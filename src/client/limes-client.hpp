#ifndef LIMES_CLIENT_HPP
#define LIMES_CLIENT_HPP

#include <main-window.hpp>

class LimesClient : public ui::MainWindow {
  public:
    LimesClient(def::CmdLinOptionsClient& options);
    ~LimesClient();
};

#endif