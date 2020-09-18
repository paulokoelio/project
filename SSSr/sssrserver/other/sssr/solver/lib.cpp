#include "lib.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <string>

namespace slvr
{

namespace lib
{

unsigned long long fixed_time_in_usec()
{
    unsigned long long res;
    auto t0 = std::chrono::steady_clock::now().time_since_epoch();
    std::chrono::microseconds t_sec = std::chrono::duration_cast<std::chrono::microseconds>(t0);
    res = t_sec.count();
    return res;
}

std::vector<std::string> split(const std::string &str, char d, const size_t parts)
{
    std::vector<std::string> r;
    r.reserve(parts);

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    size_t iter = parts;
    while ((stop != std::string::npos) && (iter > 0))
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
        --iter;
    }
    if (iter > 0)
        r.push_back(str.substr(start));

    return r;
}

} // namespace lib

} // namespace slvr
