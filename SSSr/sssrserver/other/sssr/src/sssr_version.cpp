/**
\file
\brief Definition of function sssr::version() for output version of SSSr library

To check the version of SSSr library use call of function sssr::version()
inside your code or start ssserver without parameter.
*/
#include "sssr_version.h"

namespace sssr
{

    const char *version()
    {
        return SSSR_PROJECT_VERSION;
    }

} // namespace sssr

