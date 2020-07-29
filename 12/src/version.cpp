/**
\file
\brief Реализация функции gvedt::version() для вывода версии решения ДЗ

Версия решения ДЗ может быть определена в коде программы путем вызова 
функции gvedt::version()
*/
#include "version.h"

namespace gvedt
{

    const char *version()
    {
        return PROJECT_VERSION;
    }

} // namespace gvedt