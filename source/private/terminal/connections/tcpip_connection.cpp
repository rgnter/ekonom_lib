//
// Created by maros on 23/12/2021.
//

#include "terminal/connections/tcpip_connection.hpp"
#include <cstdio>

bool ekonom::terminal::network::TcpIpConnection::establish(
        const std::string &address,
        const std::string &port) {

    printf("Establishing connection to %s:%s\n", address.c_str(), port.c_str());
    return true;
}

bool ekonom::terminal::network::TcpIpConnection::write_packet(
        const ekonom::terminal::network::packet &data) {
    printf("Writing packet: %s\n", data.packetData);
    return true;
}

bool ekonom::terminal::network::TcpIpConnection::read_packet(
        ekonom::terminal::network::packet &data) {
    data.packetData = (uint8_t*) "packet";
    data.packetLength = 6;

    printf("Receiving packet: %s\n", data.packetData);
    return true;
}
