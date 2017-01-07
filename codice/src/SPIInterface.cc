#include "SPIInterface.h"
#include "Ieee802154MacPhyPrimitives_m.h"
#include "SpiPrimitive_m.h"
#include "Dataframe_m.h"

Define_Module(SPIInterface);

void SPIInterface::initialize() {

    lowerLayerIn = gate("lowerLayerIn");
    lowerLayerOut = gate("lowerLayerOut");
    upperLayerIn = gate("upperLayerIn");
    upperLayerOut = gate("upperLayerOut");

    //assegnazione delle costanti di tempo
    Ttxm = par("Ttxm").doubleValue();
    Tstx = par("Tstx").doubleValue();
    Tsrx = par("Tsrx").doubleValue();
    Trxm = par("Trxm").doubleValue();
    Trxnf = par("Trxnf").doubleValue();

    //dichiarazione dei timer
    timerTtx = new cMessage("timerTtx");
    timerTrx = new cMessage("timerTrx");
    timerTstx = new cMessage("timerTstx");
    timerTsrx = new cMessage("timerTsrx");
    timerTrxnf = new cMessage("timerTrxnf");

    chngmodecomplete = false;

    bitrate = par("bitrate").doubleValue();

    state = IDLE; //stato iniziale = IDLE

    indice = par("indice").longValue();

    txBuffer = NULL;
    rxBuffer = NULL;

    OverWrittenDataframesCount = 0;
    ArrivedDataframesCount = 0;
    getReceivedDataCount = 0;

    WATCH(currentChannel);
}

