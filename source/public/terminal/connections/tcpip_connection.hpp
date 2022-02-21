//
// Created by maros on 23/12/2021.
//

#ifndef EKONOM_LIB_TCPIP_CONNECTION_HPP
#define EKONOM_LIB_TCPIP_CONNECTION_HPP


#include <terminal/terminal.hpp>

namespace ekonom {
    namespace terminal {
        namespace network {

            class TcpIpConnection
                    : Connection {
                bool establish(const std::string &address,
                               const std::string &port) override;

                bool write_packet(const packet &data) override;
                bool read_packet(packet &data) override;
            };

        }

        using tcpip = network::TcpIpConnection;
        auto use_tcpip = []() {
            return std::make_unique<tcpip>();
        };
    }
}

#endif //EKONOM_LIB_TCPIP_CONNECTION_HPP
