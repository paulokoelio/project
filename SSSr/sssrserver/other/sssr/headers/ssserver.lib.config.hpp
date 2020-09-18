#ifndef SSSERVER_LIB_CONFIG_HPP_
#define SSSERVER_LIB_CONFIG_HPP_

namespace sssr
{

/**
Class-enum that contain number of string for coresponding default constant
value in configuration file "ssserver.lib.config.txt".
Numbers of lines starting from 1.
This class must be coordinated with content of this file.
*/
namespace server_config
{
const int PORTS_START = 2;
const int PORTS_END = 4;
}

} // namespace sssr

#endif /* SSSERVER_LIB_CONFIG_HPP_ */