void SPIInterface::handleMessage(cMessage *msg) {

    EV << "Node " << indice << " is handling a new cMessage" << endl;

    if (dynamic_cast<dataframe *>(msg) != NULL) {

        dataframe *df = dynamic_cast<dataframe *>(msg);

        EV << "Node " << indice << " (SPIInterface) NEW DATAFRAME" << endl;

        //codice di emissione del segnale per il dataframe Arrival Period
        simsignal_t sig2 = registerSignal("DataframeArrivalPeriod");
        emit(sig2, (double) (simTime().dbl() - df->getGenTime()));

        ArrivedDataframesCount++;
        sig2 = registerSignal("ArrivedDataframesCount");
        emit(sig2, ArrivedDataframesCount);

    }



    if (msg->getArrivalGate() == lowerLayerIn&&
    dynamic_cast<Ieee802154MacPhyPrimitives *>(msg) != NULL) { //gestione delle primitive provenienti dal livello fisico
        handlePhyPrimitive(msg); //completamento trasmissione
        //delete msg;

        return;

    } else {

        switch (state) {

        case IDLE:
            EV << "Node " << indice << " is IDLE" << endl;
            if (msg->getArrivalGate() == upperLayerIn) {
                if (dynamic_cast<setTxModePrimitive *>(msg) != NULL) { //caso ricezione primitiva setTxMode


                    state = TX_MODE; //prossimo stato = TX_MODE

                    //decapsulamento della dataframe dalla primitiva setTxMode
                    setTxModePrimitive *prim =
                            dynamic_cast<setTxModePrimitive *>(msg);
                    dataframe *pkt =
                            dynamic_cast<dataframe *>(prim->decapsulate());

                    txBuffer = pkt; //bufferizzazione della dataframe

                    //avvio del timer che simula il cambio di stato
                    scheduleAt(
                            (double) (pkt->getBitLength() / (double) bitrate)
                                    + Ttxm + simTime(), timerTtx);

                    chngmodecomplete = false; //cambio di stato in TX MODE non ancora completato

                    //bufferizzazione della primitiva per uso futuro per collecting delle statistiche
                    primBuffer = new cPacket();
                    primBuffer->encapsulate(
                            dynamic_cast<setTxModePrimitive *>(msg));

                    EV << "Node " << indice
                              << " (SPIInterface) received setTxMode Primitive (contained dataframe has ByteLenght "
                              << pkt->getBitLength() / 8 << ")" << endl;

                    return;

                }

                if (dynamic_cast<setRxModePrimitive *>(msg) != NULL) { //caso ricezione primitiva setRxMode

                    //prossimo stato = RX_MODE
                    state = RX_MODE;

                    //casting della primitiva setRxMode
                    setRxModePrimitive *prim =
                            dynamic_cast<setRxModePrimitive *>(msg);


                    //avvio del timer che simula il cambio di stato
                    scheduleAt(Tsrx + simTime(), timerTsrx);
                    chngmodecomplete = false; //cambio di stato in RX_MODE non completato

                    //bufferizzazione della primitiva per uso futuro per collecting delle statistiche
                    primBuffer = new cPacket();
                    primBuffer->encapsulate(prim);

                    EV << "Node " << indice
                              << " (SPIInterface) received setRxMode Primitive"
                              << endl;

                    return;
                }
            }

            break;

        case TX_MODE:
            EV << "Node " << indice << " is in TX_MODE" << endl;
            if (msg->isSelfMessage()
                    && strcmp(msg->getName(), "timerTtx") == 0) { //completato passaggio a modalita' trasmissione

                setTxModePrimitive *prim =
                                        dynamic_cast<setTxModePrimitive *>(primBuffer->decapsulate());

                //impostazione del canale in trasmissione e invio al livello fisico della dataframe
                setTxMode(prim->getChannel(), txBuffer);

                //notifica al livello app dell'avvenuto cambio di stato
                confirmSetTxMode();
                chngmodecomplete = true; //cambio di stato completato

                EV << "Node " << indice
                          << " (SPIInterface) changed state to TX_MODE" << endl;

                //codice emissione segnale
                simsignal_t sig = registerSignal("setTxMode_time");
                emit(sig, simTime().dbl() - prim->getGenTime());

                delete prim;
                delete primBuffer;
                primBuffer = NULL;

                return;
            }

            if (dynamic_cast<startTxPrimitive *>(msg) != NULL
                    && chngmodecomplete == true) { //richiesta di startTx

                state = TX; //prossimo stato = TX

                //avvio del timer che simula la trasmissione
                scheduleAt(simTime() + Tstx, timerTstx);

                //bufferizzazione della primitiva per uso futuro per collecting delle statistiche
                primBuffer = new cPacket();
                primBuffer->encapsulate(dynamic_cast<startTxPrimitive *>(msg));

                EV << "Node " << indice
                          << " (SPIInterface) received startTx Primitive"
                          << endl;

                return;
            }

            if (dynamic_cast<setRxModePrimitive *>(msg) != NULL
                    && chngmodecomplete == true) { //richiesta di setRxMode

                //prossimo stato = RX_MODE
                state = RX_MODE;

                //avvio del timer che simula il cambio di stato
                scheduleAt(simTime() + Tsrx, timerTsrx);
                chngmodecomplete = false;

                //bufferizzazione della primitiva per uso futuro per collecting delle statistiche
                primBuffer = new cPacket();
                primBuffer->encapsulate(
                        dynamic_cast<setRxModePrimitive *>(msg));

                EV << "Node " << indice
                          << " (SPIInterface) received setRxMode Primitive"
                          << endl;

                return;
            }

            break;

        case RX_MODE:
            EV << "Node " << indice << " is in RX_MODE" << endl;

            if (dynamic_cast<dataframe *>(msg) != NULL
                    && msg->getArrivalGate() == lowerLayerIn)
                EV << "Node " << indice
                          << " (SPIInterface) received a not corrupted dataframe"
                          << endl;

            if (msg->isSelfMessage()
                    && strcmp(msg->getName(), "timerTsrx") == 0) { //gestione del timer avvenuto passaggio allo stato RX_MODE

                setRxModePrimitive *prim =
                                        dynamic_cast<setRxModePrimitive *>(primBuffer->decapsulate());

                //set del livello fisico in modalità ricezione sul canale indicato dal livello app
                setRxMode(prim->getChannel());

                    //notifica verso il livello app dell'avvenuto cambio di stato
                confirmSetRxMode();
                chngmodecomplete = true;

                EV << "Node " << indice
                          << " (SPIInterface) changed state to RX_MODE" << endl;

                //codice emissione segnale
                simsignal_t sig = registerSignal("setRxMode_time");
                emit(sig, simTime().dbl() - prim->getGenTime());
                delete prim;
                delete primBuffer;
                primBuffer = NULL;

                return;
            }

            if (dynamic_cast<dataframe *>(msg) != NULL
                    && msg->getArrivalGate() == lowerLayerIn
                    && chngmodecomplete == true) { //gestione dell'arrivo di una dataframe dal livello fisico quando l'interfaccia ha già completato il passaggio allo stato RX MODE

                if (rxBuffer != NULL) {

                    EV << "Node " << indice
                              << " (SPIInterface) rxBuffer overwritten" << endl;

                    OverWrittenDataframesCount++;
                    simsignal_t sig = registerSignal(
                            "OverWrittenDataframesCount");
                    emit(sig, OverWrittenDataframesCount);

                    delete rxBuffer;
                }

                rxBuffer = dynamic_cast<dataframe *>(msg); //bufferizzazione della dataframe

                if (rxBuffer->hasBitError()) { //frame non valida
                    delete rxBuffer;
                    rxBuffer = NULL;
                    return;
                } else { //frame valida

                    RxReady(); //notifica al livello applicazione della disponibilita' di una dataframe
                    state = RX; //prossimo stato = RX

                    bubble("SPI RECEIVED A FRAME");
                    EV << "Node " << indice
                              << " (SPIInterface) received a not corrupted frame"
                              << endl;

                    return;
                }
            }

            if (dynamic_cast<setTxModePrimitive *>(msg) != NULL
                    && chngmodecomplete == true) { //richiesta di setTxMode

                state = TX_MODE; //prossimo stato = TX_MODE

                //decapsulamento della dataframe all'interno della primitiva ricevuta
                setTxModePrimitive *prim =
                        dynamic_cast<setTxModePrimitive *>(msg);
                txBuffer = prim->decapsulate(); //app dataframe

                //avvio del timer che simula la trasmissione
                scheduleAt(
                        (double) (txBuffer->getBitLength() / (double) bitrate) + Ttxm
                                + simTime(), timerTtx);
                chngmodecomplete = false;

                //bufferizzazione della primitiva per uso futuro per collecting delle statistiche
                primBuffer = new cPacket();
                primBuffer->encapsulate(
                        dynamic_cast<setTxModePrimitive *>(msg));

                EV << "Node " << indice
                          << " (SPIInterface) received setTxMode Primitive"
                          << endl;

                return;
            }

            if (dynamic_cast<getReceivedDataPrimitive *>(msg) != NULL
                    && chngmodecomplete == true) { //richiesta di frame dati dall'alto

                //avvio del timer che simula i tempi di trasmissione della primitiva RxNoFrame
                scheduleAt(simTime() + Trxnf, timerTrxnf);

                //bufferizzazione della primitiva per uso futuro per collecting delle statistiche
                primBuffer = new cPacket();
                primBuffer->encapsulate(
                        dynamic_cast<getReceivedDataPrimitive *>(msg));

                EV << "Node " << indice
                          << " (SPIInterface) received getReceivedData Primitive"
                          << endl;

                return;
            }

            if (msg->isSelfMessage()
                    && strcmp(msg->getName(), "timerTrxnf") == 0) { //gestione del timeout del timer relativo alla RxNoFrame

                RxNoFrame(); //notifica al livello applicativo che non vi sono dataframe disponibili nel buffer di ricezione

                //codice emissione segnale
                simsignal_t sig = registerSignal("RxNoFrame_time");
                getReceivedDataPrimitive *prim =
                        dynamic_cast<getReceivedDataPrimitive *>(primBuffer->decapsulate());
                emit(sig, simTime().dbl() - prim->getGenTime());
                delete prim;
                delete primBuffer;
                primBuffer = NULL;

                EV << "Node " << indice
                          << " (SPIInterface) sent RxNoFrame Primitive" << endl;
                return;
            }

            break;

        case RX:
            EV << "Node " << indice << " is in RX STATE" << endl;
            if (dynamic_cast<getReceivedDataPrimitive *>(msg) != NULL) { //ricezione di una getReceivedData

                //avvio del timer che simula i tempi di trasmissione della frame verso il livello applicazione
                scheduleAt(
                        simTime()
                                + (double) (rxBuffer->getBitLength()
                                        / (double) bitrate) + Trxm, timerTrx);

                //bufferizzazione della primitiva per uso futuro per collecting delle statistiche
                primBuffer = new cPacket();
                primBuffer->encapsulate(
                        dynamic_cast<getReceivedDataPrimitive *>(msg));

                EV << "Node " << indice
                          << " (SPIInterface) received getReceivedData Primitive"
                          << endl;

                return;
            }

            if (msg->isSelfMessage()
                    && strcmp(msg->getName(), "timerTrx") == 0) { //gestione del timeout del timer relativo alla getReceivedData

                getReceivedData(); //invio della dataframe presente nel buffer di ricezione verso il livello applicazione

                state = IDLE; //prossimo stato = IDLE

                EV << "Node " << indice
                          << " (SPIInterface) frame reception completed"
                          << endl;

                //codice emissione segnale
                simsignal_t sig = registerSignal("getReceivedData_time");
                getReceivedDataPrimitive *prim =
                        dynamic_cast<getReceivedDataPrimitive *>(primBuffer->decapsulate());
                emit(sig, simTime().dbl() - prim->getGenTime());
                delete prim;
                delete primBuffer;
                primBuffer = NULL;

                return;
            }

            break;

        case TX:
            EV << "Node " << indice << " is in TX STATE" << endl;
            if (msg->isSelfMessage()
                    && strcmp(msg->getName(), "timerTstx") == 0) { //gestione del timeout del timer che simula l'avvio della trasmissione

                startTx(); //avvio della trasmissione della frame presente nel buffer di trasmissione verso il livello fisico


                EV << "Node " << indice
                          << " (SPIInterface) frame transmitted to PHY layer"
                          << endl;

                //codice emissione segnale
                simsignal_t sig = registerSignal("startTx_time");
                startTxPrimitive *prim =
                        dynamic_cast<startTxPrimitive *>(primBuffer->decapsulate());
                emit(sig, simTime().dbl() - prim->getGenTime());
                delete prim;
                delete primBuffer;
                primBuffer = NULL;

                return;
            }
            break;

        }

    }

}

