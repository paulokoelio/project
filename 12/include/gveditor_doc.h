#ifndef GVEDITOR_DOC_H_
#define GVEDITOR_DOC_H_

#include "gveditor_iobj.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>

namespace gvedt
{

class doc
{
    friend inline std::ostream &operator<<(std::ostream &out, const gvedt::doc &document);

private:
    std::string name;
    std::map<int, std::shared_ptr<iobj>> shapes;
    int index{1};
public:
    void serialize(std::ostream &out) const;

public:
    doc() {std::cerr << "Created document " << std::endl ;};
    doc(const doc &x) = delete;
    doc(doc &&x) = delete;
    ~doc() {std::cerr << "Destoyed document " << std::endl ;};
    doc &operator=(const doc &x) = delete;
    doc &operator=(doc &&x) = delete;

    void add_shape(std::shared_ptr<gvedt::iobj> sp_new_obj);
};

} // namespace gvedt

inline std::ostream &operator<<(std::ostream &out, const gvedt::doc &document)
{
    // Здесь должна быть сериализация всего документа в поток
    // Перед каждой фигурой записывается ее тип, полученный методом get_type()
    /* например, так:         */
    
    document.serialize(out);
    return out;

    /* */
}

#endif /* GVEDITOR_DOC_H_ */