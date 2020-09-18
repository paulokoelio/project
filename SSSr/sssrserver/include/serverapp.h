/**
\file
\brief Заголовочный файл общий для приложения serverApp

Заголовочный файл с подключением всех остальных заголовочных файлов, 
необходимых для компиляции serverApp.
*/
#ifndef SERVERAPP_H_
#define SERVERAPP_H_

#include "version.h"
#include <string>
#include <vector>

namespace srapp
{

constexpr char default_subdir[]{"./log/"};

class serverApp
{
private:
    bool ready;
    bool started;

public:
    serverApp() : ready(false), started(false) {}
    serverApp(const serverApp &x) = delete;
    serverApp(serverApp &&x) = delete;
    ~serverApp() = default;
    serverApp &operator=(const serverApp &x) = delete;
    serverApp &operator=(serverApp &&x) = delete;

    void start(const int argc, const char **argv);
};

} // namespace srapp

#endif /* SERVERAPP_H_ */

