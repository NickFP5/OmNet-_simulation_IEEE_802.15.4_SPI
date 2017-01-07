#include "PeriodicAppLayer.h"
#include "SpiPrimitive_m.h"
#include "Dataframe_m.h"

Define_Module(PeriodicAppLayer);

void PeriodicAppLayer::initialize() {
    lowerLayerIn = gate("lowerLayerIn");
    lowerLayerOut = gate("lowerLayerOut");

    payloadSize = par("payloadSize");

    sink = par("sink").boolValue();

    totbit = 0;

    gestioneConInterrupt = par("gestioneConInterrupt").boolValue(); //il receiver chiede dati (getReceivedData) periodicamente o previa ricezione della interrupt RxReady
    GetReceivedTimePeriod = par("GetReceivedTimePeriod").doubleValue();
    getReceivedDataTimer = new cMessage("getReceivedDataTimer");

    seqn = 0;
    indice = 1;
    if (sink) //il sink ha indice 0
        indice = 0;

    if (!sink) {

        //creazione di una dataframe, incapsulamento in una primitiva setTxMode e trasmissione
        setTxModePrimitive *prim = new setTxModePrimitive(); //creazione primitiva
        dataframe *df = new dataframe(); //creazione dataframe
        df->setBitLength(payloadSize); //set della lunghezza in bit
        df->setSeqn(seqn); //set del numero di sequenza
        df->setGenTime(simTime().dbl());
        seqn++;
        prim->encapsulate(df); //incapsulamento nella primitiva
        prim->setChannel(11); //set del canale di trasmissione
        prim->setGenTime(simTime().dbl()); //set dell'istante di generazione della primitiva

        dataframeGenTime = simTime().dbl(); //set dell'istante di generazione della dataframe

        EV << "Node " << indice
                  << " (APPLAYER) sent setTxMode Primitive containing dataframe (payload size is "
                  << df->getByteLength() << " bytes)" << endl;

        send(prim, lowerLayerOut); //invio della primitiva

    } else {

        setRxModePrimitive *prim = new setRxModePrimitive(); //creazione della primitiva
        prim->setChannel(11); //set del canale di ricezione
        prim->setGenTime(simTime().dbl()); //set dell'istante di generazione della primitiva
        send(prim, lowerLayerOut); //invio della primitiva

        EV << "Node " << indice
                  << " (APPLAYER)  sent setRxMode Primitive (contained frame has #seq "
                  << seqn << ")" << endl;

        if (!gestioneConInterrupt) {
            scheduleAt(simTime() + GetReceivedTimePeriod, getReceivedDataTimer); //avvio del prossimo timer
            EV << "Node " << indice << " (APPLAYER)  init  getReceivedDataTimer"
                      << endl;
        }

    }
}

