
#include <iostream>
#include <fstream>
#include <vector>
#include "ssserver.hpp"
#include <filesystem>

namespace sssr
{

void Server::prepare(std::string new_config_file )
{
    std::cerr << "prepare() config_file is: " << new_config_file << '\n';
    m_config_file = new_config_file;
    load_config();
    int ep_number = m_ports_end - m_ports_start +1;
    m_endpoints.reserve(ep_number);
    for (int port_j=m_ports_start; port_j<= m_ports_end; ++port_j)
    {
        m_endpoints.emplace_back(tcp_t::v4(),port_j);
    }

}

using namespace std::filesystem;

void Server::load_config()
{
    
    std::filesystem::path config_file = this->m_config_file;
    std::ifstream fstream_in(config_file.native(), std::ios::in | std::ios::binary);
    std::cerr << "load_config() config_file is: " << config_file << '\n';
    std::cerr << "load_config() config_file is_exist: " << std::filesystem::exists(config_file)  << '\n';
    std::cerr << "load_config() current_dir is: " << std::filesystem::current_path()  << '\n';
    std::cerr << "load_config() fstream_in is: " << bool(fstream_in)  << '\n';
    
    if (! std::filesystem::exists(config_file) ) throw sssr::err_runtime::runtime_error("There is no config file in server directory!");
    
    std::vector<std::string> lines;
    std::string line;
    fstream_in.clear();
    fstream_in.seekg(std::ios::beg);
    while (std::getline(fstream_in, line) )
    {
        lines.push_back(line);
        std::cerr << "Load config pushed_back line: " << line << '\n';
    }
    m_ports_start = std::stoi(lines.at(server_config::PORTS_START-1).c_str());
    m_ports_end = std::stoi(lines.at(server_config::PORTS_END-1));

}

std::string Server::print()
{
    std::string res{};
    res += m_config_file + ";";
    res += std::to_string(m_ports_start) + ";";
    res += std::to_string(m_ports_end) + "\n";
    return res;
}

}
