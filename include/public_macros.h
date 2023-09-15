/* tuple access */
#define TUPLE_AT_0(x, ...) x
#define TUPLE_AT_1(x,y,...) y
#define TUPLE_AT_2(x,y,z,...) z
#define CHECK0(...) TUPLE_AT_0(__VA_ARGS__, UNUSED)
#define CHECK1(...) TUPLE_AT_1(__VA_ARGS__, UNUSED)
#define CHECK2(...) TUPLE_AT_2(__VA_ARGS__, UNUSED)

// for recursion by deferred expression
// TODO: need to see if this can replace the constant need to define MACRO_B vs MACR_A in iteration
#define DEFER(id) id EMPTY()
#define OBSTRUCT(...) __VA_ARGS__ DEFER(EMPTY)()
#define EXPAND(...) __VA_ARGS__
#define ACCESSOR OOP_ACCESSOR

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

#define LPAREN() (
#define RPAREN() )

#define TYPE_NAME(name) CAT(name, __)

#define ID(x) x

#define CAT(A, B) CAT_(A, B)
#define CAT_(A, B) A##B

#define NOTCAT(A, B) A B

#define EVAL(func, arg) func(arg)

#define ERASE(...)

#define IIF(c) CAT_(IIF_, c)
#define IIF_0(t, f) f
#define IIF_1(t, f) t

#define COMPL(b) CAT_(COMPL_, b)
#define COMPL_0 1
#define COMPL_1 0

#define EQUAL(x, y) COMPL(NOT_EQUAL(x, y))

#define PROBE(x) x, 1,
#define IS_PAREN(x) CHECK1(IS_PAREN_PROBE x, 0)
#define IS_PAREN_PROBE(...) PROBE(~)

#define COMPARE_(x, y) IS_PAREN( \
OOP_MEMBER_ ## x ( OOP_MEMBER_ ## y) (())  \
)

#define IS_COMPARABLE(x) IS_PAREN( CAT_(OOP_MEMBER_, x) (()) )

#define BITAND(x) CAT_(BITAND_, x)
#define BITAND_0(y) 0
#define BITAND_1(y) y

#define NOT_EQUAL(x, y) \
IIF(BITAND(IS_COMPARABLE(x))(IS_COMPARABLE(y)) ) \
( \
   COMPARE_, \
   1 ERASE \
)(x, y)

#define EMPTY() 

/* POWERFUL */
#define SEQ_IS_EMPTY(seq) COMPL(IS_PAREN(ERASE seq()))

// TODO: should replace most ENDs
#define IS_END_END
#define IS_END(val) IS_PAREN(CAT(IS_END_, val)())

/* sequence actions */
#define SEQ_TERM(...) SEQ_TERM_(__VA_ARGS__)
#define SEQ_TERM_(...) __VA_ARGS__##_TERM

/* transform a sequence to a guide*/
#define SEQ_TO_GUIDE_A(...) __VA_ARGS__ RPAREN EMPTY()()SEQ_TO_GUIDE_B
#define SEQ_TO_GUIDE_B(...) __VA_ARGS__ RPAREN EMPTY()()SEQ_TO_GUIDE_A
#define SEQ_TO_GUIDE_A_TERM
#define SEQ_TO_GUIDE_B_TERM
#define SEQ_TO_GUIDE(seq) SEQ_TERM(SEQ_TO_GUIDE_A seq)

// get first element of a SEQ. will only work for elements that make valid macros. Would be more convenient if I had a SEQ_ERASE function that iterated through, creating nothing
#define SEQ_1ST_PASS_END , SEQ_1ST_PASS_END_END
#define SEQ_1ST_PASS_A(val) CHECK1(SEQ_1ST_PASS_##val, SEQ_1ST_PASS_NEXT)(val, B)
#define SEQ_1ST_PASS_B(val) CHECK1(SEQ_1ST_PASS_##val, SEQ_1ST_PASS_NEXT)(val, A)
#define SEQ_1ST_PASS_NEXT(val, next) SEQ_1ST_PASS_##next
#define SEQ_1ST_PASS_END_END(val, next)
#define SEQ_1ST_(...) __VA_ARGS__ SEQ_1ST_PASS_A
#define SEQ_1ST(seq) IIF(SEQ_IS_EMPTY(seq))(SEQ_1ST_PASS_A , SEQ_1ST_) seq(END)

#define OOP_CLASS_G_HIERARCHY(name) name) OOP_CLASS_G_PARENT_##name

