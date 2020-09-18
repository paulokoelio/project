/**
\file
\brief Application example for SSSr library

Основной файл-сценарий приложения ServerApp. 
*/
#include "serverapp.h"
#include "version.h"
#include "sssr.hpp"
#include <string>
#include <iostream>

void srapp::serverApp::start(const int argc, const char **argv)
{
    (void) argv;
    if (argc < 2)
    {
        std::cerr << "Version of ServerApp is " << srapp::version() << ".\t It requires at least one parameter in command line (start, stop, exit, status)." << std::endl;
        return;
    }
    try
    {
        std::cout << "STARTING ServerApp \n" ;
    }
    // catch (const sssr::err &e)
    // {
    //     std::cerr << "Version of ServerApp is " << srapp::version() << ".\t Cannot start ServerApp. Error type - " << e.what() << '\n';
    //     return;
    // }
    catch (const std::exception &e)
    {
        std::cerr << "Version of ServerApp is " << srapp::version() << ".\t Non ServerApp specific error occured during start with error " << e.what() << '\n';
        return;
    }
    ready = true;

    sssr::Server m_Server;
    std::cout << "Server created. Server time: " << m_Server.time() << '\n';
    m_Server.prepare();
    std::cout << m_Server.print();

    started = true;
    
}

