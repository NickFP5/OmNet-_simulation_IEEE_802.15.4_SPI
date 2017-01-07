


//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//


package spi_bbpv;

simple SPIInterface {
    parameters:
    	
    	//bool macPrioQueue = default(false);
    	//int macMaxQueueLength = default(0); //0 disabled
    	//int macMaxExpectedPayloadLength;
    	//int macNumMsgTS = default(1);
    	
    	double Ttxm @unit(s) = default(350us); //costante di tempo per la primitiva setTxMode
    	double Tstx @unit(s) = default(50us); //costante di tempo per la primitiva startTx
    	double Tsrx @unit(s) = default(50us); //costante di tempo per la primitiva setRxMode
    	double Trxm @unit(s) = default(350us); //costante di tempo per la primitiva getReceoivedData
    	
    	double Trxnf @unit(s) = default(50us); //per il timer della primitiva RxNoFrame
    	
    	double bitrate @unit(bps) = default(1Mbps);
    	
    	@statistic[setTxMode_time](record=vector); //collecting delle statistiche dei tempi della setTxMode
     	@statistic[setRxMode_time](record=vector); //collecting delle statistiche dei tempi della setRxMode
     	@statistic[getReceivedData_time](record=vector); //collecting delle statistiche dei tempi della getReceivedData
     	@statistic[startTx_time](record=vector); //collecting delle statistiche dei tempi della startTx
     	@statistic[RxNoFrame_time](record=vector); //collecting delle statistiche dei tempi della RxNoFrame
     	
     	@statistic[DataframeArrivalPeriod](record=vector, last);
     	@statistic[OverWrittenDataframesCount](record=vector, last);
     	@statistic[ArrivedDataframesCount](record=vector, last);
     	@statistic[getReceivedDataCount](record=vector, last);
     			
     	
     	int indice = default(0); //descrive il nodo all'interno della rete
    	
   	gates:
   	    input 	lowerLayerIn;
	    output 	lowerLayerOut;
	    input 	upperLayerIn;
	    output 	upperLayerOut;
}
