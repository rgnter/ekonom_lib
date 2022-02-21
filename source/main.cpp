#include <cstdint>
#include <cstdio>

#include <ekonom.hpp>

int main() {

    ekonom::terminal::Client client("192.168.0.100",
                                    "53535",
                                    ekonom::terminal::use_tcpip
    );


    return 0;
}