void PeriodicAppLayer::handleMessage(cMessage *msg) {

    if (!sink) { //codice del trasmettiore (possibili stati: IDLE, TX_MODE, TX)

        if (dynamic_cast<confirmSetTxModePrimitive *>(msg) != NULL) { //gestione della ricezione della primitiva di conferma di avvenuto passaggio di stato a TX_MODE

            startTxPrimitive *prim = new startTxPrimitive(); //generazione della primitiva
            prim->setGenTime(simTime().dbl()); //set dell'istante di generazione
            send(prim, lowerLayerOut); //invio della primitiva
            delete msg;

            EV << "Node " << indice
                      << " (APPLAYER) received confirmSetTxMode Primitive"
                      << endl;
            EV << "Node " << indice << " (APPLAYER)  sent startTx Primitive"
                      << endl;

            return;
        }

        if (dynamic_cast<TxDonePrimitive *>(msg) != NULL) { //gestione della ricezione della primitiva di notifica di avvenuta trasmissione

            setTxModePrimitive *prim = new setTxModePrimitive(); //generazione della primitiva
            dataframe *df = new dataframe(); //generazione della dataframe
            df->setBitLength(payloadSize); //set della lunghezza in bit
            df->setSeqn(seqn); //set del numero di sequenza
            seqn++;
            df->setGenTime(simTime().dbl());
            prim->encapsulate(df); //incapsulamento della dataframe nella primitiva
            prim->setChannel(11); //set del canale di trasmissione
            prim->setGenTime(simTime().dbl()); //set dell'istante di generazione della primitiva

            //codice di emissione del segnale per il workload
            simsignal_t sig = registerSignal("Workload");
            emit(sig,
                    (double) (payloadSize)
                            / ((double) (simTime().dbl() - dataframeGenTime)));

            //codice di emissione del segnale per il workload period
            sig = registerSignal("WorkloadPeriod");
            emit(sig, ((double) (simTime().dbl() - dataframeGenTime)));

            dataframeGenTime = simTime().dbl(); //aggiornamento dell'istante di generazione dell'ultima dataframe

            send(prim, lowerLayerOut); //invio della primitiva
            delete msg;

            EV << "Node " << indice << " (APPLAYER) received TxDone Primitive"
                      << endl;
            EV << "Node " << indice
                      << " (APPLAYER) sent setTxMode Primitive (contained frame has #seq "
                      << seqn << ")" << endl;

            return;
        }

    } else { //codice sink

        if (!gestioneConInterrupt) {
            /*
             * *******************************************
             * GESTIONE CON TIMER:
             * il ricevitore richiede periodicamente la getReceivedData
             * le possibili risposte sono una dataframe o una RxNoFrame
             * (nessuna frame nel buffer di ricezione della SPI)
             * *******************************************
             */

            if (msg->isSelfMessage()
                    && strcmp(msg->getName(), "getReceivedDataTimer") == 0) {

                scheduleAt(simTime() + GetReceivedTimePeriod,
                        getReceivedDataTimer); //avvio del prossimo timer

                EV << "Node " << indice
                          << " (APPLAYER)  restarted  getReceivedDataTimer"
                          << endl;

                getReceivedDataPrimitive *prim = new getReceivedDataPrimitive(); //generazione della primitiva
                prim->setGenTime(simTime().dbl()); //set dell'istante di generazione della primitiva
                send(prim, lowerLayerOut); //invio della primitiva

                EV << "Node " << indice
                          << " (APPLAYER) sent getReceivedData Primitive"
                          << endl;

                return;
            }

            if (dynamic_cast<confirmSetRxModePrimitive *>(msg) != NULL) {

                EV << "Node " << indice
                          << " (APPLAYER) received confirmSetRxMode Primitive"
                          << endl;

                delete msg;
                return;
            }

            if (dynamic_cast<dataframe *>(msg) != NULL) {

                setRxModePrimitive *prim = new setRxModePrimitive(); //generazione della primitiva
                prim->setChannel(11); //set del canale di ricezione
                prim->setGenTime(simTime().dbl()); //set dell'istante di generazione della primitiva
                send(prim, lowerLayerOut); //invio della primitiva

                dataframe *df = dynamic_cast<dataframe *>(msg);

                EV << "Node " << indice
                          << " (APPLAYER) received a not corrupted frame with #seq "
                          << df->getSeqn() << endl;

                //codice di emissione del segnale per il throughput
                totbit = totbit + df->getBitLength(); //incremento dei bit ricevuti
                simsignal_t sig = registerSignal("Throughput");
                double thr = (double) totbit / simTime().dbl();
                emit(sig, thr); //emissione del segnale Throughput

                EV << "Node " << indice
                          << " (APPLAYER) sent setRxMode Primitive" << endl;

                delete msg;

                return;
            }

            if (dynamic_cast<RxNoFramePrimitive *>(msg) != NULL) {

                EV << "Node " << indice << " (APPLAYER) received RxNoFrame "
                          << endl;

                delete msg;
            }

        } else {

            /*
             * ***********************************************
             * ***********************************************
             * GESTIONE CON INTERRUPT:
             * attesa della RxReady per effettuare la getReceivedData
             * ***********************************************
             * ***********************************************
             */

            if (dynamic_cast<confirmSetRxModePrimitive *>(msg) != NULL) {

                EV << "Node " << indice
                          << " (APPLAYER) received confirmSetRxMode Primitive"
                          << endl;

                delete msg;
                return;
            }

            if (dynamic_cast<RxReadyPrimitive *>(msg) != NULL) { //gestione della ricezione di una primitiva di notifica di disponibilita' di una dataframe nell'interfaccia SPI

                getReceivedDataPrimitive *prim = new getReceivedDataPrimitive(); //generazione della primitiva
                prim->setGenTime(simTime().dbl()); //set dell'istante di generazione
                send(prim, lowerLayerOut); //invio della primitiva

                delete msg;

                EV << "Node " << indice
                          << " (APPLAYER) received RxReady Primitive" << endl;
                EV << "Node " << indice
                          << " (APPLAYER) sent getReceivedData Primitive"
                          << endl;

                return;
            }

            /*
             * gestione della ricezione di una nuova dataframe
             */
            if (dynamic_cast<dataframe *>(msg) != NULL) {

                setRxModePrimitive *prim = new setRxModePrimitive(); //generazione della primitiva
                prim->setChannel(11); //set del canale di ricezione
                prim->setGenTime(simTime().dbl()); //set dell'istante di generazione della primitiva
                send(prim, lowerLayerOut); //invio della primitiva

                dataframe *df = dynamic_cast<dataframe *>(msg);

                EV << "Node " << indice
                          << " (APPLAYER) received a not corrupted frame with #seq "
                          << df->getSeqn() << endl;

                totbit = totbit + df->getBitLength(); //incremento dei bit ricevuti
                simsignal_t sig = registerSignal("Throughput");
                double thr = (double) totbit / simTime().dbl();
                emit(sig, thr); //emissione del segnale Throughput
                //emit(sig, (double)(df->getBitLength())/((double)(simTime().dbl() - df->getGenTime() )));

                EV << "Node " << indice
                          << " (APPLAYER) sent setRxMode Primitive" << endl;

                if (dynamic_cast<dataframe *>(msg) != NULL)
                    bubble("APPLAYER RECEIVED A FRAME");

                delete msg;

                return;
            }

            /*
             * FINE GESTIONE DEL CASO INTERRUPT
             */

        }

    }

}

