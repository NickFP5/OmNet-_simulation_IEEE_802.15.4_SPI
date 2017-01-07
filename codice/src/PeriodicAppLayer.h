

#include <omnetpp.h>

class PeriodicAppLayer : public cSimpleModule {
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);


    cGate *lowerLayerIn;
    cGate *lowerLayerOut;

    int payloadSize; //dimensione in bit delle dataframe

    double dataframeGenTime;

    bool gestioneConInterrupt; //il receiver chiede dati (getReceivedData) periodicamente o previa ricezione della interrupt RxReady
    simtime_t GetReceivedTimePeriod; //nel caso di getReceivedData periodica, periodo del timer relativo
    cMessage *getReceivedDataTimer; //periodo di richiesta dati all'interfaccia SPI tramite getReceivedData

    bool sink; //booleano che indica se il nodo e' il sink

    int indice; //indice del nodo all'interno della rete

    int seqn; //numero di sequenza dell'ultimo pacchetto inviato

    long totbit; //somma dei bit delle dataframe generate (per collecting delle statistiche)
};
