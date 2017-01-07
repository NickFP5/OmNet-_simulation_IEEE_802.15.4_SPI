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

//
// TODO auto-generated module
//

simple PeriodicAppLayer {
    parameters:
    	@display("i=block/source");

    	int payloadSize = default(80); //dimensione in bit delle dataframe prodotte
    	
    	bool sink = default(false); //booleano che indica se il nodo e' il sink
    	
    	bool gestioneConInterrupt = default(false); //il receiver chiede dati (getReceivedData) periodicamente o previa ricezione della interrupt RxReady
    	double GetReceivedTimePeriod @unit(s) = default(1s); //nel caso di getReceivedData periodica, periodo del timer relativo
    	
    	
    	@statistic[Throughput](record=vector, last);
    	@statistic[Workload](record=vector, last);
    	@statistic[WorkloadPeriod](record=vector, last);
    	//@statistic[DataframeArrivalPeriod](record=vector, last);
    
    gates:
        input lowerLayerIn;
        output lowerLayerOut; 
}

