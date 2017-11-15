#ifndef CHILDCLASS_H
#define CHILDCLASS_H

#include "parentclass.h"

class ChildClass : public ParentClass
{
    public:
        string who_am_i();
        string where_am_i();
};

#endif // CHILDCLASS_H
