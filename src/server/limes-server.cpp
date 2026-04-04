#include <limes-server.hpp>
#include <sys-phy.hpp>

LimesServer::LimesServer(sphy::CmdLinOptionsServer &options)
    : Server(options) {}

LimesServer::~LimesServer() {}

void LimesServer::registerSystems(ecs::Ecs& ecs) {
  ecs.registerSystem(ecs::sysPhyThrust);
  ecs.registerSystem(ecs::sysPhysics);
}
