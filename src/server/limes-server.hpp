#ifndef LIMES_SERVER_HPP
#define LIMES_SERVER_HPP

#include <server.hpp>

class LimesServer : public sphys::Server {
  public:
    LimesServer(sphy::CmdLinOptionsServer& options);
    ~LimesServer();
};

#endif