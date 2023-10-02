#include <oopc.h>
IFNDEF COMPARABLE_H
DEFINE COMPARABLE_H

INCLUDE_OOPC

/*
Comparable is in fact a base class and an interface. Some objects, specifically generic 
containers, will have a different compare function for each instance, while many objects will 
themselves be comparable among different instances of the classes, and so it is an interface. In 
most cases, the interface function will be call in a simple search with OOP_GET so the user must
specify the base class that owns the implementation of comparable, i.e. SUPER(InstanceType, 
instance, BaseClassWithDesiredCompareFunction).compare(object1, object2)
*/

CLASS(Comparable,
    FUNCTION(NULL, int, compare, void *, void *)
)

ENDIF // COMPARABLE_H