void SPIInterface::handlePhyPrimitive(cMessage *msg) { //gestione delle primitive ricevute dal livello fisico
    Ieee802154MacPhyPrimitives* primitive = check_and_cast<
            Ieee802154MacPhyPrimitives *>(msg);

    switch (primitive->getKind()) {
    case PLME_SET_CONFIRM: {
        EV << "Node " << indice << " HANDLEPHYPRIMTIVE, kind PLME_SET_CONFIRM"
                  << endl;
        if (primitive->getStatus() == phy_SUCCESS) {
            PLME_SET_TRX_STATE_request(phy_FORCE_TRX_OFF);
        }
        delete primitive;
    }
        return;
    case PLME_SET_TRX_STATE_CONFIRM: {
        EV << "Node " << indice
                  << " HANDLEPHYPRIMTIVE, kind PLME_SET_TRX_STATE_CONFIRM"
                  << endl;
        switch (primitive->getStatus()) {
        case phy_SUCCESS:
        case phy_RX_ON:
        case phy_TX_ON:
            delete primitive;
            return;
        case phy_TRX_OFF:
            if (!rxMode) {
                PLME_SET_TRX_STATE_request(phy_TX_ON);
            } else {
                PLME_SET_TRX_STATE_request(phy_RX_ON);
            }
            delete primitive;
            return;
        default:
            error("TRX state: %d not supported", primitive->getStatus());
        }
    }
        return;
    case PD_DATA_CONFIRM: { //Ã¨ completa una trasmissione (notifica dal phy)
        //handleTxConfirm((PHYenum)primitive->getStatus());
        EV << "Node " << indice << " HANDLEPHYPRIMTIVE, kind PD_DATA_CONFIRM"
                  << endl;
        TxDone();
        state = IDLE; //prossimo stato = IDLE

        EV << "Node " << indice << " (SPIInterface) sent TxDone Primitive"
                  << endl;
        delete primitive;
//            setRxMode();
    }
        return;
        /* case PLME_CCA_CONFIRM: {
         handlePhyCCAConfirm((PHYenum)primitive->getStatus());
         delete primitive;
         } return;*/
    default:
        error("Primitive not managed");
    }
}

