#include <oopc.h>
// test IS_PAREN
IS_PAREN(())    // 1
IS_PAREN(()x)   // 0 this fails. Basically IS_PAREN only works if input does not start with parentheses
IS_PAREN(x())   // 0
IS_PAREN(x)     // 0

//
// test concatentations
CATD(a, b, )    // ab
CATD(a, b, _)   // a_b
CATS(a, b)      // a b
CATC(a, b)      // a, b
CATC(,)         // ,

#define SEQ_EMPTY
#define SEQ_1EL (a)
#define SEQ_2EL (a)(b)
#define SEQ_3EL (a)(b)(c)
#define SEQ_END (OOP_END)
#define SEQ_END_1 (a)(OOP_END)

//
// test S_IS_EMPTY
S_IS_EMPTY(SEQ_EMPTY)   // 1
S_IS_EMPTY(SEQ_1EL)     // 0
S_IS_EMPTY(SEQ_2EL)     // 0
S_IS_EMPTY(SEQ_3EL)     // 0
S_IS_EMPTY(SEQ_END)     // 0
S_IS_EMPTY(SEQ_END_1)   // 0

//
// test S_1ST
S_1ST(SEQ_EMPTY)   // (empty)
S_1ST(SEQ_1EL)     // (a)
S_1ST(SEQ_2EL)     // (a)
S_1ST(SEQ_3EL)     // (a)
S_1ST(SEQ_END)     // (OOP_END)
S_1ST(SEQ_END_1)   // (a)

//
// test S_ERASE
S_ERASE(SEQ_EMPTY)   // (empty)
S_ERASE(SEQ_1EL)     // (empty)
S_ERASE(SEQ_2EL)     // (empty)
S_ERASE(SEQ_3EL)     // (empty)
//
// test S_ERASE_
S_ERASE_(SEQ_END)     // (empty)
S_ERASE_(SEQ_END_1)   // (empty)

//
// test S_IF
S_IF()                  // (empty)
S_IF((0, 0th))          // (empty)
S_IF((1, 0th))          // 0th
S_IF((1, 0th)(0, 1st))  // 0th
S_IF((1, 0th)(1, 1st))  // 0th
S_IF((0, 0th)(1, 1st))  // 1st
S_IF((0, 0th)(0, 1st))  // (empty)
S_IF((0, 0th)(0, 1st)(0, 2nd))  // empty
S_IF((1, 0th)(0, 1st)(0, 2nd))  // 0th
S_IF((0, 0th)(1, 1st)(0, 2nd))  // 1st
S_IF((1, 0th)(1, 1st)(0, 2nd))  // 0th
S_IF((0, 0th)(0, 1st)(1, 2nd))  // 2nd
S_IF((1, 0th)(0, 1st)(1, 2nd))  // 0th
S_IF((0, 0th)(1, 1st)(1, 2nd))  // 1st
S_IF((1, 0th)(1, 1st)(1, 2nd))  // 0th

//
// test S_TO_G
S_TO_G(SEQ_EMPTY)   // (empty)
S_TO_G(SEQ_1EL)     // a) 
S_TO_G(SEQ_2EL)     // a) b)
S_TO_G(SEQ_3EL)     // a) b) c)
// test S_TO_G_
S_TO_G_(SEQ_END)    // (empty)
S_TO_G_(SEQ_END_1)  // a)

//
#define GUIDE_EMPTY
#define GUIDE_1EL a) 
#define GUIDE_2EL a) b)
#define GUIDE_3EL a) b) c)
#define GUIDE_ababa a) b) a) b) a)
#define GUIDE_END OOP_END)
#define GUIDE_END_1 a) OOP_END)

//
// test G_ERASE
G_ERASE(GUIDE_EMPTY)    // (empty)
G_ERASE(GUIDE_1EL)      // (empty)
G_ERASE(GUIDE_2EL)      // (empty)
G_ERASE(GUIDE_3EL)      // (empty)
// test G_ERASE_
PASS_ARGS(G_ERASE_ LPAREN() GUIDE_END)      // (empty) NOTE: have to use PASS_ARGS
PASS_ARGS(G_ERASE_ LPAREN() GUIDE_END_1)    // (empty) NOTE: have to use PASS_ARGS

//
// test G_1ST
G_1ST(GUIDE_EMPTY)      // (empty)
G_1ST(GUIDE_1EL)        // a)
G_1ST(GUIDE_2EL)        // a)
G_1ST(GUIDE_3EL)        // a)
PASS_ARGS(G_1ST_ LPAREN() GUIDE_END)        // (empty)) NOTE: have to use PASS_ARGS
PASS_ARGS(G_1ST_ LPAREN() GUIDE_END_1)      // a) NOTE: have to use PASS_ARGS