// A and B are bits
#define OOP_OR(A, B) CAT(CAT(OOP_OR_, A), B)
#define OOP_OR_1_ 1
#define OOP_OR__1 1
#define OOP_OR_0_ 0
#define OOP_OR__0 0
#define OOP_OR_1_1 1
#define OOP_OR_0_1 1
#define OOP_OR_1_0 1
#define OOP_OR_0_0 0

#define OOP_AND(A, B) CAT(CAT(OOP_AND_, A), B)
#define OOP_AND_0_ 0
#define OOP_AND_1_ 0
#define OOP_AND__1 0
#define OOP_AND__0 0
#define OOP_AND_1_1 1
#define OOP_AND_0_1 0
#define OOP_AND_1_0 0
#define OOP_AND_0_0 0

#define OOP_XOR(A, B) CAT(CAT(OOP_XOR_, A), B)
#define OOP_XOR__1 1
#define OOP_XOR_1_ 1
#define OOP_XOR_0_ 0
#define OOP_XOR__0 0
#define OOP_XOR_1_1 0
#define OOP_XOR_0_1 1
#define OOP_XOR_1_0 1
#define OOP_XOR_0_0 0

#define OOP_NOT(A) CAT(OOP_NOT_, A)
#define OOP_NOT_ 1
#define OOP_NOT_0 1
#define OOP_NOT_1 0

#define IS_IN_G_0()
#define IS_IN_G_1() , IS_IN_G_FOUND
#define IS_IN_G_END , IS_IN_G_END_END2
#define IS_IN_G_PASS_END , IS_IN_G_END_END
#define IS_IN_G_PASS_A(val) CHECK1(IS_IN_G_PASS_##val, IS_IN_G_PASS_NEXT)(B)
#define IS_IN_G_PASS_B(val) CHECK1(IS_IN_G_PASS_##val, IS_IN_G_PASS_NEXT)(A)
#define IS_IN_G_PASS_NEXT(next) IS_IN_G_PASS_##next(
#define IS_IN_G_A(x, val) IS_IN_G_NEXT_(x, val, EQUAL(x, val), B)
#define IS_IN_G_B(x, val) IS_IN_G_NEXT_(x, val, EQUAL(x, val), A)
#define IS_IN_G_NEXT_(x, val, eq, next) CHECK1(CHECK1(IS_IN_G_##val, CAT(IS_IN_G_, eq))(), IS_IN_G_NEXT)(x, val, eq, next)
#define IS_IN_G_NEXT(x, val, eq, next) IS_IN_G_##next(x, 
#define IS_IN_G_FOUND(x, val, eq, next) 1 IS_IN_G_PASS_A(
#define IS_IN_G_END_END(next)
#define IS_IN_G_END_END2() , IS_IN_G_END_END3
#define IS_IN_G_END_END3(...) 0
#define IS_IN_G(x, guide) IS_IN_G_A(x, guide END)

/*
#define G_CAT1_END , G_CAT1_END_END
#define G_CAT1_A(C) CHECK1(G_CAT1_##C, G_CAT1_NEXT)(C, B)
#define G_CAT1_B(C) CHECK1(G_CAT1_##C, G_CAT1_NEXT)(C, A)
#define G_CAT1_NEXT(C, next) C G_CAT1_##next(
#define G_CAT1_END_END(C, next) 
#define G_CAT1(guide) G_CAT1_A(guide END)
*/

#define G_CAT1_END , G_CAT1_END_END
#define G_CAT1_A(delim, C) CHECK1(G_CAT1_##C, G_CAT1_NEXT)(delim, C, B)
#define G_CAT1_B(delim, C) CHECK1(G_CAT1_##C, G_CAT1_NEXT)(delim, C, A)
#define G_CAT1_NEXT(delim, C, next) delim C G_CAT1_##next(delim, 
#define G_CAT1_END_END(delim, C, next) 
#define G_CAT1(delim, guide) G_CAT1_A(delim, guide END)

// return the first element of a guide. This does not work if G is empty. Need to do a G_IS_EMPTY
#define G_1ST_PASS_END , G_1ST_PASS_END_END
#define G_1ST_PASS_A(val) CHECK1(G_1ST_PASS_##val, G_1ST_PASS_NEXT)(val, B)
#define G_1ST_PASS_B(val) CHECK1(G_1ST_PASS_##val, G_1ST_PASS_NEXT)(val, A)
#define G_1ST_PASS_NEXT(val, next) G_1ST_PASS_##next(
#define G_1ST_PASS_END_END(val, next)
#define G_1ST_(val) val) G_1ST_PASS_A(
#define G_1ST(guide) G_1ST_(guide END)

// I hope I don't need this one
#define OOP_CLASS_G_PARENT_END
// ensures IS_PARENT(A, ) returns 0
#define OOP_CLASS_G_PARENT_ 
// returns true if A is a parent of B
#define IS_PARENT(A, B) IS_IN_G(A, OOP_CLASS_G_PARENT_##B)

