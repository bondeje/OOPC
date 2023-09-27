#include <oopc.h>
INCLUDE_OOPC

enum iterator_status {
    ITERATOR_FAIL = -1,
    ITERATOR_GO,
    ITERATOR_STOP,
    ITERATOR_PAUSE,
};

CLASS(Iterator,
    FUNCTION(NULL, enum iterator_status, next, void *, void *)
    FUNCTION(NULL, enum iterator_status, stop, void *)
    IMPLEMENTS(Creatable, new, NULL, init, NULL, del, NULL)
)