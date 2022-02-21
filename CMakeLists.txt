cmake_minimum_required(VERSION 3.21)
project(ekonom_lib)

set(CMAKE_CXX_STANDARD 14)

set(PRIVATE_SOURCES
        source/pch.cpp
        source/pch.hpp
        source/main.cpp
        source/private/ekonom.cpp)
set(PUBLIC_SOURCES
        source/public/ekonom.hpp
        source/private/terminal/terminal.cpp
        source/public/terminal/terminal.hpp
        source/private/terminal/protocols/ecr2_protocol.cpp
        source/public/terminal/protocols/ecr2_protocol.hpp
        source/private/terminal/connections/tcpip_connection.cpp
        source/public/terminal/connections/tcpip_connection.hpp
        source/private/terminal/connections/serial_connection.cpp
        source/public/terminal/connections/serial_connection.hpp)
include_directories(source/public)


find_package(Boost 1.62.0)
include_directories(${Boost_INCLUDE_DIR})

add_executable(ekonom_lib ${PRIVATE_SOURCES} ${PUBLIC_SOURCES})
