#include <limes-client.hpp>

LimesClient::LimesClient(sphy::CmdLinOptionsClient& options) : MainWindow(options) {
    initPre();
    winLoop();
}
LimesClient::~LimesClient() {}
