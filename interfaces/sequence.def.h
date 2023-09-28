
// Sequence interface
CLASS(Sequence,
    FUNCTION(NULL, size_t, len, void *)
    FUNCTION(NULL, void *, get, void *, size_t)
    EXTENDS(Creatable)
)