#define IS_IN_SEQ(seq, x) IS_IN_G(x, EVAL(SEQ_TO_GUIDE, seq))








// searching hierarhy
// not found in instance's namespace
#define G_SEARCH_HIER_INST_0
// found in instance's namespace. add member to namespace and register found
#define G_SEARCH_HIER_INST_1 , , G_SEARCH_INST_FOUND
// print result and start pass-through
#define G_SEARCH_INST_FOUND(namespace, member, class, next) (class)namespace G_SEARCH_PASS_A(

// not found in class's namespace
#define G_SEARCH_HIER_CLASS_0
// found in class's namespace. add class and namespace and register found
#define G_SEARCH_HIER_CLASS_1 , G_SEARCH_CLASS_FOUND
// print result and start pass-through
// TODO: this is going to have to get fixed depending on how class types are accessed. Specifically, the _(cast to class) cannot have * or parentheses or reserved characters before it. Might have to separate off (member), reprocess depending on instance or class found and then re-append member
#define G_SEARCH_CLASS_FOUND(namespace, member, class, next) (_(cast to class)class)namespace G_SEARCH_PASS_A(

#define G_SEARCH_PASS_END , G_SEARCH_PASS_END_END
#define G_SEARCH_PASS_A(class) CHECK1(G_SEARCH_PASS_##class, G_SEARCH_PASS_NEXT)(class, B)
#define G_SEARCH_PASS_B(class) CHECK1(G_SEARCH_PASS_##class, G_SEARCH_PASS_NEXT)(class, A)
#define G_SEARCH_PASS_NEXT(class, next) G_SEARCH_PASS_##next(
#define G_SEARCH_PASS_END_END(class, next)

#define G_SEARCH_HIER_END(...) , G_SEARCH_HIER_END_END
// check if we ended already otherwise add class to namespace and check class member lists for member
#define G_SEARCH_HIER_A(namespace, member, class) CHECK1(G_SEARCH_HIER_##class, G_SEARCH_HIER_NEXT_0)(namespace, member, class, B)
#define G_SEARCH_HIER_B(namespace, member, class) CHECK1(G_SEARCH_HIER_##class, G_SEARCH_HIER_NEXT_0)(namespace, member, class, A)
// at this pointer, the namespace already includes the class...do not add it again.
// check class member lists for member otherwise move on to next iteration
#define G_SEARCH_HIER_NEXT_0(namespace, member, class, next) CHECK2(CAT(G_SEARCH_HIER_INST_, IS_IN_SEQ(CHECK0(OOP_MEMBERS_T_##class), member)), CAT(G_SEARCH_HIER_CLASS_, IS_IN_SEQ(CHECK1(OOP_MEMBERS_T_##class), member)), G_SEARCH_HIER_NEXT)(namespace, member, class, next)
// move onto next iteration
// old version: #define G_SEARCH_HIER_NEXT(namespace, member, class, next) G_SEARCH_HIER_##next(namespace, member, 
#define G_SEARCH_HIER_NEXT(namespace, member, class, next) MOD_NAMESPACE_##next(G_SEARCH_HIER_##next, namespace, member, class,
// terminate search failure
#define G_SEARCH_HIER_END_END(...) null
// likely need a first pass to check if it is just in the first class so that I do not get extra "." in the namespace
#define G_SEARCH_HIER(member, guide) G_SEARCH_HIER_A( , member, guide END)

// double EXPAND(OBSTRUCT(IIF)) needed to get around painting nested IIF conditions blue
#define BACKTRACK_NAMESPACE_A(namespace, next_class) EXPAND(OBSTRUCT(IIF)(SEQ_IS_EMPTY(namespace)))(ERASE, IIF EMPTY()(IS_PARENT EMPTY()(next_class, SEQ_1ST(namespace)))(CHECK0, BACKTRACK_NAMESPACE_REMOVE))(namespace, next_class, B)
#define BACKTRACK_NAMESPACE_B(namespace, next_class) EXPAND(OBSTRUCT(IIF)(SEQ_IS_EMPTY(namespace)))(ERASE, IIF EMPTY()(IS_PARENT EMPTY()(next_class, SEQ_1ST(namespace)))(CHECK0, BACKTRACK_NAMESPACE_REMOVE))(namespace, next_class, A)
#define BACKTRACK_NAMESPACE_REMOVE(namespace, next_class, next) BACKTRACK_NAMESPACE_NEXT(ERASE namespace, next_class, next)
#define BACKTRACK_NAMESPACE_NEXT(namespace, next_class, next) BACKTRACK_NAMESPACE_##next(namespace, next_class)
#define BACKTRACK_NAMESPACE(namespace, class, next_class) BACKTRACK_NAMESPACE_A(namespace, next_class)

