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
//package inet.examples.wpan.StarNet;
import inet.world.radio.ChannelControl;





//import inet.wpan.nodes.Ieee802154Node;


//network Ieee802154StarNet
//{
network Network
{
    parameters:
        double numHosts;
        @display("bgb=322,295");
    submodules:
        host[numHosts]: SubGHzNode {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=84,57");
        }
        channelControl: ChannelControl {
            parameters:
                @display("p=-65,20;i=misc/sun");
        }
    connections allowunconnected:
}



