/**
\file
\brief Реализация приложения gveditor

Основной файл приложения gveditor, включая объявление псевдофункций GUI. 
*/
#include <cassert>
#include <exception>
#include <iostream>
#include <list>

#include "gveditor.h"

// gui functions
namespace gvedt
{

struct gui_lib : public igui
{
public:
    virtual std::shared_ptr<cl_window> new_mainwindow(slvr::lib::coord2d size, std::string name) override
    {
        UNUSED(size);
        UNUSED(name);
        // Здесь создается основное окно приложения (единственное) с меню
        return std::shared_ptr<cl_window>(new cl_window);
    }
    virtual std::shared_ptr<cl_window> new_window(slvr::lib::coord2d size, std::string name) override
    {
        UNUSED(size);
        UNUSED(name);
        // Здесь создается дочернее окно, например, для документа
        return std::shared_ptr<cl_window>(new cl_window);
    }
    virtual void process() override
    {
        // Здесь обрабатываются события от ОС и в зависимости от выбора меню вызываются
        // соответствующие методы контроллера после соответствующей обработки
        // включая получение необходимой информации (ввода имени файла или документа)
        // обрабатываемое gui. Упрощенный пример приводится ниже.
        char console_input;
        std::cin >> console_input;
        std::cin.clear();
        std::cout << "input char= \t" << console_input << std::endl;
        switch (console_input)
        {
        case 27:
            gvedt::controller::ref().close_app();
            break;
        case 'n':
            gvedt::controller::ref().new_document(std::string("new"));
            break;
        case 'i':
            gvedt::controller::ref().import_file();
            break;
        case 'e':
            gvedt::controller::ref().export_file();
            break;
        case 's':
            gvedt::controller::ref().new_shape(gvedt::obj_types::POINT);
            break;
        case 'd':
            gvedt::controller::ref().delete_shape();
            break;
        }
    }
};

} // namespace gvedt
// ---end--- gui functions

int main(int argc, char const *argv[])
{

    try
    {
        using namespace slvr::lib;
        using namespace gvedt;
        gvedt::controller::ref().init(argc, argv);
        gvedt::controller::ref().init_gui(factory<gui_lib>());

        while (!gvedt::controller::ref().app_exit())
        {
            gvedt::controller::ref().get_gui()->process();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << "gveditor version " << version() << std::endl;
    }

    return 0;
}
