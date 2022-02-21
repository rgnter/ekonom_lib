//
// Created by maros on 23/12/2021.
//

#include "terminal/terminal.hpp"

// packet struct

ekonom::terminal::network::packet::packet(size_t packetLength, uint8_t *packetData)
        : packetLength(packetLength) {
    this->packetData = (uint8_t*) malloc(this->packetLength);
    memcpy_s(this->packetData, this->packetLength, packetData, packetLength);
}

ekonom::terminal::network::packet::~packet() {
    free(this->packetData);
}

// --

// Protocol class

ekonom::terminal::network::Protocol::Protocol(const std::unique_ptr<network::Connection> &mConnection) {
    this->m_connection.reset(mConnection.get());
}


// Client class
ekonom::terminal::Client::Client(const std::string &address,
                                 const std::string &port,
                                 std::unique_ptr<network::Connection> connection) {

}


bool ekonom::terminal::Client::initialize() {
    return true;
}

bool ekonom::terminal::Client::terminate() {
    return true;
}


// --