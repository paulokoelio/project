#include "gveditor_doc.h"
#include <map>

using namespace gvedt;

// inline std::ostream &operator<<(std::ostream &out, const gvedt::doc &document)
// {
//     // Здесь должна быть сериализация всего документа в поток
//     // Перед каждой фигурой записывается ее тип, полученный методом get_type()
//     /* например, так:         */
//     std::string temp_string;
//     temp_string = name;
//     out << static_cast<long>(name.size()) << std::endl;
//     std::copy(name.cbegin(), name.cend(), std::ostream_iterator<char>{out});
//     out << std::endl;
//     out << static_cast<long>(shapes.size()) << std::endl;
//     for (auto & el: shapes )
//     {
//         out << static_cast<long>(el.second->get_type()) << '\n';
//         out << static_cast<long>(el.first) << '\n';
//         out << *(el.second) << '\n';
//     };

//     return out;

//     /* */
// }

void gvedt::doc::add_shape(std::shared_ptr<gvedt::iobj> sp_new_obj)
{
    auto result = shapes.insert({index, sp_new_obj});
    (void)result;
    // Здесь должна быть проверка уникальности ID - если ID уже используется, то index увеличивается на 1 и проверяется повторно
    shapes[index]->set_id(index);
    ++index;
}

void gvedt::doc::serialize(std::ostream &out) const
{
    out << static_cast<long>(name.size()) << std::endl;
    std::copy(name.cbegin(), name.cend(), std::ostream_iterator<char>{out});
    out << std::endl;
    out << static_cast<long>(shapes.size()) << std::endl;

    for (auto &el : shapes)
    {
        out << static_cast<long>(el.second->get_type()) << '\n';
        out << static_cast<long>(el.first) << '\n';
        out << el.second.get() << '\n';
    };
}