void SPIInterface::PLME_SET_TRX_STATE_request(PHYenum status) {
    Ieee802154MacPhyPrimitives *primitive = new Ieee802154MacPhyPrimitives();
    primitive->setKind(PLME_SET_TRX_STATE_REQUEST);
    primitive->setStatus(status);
    send(primitive, lowerLayerOut);
    return;
}

/***********************************************
 * *****************************************
 * **********************************
 * ***************************
 */

void SPIInterface::setTxMode(int channel, cPacket *frame) {
    rxMode = false;
    PLME_SET_TRX_STATE_request(phy_FORCE_TRX_OFF);

    currentChannel = channel;
    Ieee802154MacPhyPrimitives *primitive = new Ieee802154MacPhyPrimitives();
    primitive->setKind(PLME_SET_REQUEST);
    primitive->setAttribute(PHY_CURRENT_CHANNEL);
    primitive->setChannelNumber(currentChannel);
    send(primitive, lowerLayerOut); //invio della primitiva
    return;
}

void SPIInterface::confirmSetTxMode() { //creazione ed invio di una primitiva di conferma di avvenuto cambio di modalita' in TX MODE
    confirmSetTxModePrimitive *prim = new confirmSetTxModePrimitive();
    send(prim, upperLayerOut);
}

void SPIInterface::confirmSetRxMode() { //creazione ed invio di una primitiva di conferma di avvenuto cambio di modalita' in RX MODE
    confirmSetRxModePrimitive *prim = new confirmSetRxModePrimitive();
    send(prim, upperLayerOut);
}

