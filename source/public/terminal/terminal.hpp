//
// Created by maros on 23/12/2021.
//

#ifndef EKONOM_LIB_TERMINAL_HPP
#define EKONOM_LIB_TERMINAL_HPP

#include <string>
#include <memory>
#include <vector>

namespace ekonom {
    namespace terminal {
        namespace network {
            /**
             * RAII-style buffer for network packets.
             */
            struct packet {
                size_t packetLength;
                uint8_t *packetData;

                packet(size_t packetLength,
                       uint8_t *packetData);

                virtual ~packet();
            };

            /**
             * Connection.
             */
            class Connection {
            public:
                virtual bool establish(const std::string& address,
                                       const std::string& port) = 0;

                virtual bool write_packet(const packet &data) = 0;
                virtual bool read_packet(packet& data) = 0;
            };

            /**
             * Protocol.
             */
            class Protocol {
            private:
                std::unique_ptr<network::Connection> m_connection;
            public:
                explicit Protocol(const std::unique_ptr<network::Connection> &mConnection);

            public:
                virtual void begin()  = 0;
                virtual void close() = 0;

                virtual void heartbeat() = 0;

                virtual void send(const packet &data) = 0;
                virtual void receive(packet& data) = 0;
            };

        };

        /**
         * terminal Client.
         */
        class Client {
        private:
            std::unique_ptr<network::Connection> m_connection;
            std::unique_ptr<network::Protocol>   m_protocol;
        public:
            Client(std::string const& address,
                   std::string const& port,
                   std::unique_ptr<network::Connection> connection);

        public:
            bool initialize();
            bool terminate();

        };

        /**
         * terminal Server.
         */
        class Server {

        };
    };
}


#endif //EKONOM_LIB_TERMINAL_HPP
