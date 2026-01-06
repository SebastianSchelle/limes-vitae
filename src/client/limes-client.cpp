#include <limes-client.hpp>

LimesClient::LimesClient(def::CmdLinOptionsClient& options) : MainWindow(options) {
    initPre();
    winLoop();
}
LimesClient::~LimesClient() {}
