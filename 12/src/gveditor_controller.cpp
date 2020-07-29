#include "gveditor_controller.h"
#include "gveditor_basefncl.h"
#include "gveditor_coord2d.h"
#include "version.h"
#include "gveditor_shapes.h"
#include <iostream>
#include <string>

namespace gvedt
{
void controller::init(const int argc, char const **argv)
{
    if (gvedt::controller::ref().init_good == true) return;
    if (argc > 1)
    {
        if (std::string(argv[1]) == std::string("version"))
        {
            std::cout << "Version of gveditor is " << gvedt::version() << std::endl;
            gvedt::controller::ref().exit = true;
        }
        else
        {
            //\todo: Try to open file with name in argv[1]
        }
    }
    // тестируем классы - тестовая зона

    std::cout << " \t"
              << "argc= "
              << "\t" << argc << std::endl;

    // получаем ссылку на гуи
    // создаем новое основное окно Меню
    if (gvedt::controller::ref().exit == true) return;

    gvedt::controller::ref().init_good = true;
}

void controller::init_gui(std::shared_ptr<igui> spgui)
{
    sp_gui = spgui;
    sp_main_window = sp_gui->new_mainwindow(MAIN_WINDOW_SIZE, MAIN_WINDOW_NAME);
    // здесь загружается перечень меню и другие ресурсы gui методом,
    // предусмотренным конкретным типом gui
}

std::shared_ptr<igui> controller::get_gui()
{
    return sp_gui;
}

bool controller::app_exit() const { return gvedt::controller::ref().exit; }

void controller::close_app()
{
    exit = true;
}

void controller::new_document(std::string document_name)
{
    if (!sp_doc_window) sp_doc_window = gvedt::controller::ref().get_gui()->new_window(DOC_WINDOW_SIZE, document_name);
    // Далее здесь логика создания нового документа
    sp_doc = gvedt::controller::ref().sp_doc = slvr::lib::factory<gvedt::doc>();
}

void controller::import_file()
{

}

void controller::export_file()
{

}

void controller::new_shape(gvedt::obj_types shape_type)
{
    if ( !gvedt::controller::ref().sp_doc_window ) return ;
    sp_object = shape_factory(shape_type);
    sp_doc->add_shape(sp_object);
    // Получение из GUI координат точки
    sp_object->create(this->context_data);

}

void controller::delete_shape()
{

}

} // namespace gvedt
