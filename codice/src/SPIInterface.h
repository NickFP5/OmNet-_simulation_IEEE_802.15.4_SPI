#ifndef __LLDN_TII_LLDNBASEMAC_H_
#define __LLDN_TII_LLDNBASEMAC_H_

#include <omnetpp.h>
#include "Ieee802154Enum.h"

class SPIInterface: public cSimpleModule {
protected:

    typedef enum { //possibili stati dell'interfaccia SPI
        IDLE, TX_MODE, RX_MODE, RX, TX
    } spi_state;

    cGate *lowerLayerIn;
    cGate *lowerLayerOut;
    cGate *upperLayerIn;
    cGate *upperLayerOut;

    /*bool macPrioQueue;
    int macMaxQueueLength; //0 disabled
    int macMaxExpectedPayloadLength;
    int macNumMsgTS;
    double timeslotDuration;*/

    //State variables
    bool rxMode;
    int currentChannel;

    //Objects
    /*cPacketQueue *TxQueue;
    cPacketQueue RtxQueue;*/

    //*************************

    cPacket *txBuffer; //buffer di trasmissione
    cPacket *rxBuffer; //buffer di ricezione
    cPacket *primBuffer;  //contiene la primitiva precedentemente ricevuta per statistica
    spi_state state; //stato della SPI

    simtime_t Ttxm; //costante di tempo della primitiva setTxMode
    simtime_t Tstx; //costante di tempo della primitiva startTx
    simtime_t Tsrx; //costante di tempo della primitiva setRxMode
    simtime_t Trxm; //costante di tempo della primitiva getReceivedData
    simtime_t Trxnf; //costante di tempo della primtiva RxNoFrame

    long bitrate; //bitrate (adoperato per la simulazione dei tempi delle primitive setTxMode e getReceivedData)

    cMessage *timerTtx; //timer della primitiva setTxMode
    cMessage *timerTrx; //timer della primitiva getReceivedData
    cMessage *timerTstx; //timer della primitiva startTx
    cMessage *timerTsrx; //timer della primitiva setRxMode
    cMessage *timerTrxnf; //timer della primitiva RxNoFrame


    bool chngmodecomplete; //variabile che descrive se il posizionamento in modalità TX o RX e' stato completato

    int indice; //variabile che indica l'indice del nodo SubGHzNode, a cui appartiene la SPI, all'interno della rete

    int OverWrittenDataframesCount;
    int getReceivedDataCount;
    int ArrivedDataframesCount;
    //*************************


    //statistics
    /*int TxQueueDrops;*/

    virtual void initialize();
    //virtual ~SPIInterface();
    //virtual void finish();
    virtual void handleMessage(cMessage *msg);
    //virtual void handleSelfMessage(cMessage *msg);

    /*   Utility
     virtual cMessage * startTimer(const char *name, double relTime);
     virtual void TxQueuePush(cPacket *pkt);
     virtual cPacket * TxQueuePop();
     virtual void RtxQueuePush(cPacket *pkt);
     virtual cPacket * RtxQueuePop();
     virtual void clearTxQueue();
     virtual void clearRtxQueue();
     static int ComparePacket(cObject *lhs, cObject *rhs);
     virtual double getTimeslotDuration();*/

    /* Phy Interfaces */
    // virtual void sendCCARequest();
    virtual void setTxMode(int channel, cPacket *frame);
    virtual void setRxMode(int channel);
    virtual void RxNoFrame();
    virtual void RxReady();
    virtual void confirmSetTxMode();
    virtual void confirmSetRxMode();
    virtual void startTx();
    virtual void TxDone();
    virtual void getReceivedData();
    //virtual void setChannel(int channel, bool rx);
    virtual void handlePhyPrimitive(cMessage *msg);
    // virtual void handlePhyCCAConfirm(PHYenum res);
    //virtual void handleTxConfirm(PHYenum res);
    virtual void PLME_SET_TRX_STATE_request(PHYenum status);
};

#endif
