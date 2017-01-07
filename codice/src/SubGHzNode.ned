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
import inet.wpan.phyLayer.ieee802154.Ieee802154Phy;
import inet.wpan.networklayer.Ieee802154StarRouting.Ieee802154StarRouting;

//import inet.underTest.wpan.battery.Ieee802154Battery;
import inet.battery.models.InetSimpleBattery;
import inet.wpan.applications.Ieee802154TestApp.Ieee802154TestApp;
import inet.mobility.contract.IMobility;
import inet.base.NotificationBoard;
import inet.wpan.Isabel.Base.Display;

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

module SubGHzNode
{
  parameters:
        @node();
        string mobilityType;
        volatile double numHosts;
    gates:
        input radioIn;
    submodules:
        notificationBoard: NotificationBoard {
            parameters:
                @display("p=65,70;i=block/control");

        }
        mobility: <mobilityType> like IMobility {
            parameters:
                @display("p=65,150;i=block/cogwheel");

        }
        disp: Display {
            parameters:
                @display("p=65,230;i=block/app2");

        }
        // battery module
        battery: InetSimpleBattery{
            parameters:
                @display("p=65,310;i=block/plug");

        }
        // application-layer
        app: PeriodicAppLayer {
            parameters:
                @display("p=250,100;i=block/source");

        }
        // interfaccia SPI
        spi: SPIInterface {
            parameters:
                @display("p=250,200;i=block/network2");

        }
        // livello fisico
        phy: Ieee802154Phy {
            parameters:
                @display("p=250,300;q=queue;i=block/ifcard");

        }
    connections allowunconnected:
        radioIn --> phy.radioIn;
        phy.upperLayerOut --> spi.lowerLayerIn;
        phy.upperLayerIn <-- spi.lowerLayerOut;
        spi.upperLayerOut --> app.lowerLayerIn;
        spi.upperLayerIn <-- app.lowerLayerOut;
}