void SPIInterface::startTx() { //invio della frame presente nel buffer di trasmissione verso il livello fisico

    if (txBuffer != NULL) {
        send(txBuffer, lowerLayerOut);
        txBuffer = NULL;
    }

}

void SPIInterface::TxDone() { //invio della primitiva TxDone verso il livello applicazione
    TxDonePrimitive *prim = new TxDonePrimitive();
    send(prim, upperLayerOut);
}

void SPIInterface::RxReady() { //invio della primitiva TxDone verso il livello applicazione
    RxReadyPrimitive *prim = new RxReadyPrimitive();
    send(prim, upperLayerOut);
}

void SPIInterface::setRxMode(int channel) { //invio della primitiva che setta il canale in ricezione verso il livello fisico

    if(rxMode == false || channel != currentChannel){
        PLME_SET_TRX_STATE_request(phy_FORCE_TRX_OFF);
        if (channel < 11 || channel > 26)
            error("Invalid channel arguments");
        rxMode = true;
        currentChannel = channel;
        Ieee802154MacPhyPrimitives *primitive = new Ieee802154MacPhyPrimitives();
        primitive->setKind(PLME_SET_REQUEST);
        primitive->setAttribute(PHY_CURRENT_CHANNEL);
        primitive->setChannelNumber(currentChannel);
        send(primitive, lowerLayerOut);
    }
    return;
}

void SPIInterface::getReceivedData() { //invio della frame presente nel buffer di ricezione verso il livello fisico
    if (rxBuffer != NULL) {
        send(rxBuffer, upperLayerOut);
        rxBuffer = NULL;
    }
}

void SPIInterface::RxNoFrame() { //creazione ed invio di una primitiva di notifica dell'assenza di frame nel buffer di ricezione
    RxNoFramePrimitive *prim = new RxNoFramePrimitive();
    send(prim, upperLayerOut);
}