#define PREPEND_CLASS(namespace, class, next_class) (class)namespace
#define PREPROC_NEXT_CLASS(namespace, class, next_class) IIF(IS_PARENT(next_class, class))(PREPEND_CLASS, BACKTRACK_NAMESPACE)(namespace, class, next_class)

// when ready, insert into G_SEARCH_HIER_NEXT as: MOD_NAMESPACE(G_SEARCH_HIER_##next, namespace, member, class,
#define MOD_NAMESPACE_A(next_func, namespace, member, class, next_class) next_func(PREPROC_NEXT_CLASS(namespace, class, next_class), member, next_class)
#define MOD_NAMESPACE_B(next_func, namespace, member, class, next_class) next_func(PREPROC_NEXT_CLASS(namespace, class, next_class), member, next_class)

// reverse a sequence
#define SEQ_REV_A(seq_out, val) IIF(IS_END(val))(SEQ_REV_RETURN, SEQ_REV_NEXT)(seq_out, val, B)
#define SEQ_REV_B(seq_out, val) IIF(IS_END(val))(SEQ_REV_RETURN, SEQ_REV_NEXT)(seq_out, val, A)
#define SEQ_REV_NEXT(seq_out, val, next) SEQ_REV_##next((val)seq_out, 
#define SEQ_REV_RETURN(seq_out, val, B) seq_out
#define SEQ_REV_0(seq_out, guide) SEQ_REV_A(seq_out, guide END)
#define SEQ_REV_(seq) SEQ_REV_0( , SEQ_TO_GUIDE(seq))
#define SEQ_REV(seq) IIF(SEQ_IS_EMPTY(seq))( , SEQ_REV_)(seq)

// this is not a generic join since it cannot accept a '.' delimiter. additionally, it formats the classes for use with OOP_GET
#define SEQ_JOIN_A(joined, val) IIF(IS_END(val))(SEQ_JOIN_RETURN, SEQ_JOIN_NEXT)(joined, val, B)
#define SEQ_JOIN_B(joined, val) IIF(IS_END(val))(SEQ_JOIN_RETURN, SEQ_JOIN_NEXT)(joined, val, A)
#define SEQ_JOIN_NEXT_(joined, val) joined.val
#define SEQ_JOIN_NEXT(joined, val, next) SEQ_JOIN_##next(SEQ_JOIN_NEXT_(joined, TYPE_NAME(val)), 
#define SEQ_JOIN_RETURN(joined, val, next) joined
#define SEQ_JOIN_0(joined, guide) SEQ_JOIN_A(joined, guide END)
#define SEQ_JOIN_(seq) SEQ_JOIN_0(TYPE_NAME(SEQ_1ST(seq)), SEQ_TO_GUIDE(ERASE seq))
#define SEQ_JOIN(seq) IIF(SEQ_IS_EMPTY(seq))(ERASE, SEQ_JOIN_)(seq)

#define OOP_GET_(class, member) SEQ_JOIN(SEQ_REV(G_SEARCH_HIER(member, OOP_CLASS_G_PARENT_##class)))
//#define OOP_GET(class, inst, member) inst IIF(IS_IN_SEQ(OOP_MEMBERS_T_##class, member))(ERASE, OOP_GET_)(class, member) .member
//#define OOP_GET(class, inst, member) IIF(IS_IN_SEQ(CHECK0(CAT(OOP_MEMBERS_T_, class)), member))(inst ERASE, CAT(inst, ACCESSOR) OOP_GET_)(class, member) CAT(ACCESSOR, member)
#define OOP_GET(class, inst, member) IIF(IS_IN_SEQ(CHECK0(CAT(OOP_MEMBERS_T_, class)), member))((inst) ERASE, (inst). OOP_GET_)(class, member) .member
#define OOP_SUPER1(A) A. TYPE_NAME(G_CAT1(, G_1ST(OOP_CLASS_G_PARENT_##A)))
#define OOP_SUPER2(A, B) A. TYPE_NAME(B)
#define OOP_SUPER(...) CHECK2(__VA_ARGS__, OOP_SUPER2, OOP_SUPER1)(__VA_ARGS__)

#define OOP_CLASS_INST(name) EXPAND(TYPE_NAME EMPTY()(CLASS_MANGLE(name)))
#define CLASS_MANGLE(type) CAT(type, _CLASS)
// need a way to also cast to the correct function prototype
#define __INIT__(name, ...) OOP_CLASS_INST(name).init