//
// test G_TO_G
#define PREFIX(arg) CAT(PREFIX_, arg)
G_TO_G(PREFIX, GUIDE_EMPTY)                     // (empty)
G_TO_G(PREFIX, GUIDE_1EL)                       // PREFIX_a)
G_TO_G(PREFIX, GUIDE_2EL)                       // PREFIX_a) PREFIX_b)
G_TO_G(PREFIX, GUIDE_3EL)                       // PREFIX_a) PREFIX_b) PREFIX_c)
PASS_ARGS(G_TO_G_ LPAREN() PREFIX, GUIDE_END)   // (empty) NOTE: have to use PASS_ARGS
PASS_ARGS(G_TO_G_ LPAREN() PREFIX, GUIDE_END_1) // PREFIX_a) NOTE: have to use PASS_ARGS

//
// test G_TO_S
G_TO_S(PASS_ARGS, GUIDE_EMPTY)      // (empty)
G_TO_S(PASS_ARGS, GUIDE_1EL)        // (a)
G_TO_S(PASS_ARGS, GUIDE_2EL)        // (a) (b)
G_TO_S(PASS_ARGS, GUIDE_3EL)        // (a) (b) (c)
PASS_ARGS_(G_TO_S_ LPAREN() PASS_ARGS INSERT_COMMA() GUIDE_END)        // (empty)) NOTE: have to use PASS_ARGS
PASS_ARGS_(G_TO_S_ LPAREN() PASS_ARGS INSERT_COMMA()GUIDE_END_1)      // (a) NOTE: have to use PASS_ARGS

//
// test G_FILTER
// need to add test cases
#define OOP_MEMBER_a(x) x
#define OOP_MEMBER_b(x) x
#define OOP_MEMBER_c(x) x
#define SELECT_a(val) EQUAL(a, val)
#define SELECT_b(val) EQUAL(b, val)
// COMPARE_
COMPARE_(a, b)      // 1
COMPARE_(a, a)      // 0
IS_COMPARABLE(a)    // 1
IS_COMPARABLE(b)    // 1
// EQUAL
EQUAL(a, b)         // 0
EQUAL(a, a)         // 1
// NOT_EQUAL
NOT_EQUAL(a, b)     // 1

//
// test G_FILTER
G_FILTER(SELECT_a, GUIDE_EMPTY) // (empty)
G_FILTER(SELECT_a, GUIDE_1EL)   // a)
G_FILTER(SELECT_a, GUIDE_2EL)   // a) 
G_FILTER(SELECT_b, GUIDE_1EL)   // (empty)
G_FILTER(SELECT_b, GUIDE_2EL)   // b)
G_FILTER(SELECT_a, GUIDE_ababa) // a) a) a)
G_FILTER(SELECT_b, GUIDE_ababa) // b) b)

//
// test G_IF
// need to add test cases

//
// test IS_IN_G
IS_IN_G(a, GUIDE_EMPTY) // 0
IS_IN_G(a, GUIDE_1EL)   // 1
IS_IN_G(b, GUIDE_1EL)   // 0
IS_IN_G(a, GUIDE_3EL)   // 1
IS_IN_G(b, GUIDE_3EL)   // 1
IS_IN_G(c, GUIDE_3EL)   // 1
IS_IN_G(d, GUIDE_3EL)   // 0

//
// test IS_IN_S
IS_IN_S(a, SEQ_EMPTY)   // 0
IS_IN_S(a, SEQ_1EL)     // 1
IS_IN_S(b, SEQ_1EL)     // 0
IS_IN_S(a, SEQ_3EL)     // 1
IS_IN_S(b, SEQ_3EL)     // 1
IS_IN_S(c, SEQ_3EL)     // 1
IS_IN_S(d, SEQ_3EL)     // 0

//
// make member def
MAKE_MEMBER_DEF(some_member_type, (decl, type, name))
#define GUIDE_1MEM MEMBER_TYPE, (var1 decl, var type, var name1, ))
#define GUIDE_3MEM MEMBER_TYPE, (var1 decl, var type, var name1, )) MEMBER_TYPE, (var2 decl, var type, var name2, )) MEMBER_TYPE, (var3 decl, var type, var name3))
MAKE_MEMBER_DEFS(GUIDE_3MEM)

#define seq (I_CLASS, class__)(I, I__)(D_CLASS, class__)(D, (*d))
    OOP_BT_NS(seq, B)