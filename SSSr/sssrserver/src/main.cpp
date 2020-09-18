#include "serverapp.h"

int main(const int argc, const char** argv)
{
    srapp::serverApp application;
    application.start(argc, argv);

    return 0;
}

