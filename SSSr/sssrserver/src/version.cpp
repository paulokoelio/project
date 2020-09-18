/**
\file
\brief Реализация функции srapp::version() для вывода версии решения ДЗ

Версия решения ДЗ может быть определена при вызове функции srapp::version()
в коде программы, или при запуске приложения без параметров.
*/
#include "version.h"

namespace srapp
{

    const char *version()
    {
        return PROJECT_VERSION;
    }

} // namespace srapp

