#ifndef GVEDITOR_IGUI_H_
#define GVEDITOR_IGUI_H_

#include "gveditor_coord2d.h"
#include <memory>
#include <string>
#include <tuple>
#include <vector>

namespace gvedt
{

struct cl_window
{
    void *handle;
    slvr::lib::coord2d size;
    std::string name{};
};


class igui
{
public:
    virtual std::shared_ptr<cl_window> new_mainwindow(slvr::lib::coord2d size, std::string name) = 0;
    virtual std::shared_ptr<cl_window> new_window(slvr::lib::coord2d size, std::string name) = 0;
    virtual void process() = 0;
    virtual ~igui(){};
};

} // namespace gvedt

#endif /* GVEDITOR_IGUI_H_ */
