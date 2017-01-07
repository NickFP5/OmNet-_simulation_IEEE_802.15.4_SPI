packet setTxModePrimitive { //questa primitiva incapsula la dataframe
    int channel;
    double genTime; //tempo di generazione della primitiva (per collecting delle statistiche)
}

packet confirmSetTxModePrimitive{
}

packet TxDonePrimitive {
}

packet setRxModePrimitive {
    int channel;
    double genTime; //tempo di generazione della primitiva (per collecting delle statistiche)
}

packet RxNoFramePrimitive{
    
}

packet RxReadyPrimitive{
}

packet confirmSetRxModePrimitive{
}

packet getReceivedDataPrimitive{
    double genTime; //tempo di generazione della primitiva (per collecting delle statistiche)
}

packet startTxPrimitive{
    double genTime; //tempo di generazione della primitiva (per collecting delle statistiche)
}