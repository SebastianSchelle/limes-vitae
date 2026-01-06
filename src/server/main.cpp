#include <limes-server.hpp>
#include <boost/program_options.hpp>
#include <cmd-options.hpp>

namespace po = boost::program_options;

int main(int argc, char* argv[])
{
    po::variables_map vm;
    po::options_description desc("Allowed options");
    def::CmdLinOptionsServer options;
    def::CmdLinOptionsServer::createCmdLineOptions(desc);
    if (def::CmdLinOptionsServer::handleDefaultCmdLineOptions(argc, argv, desc, vm, options)) {
        return 0;
    }
    LimesServer limesServer(options);
    return 0;
}