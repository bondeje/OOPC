// general notes on data structures
// macros beginning with T manipulate tuples
// macros beginning with S manipulate sequence inputs
// macros beginning with G manipulate guide inputs

#include <config.h>
#include <directives.h>

// Generic meta-programming macros
#include <pptuples.h>

/* miscellaneous */
#define HASH_LIT #
#define INSERT_COMMA_0(...) , 0, 
#define INSERT_COMMA_1(...) , 1, 
#define INSERT_COMMA() ,
/* stringify */
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

/* concatenations */
// output with a delimiter between
#define CATD(left, right, delim) CATD_(left, right, delim)
#define CATD_(left, right, delim) left##delim##right
// output with a space between
#define CATS(left, right) CATS_(left, right)
#define CATS_(left, right) left right
// concatenate with a comma space
#define CATC(left, right) CATC_(left, right)
#define CATC_(left, right) left, right
#define CAT(left, right) CAT_(left, right)
#define CAT_(left, right) left##right

/* parenthesis manipulation and checking */
#define LPAREN() (
#define RPAREN() )
// only works if x does not start with a set of '()'. Worse if x is a sequence of (...)x for any x, results in '1'
#define IS_PAREN(x) T_INSPECT_1(IS_PAREN_ x, 0)
#define IS_PAREN_(x) CATC(x, 1) 

/* recursion utilities */
#define SPLIT(fmacro) fmacro EMPTY()
#define OBSTRUCT(...) __VA_ARGS__ SPLIT(EMPTY)()
#define PASS_ARGS(...) __VA_ARGS__
#define PASS_ARGS_(...) __VA_ARGS__
#define ERASE_ARGS(...)
#define ERASE_ARGS_(...)
#define EMPTY() 
#define FEVAL(func, ...) func(__VA_ARGS__)
#define FARGEVAL(func, args) func args

// check if this is actually used
#define OOP_OR(A, B) CATD(CAT(OOP_OR_, A), B, _)
#define OOP_OR_1_ 1
#define OOP_OR__1 1
#define OOP_OR_0_ 0
#define OOP_OR__0 0
#define OOP_OR_1_1 1
#define OOP_OR_0_1 1
#define OOP_OR_1_0 1
#define OOP_OR_0_0 0

// check if this is actually used
#define OOP_AND(A, B) CATD(CAT(OOP_AND_, A), B, _)
#define OOP_AND_0_ 0
#define OOP_AND_1_ 0
#define OOP_AND__1 0
#define OOP_AND__0 0
#define OOP_AND_1_1 1
#define OOP_AND_0_1 0
#define OOP_AND_1_0 0
#define OOP_AND_0_0 0

// check if this is actually used
#define OOP_XOR(A, B) CATD(CAT(OOP_XOR_, A), B, _)
#define OOP_XOR__1 1
#define OOP_XOR_1_ 1
#define OOP_XOR_0_ 0
#define OOP_XOR__0 0
#define OOP_XOR_1_1 0
#define OOP_XOR_0_1 1
#define OOP_XOR_1_0 1
#define OOP_XOR_0_0 0

// OOP_NOT is definitely used
#define OOP_NOT(b) CAT(OOP_NOT_, b)
#define OOP_NOT_0 1
#define OOP_NOT_1 0

/* comparisons */
#define IS_COMPARABLE(x) IS_PAREN( CAT(OOP_MEMBER_, x)(()))
#define OOP_IF(cond) CATD(OOP_IF_, cond, )
#define OOP_IF_0(true_, false_) false_
#define OOP_IF_1(true_, false_) true_
#define OOP_ELSE_IF(cond) CAT(OOP_ELSE_IF_, cond)
#define OOP_ELSE_IF_0(true_, false_) false_ 
#define OOP_ELSE_IF_1(true_, false_) true_
#define EQUAL(x, y) OOP_NOT(NOT_EQUAL(x, y))
#define COMPARE_(x, y) IS_PAREN(CAT(OOP_MEMBER_,x)( CAT(OOP_MEMBER_, y))(()))
#define NOT_EQUAL(x, y)                             \
OOP_IF(OOP_AND(IS_COMPARABLE(x), IS_COMPARABLE(y)) )\
(                                                   \
   COMPARE_,                                        \
   1 ERASE_ARGS                                     \
)(x, y)

// for switch statement, turn tuple into seqence, processing each element
// IF_CASE iterates through a sequence of condition/result pairs and returns the first true value from the subsequent tuple of arguments. mark an "else" case as (1)
// e.g. S_IF((cond_0, result_0)(cond_1, result_1)(cond_2, result_2)...(1, else_result)) returns result_1 if cond_0 is 0 and cond_1 is 1

/* STRUCTURE ALGORITHMS */
#define IS_OOP_END_OOP_END
#define IS_OOP_END(val) IS_PAREN(CAT(IS_OOP_END_, val)())

/* sequence operations */
#define S_1ST_0(...) CATC((__VA_ARGS__), )
#define S_1ST_(seq) T_INSPECT_0(S_1ST_0 seq)
#define S_1ST(seq) OOP_IF(S_IS_EMPTY(seq))(ERASE_ARGS, S_1ST_)(seq)
#define S_IS_EMPTY(seq) T_INSPECT_1(INSERT_COMMA_0 seq, 1)
// erase the rest of a seq. If already post-pended with (OOP_END) start call at S_ERASE_
// the next two lines are original, they might resolve better
//#define S_ERASE_0(...) T_INSPECT_1(OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(PASS_ARGS, ERASE_ARGS)(, ERASE_ARGS), S_ERASE_NEXT)(1)
//#define S_ERASE_1(...) T_INSPECT_1(OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(PASS_ARGS, ERASE_ARGS)(, ERASE_ARGS), S_ERASE_NEXT)(0)
#define S_ERASE_0(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, S_ERASE_NEXT)(1)
#define S_ERASE_1(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, S_ERASE_NEXT)(0)
#define S_ERASE_NEXT(next) S_ERASE_##next
#define S_ERASE_(seq) S_ERASE_0 seq
#define S_ERASE(seq) OOP_IF(S_IS_EMPTY(seq))(ERASE_ARGS, S_ERASE_)(seq(OOP_END))

// this should be pretty powerful...compound if statements. From a sequence cond_seq of pairs (cond, val), selects the first val where cond is true
// the guide version is going to be even better
// the next two lines are original, they might resolve better
//#define S_IF_0(cond, result) T_INSPECT_1(OOP_IF(IS_OOP_END(cond))(PASS_ARGS, ERASE_ARGS)(,), OOP_IF(cond)(result S_ERASE_0, S_IF_1))
//#define S_IF_1(cond, result) T_INSPECT_1(OOP_IF(IS_OOP_END(cond))(PASS_ARGS, ERASE_ARGS)(,), OOP_IF(cond)(result S_ERASE_0, S_IF_0))
#define S_IF_0(cond, result) OOP_IF(IS_OOP_END(cond))( , OOP_IF(cond)(result S_ERASE_0, S_IF_1))
#define S_IF_1(cond, result) OOP_IF(IS_OOP_END(cond))( , OOP_IF(cond)(result S_ERASE_0, S_IF_0))
#define S_IF_(cond_seq) S_IF_0 cond_seq
#define S_IF(cond_seq) OOP_IF(S_IS_EMPTY(cond_seq))(ERASE_ARGS, S_IF_)(cond_seq(OOP_END, OOP_END))

#define S_ANY_0(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(0 , OOP_IF(T_INSPECT_0(__VA_ARGS__))(1 S_ERASE_0, S_ANY_1))
#define S_ANY_1(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(0 , OOP_IF(T_INSPECT_0(__VA_ARGS__))(1 S_ERASE_0, S_ANY_0))
#define S_ANY_(seq) S_ANY_0 seq
#define S_ANY(cond_seq) OOP_IF(S_IS_EMPTY(cond_seq))(0 ERASE_ARGS, S_ANY_)(cond_seq(OOP_END))

#define ANY(...) S_ANY(T_TO_S(__VA_ARGS__))

// transform sequence to guide data structure
// the next two lines are original, they might resolve better
//#define S_TO_G_0(...) T_INSPECT_1(OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(PASS_ARGS, ERASE_ARGS)(, ), __VA_ARGS__ OBSTRUCT(RPAREN)() S_TO_G_1)
//#define S_TO_G_1(...) T_INSPECT_1(OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(PASS_ARGS, ERASE_ARGS)(, ), __VA_ARGS__ OBSTRUCT(RPAREN)() S_TO_G_0)
#define S_TO_G_0(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, S_TO_G_NEXT)((__VA_ARGS__), 1)
#define S_TO_G_1(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, S_TO_G_NEXT)((__VA_ARGS__), 0)
#define S_TO_G_NEXT(vals, next) PASS_ARGS_ vals) S_TO_G_##next
#define S_TO_G_(seq) S_TO_G_0 seq
#define S_TO_G(seq) OOP_IF(S_IS_EMPTY(seq))(ERASE_ARGS, S_TO_G_)(seq(OOP_END))

#define IS_IN_S(x, seq) IS_IN_G(x, S_TO_G(seq))

// S_JOIN only combines the elements in the sequence, but it cannot put in delimiters. for that, use G_JOIN
// I don't think this is used and does not necessarily make sense
#define S_JOIN_0(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, S_JOIN_NEXT)((__VA_ARGS__), 1)
#define S_JOIN_1(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, S_JOIN_NEXT)((__VA_ARGS__), 0)
#define S_JOIN_NEXT(vals, next) PASS_ARGS_ vals S_JOIN_##next
#define S_JOIN(seq) S_JOIN_0(seq(OOP_END))

// sequence to tuple
#define S_TO_T_0(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, S_TO_T_NEXT)((__VA_ARGS__), 1)
#define S_TO_T_1(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, S_TO_T_NEXT)((__VA_ARGS__), 0)
#define S_TO_T_NEXT(vals, next) , PASS_ARGS_ vals S_TO_T_##next
#define S_TO_T(seq) PASS_ARGS(OOP_IF(S_IS_EMPTY(seq))(ERASE_ARGS, PASS_ARGS_ S_1ST(seq) S_TO_T_0 ERASE_ARGS) seq(OOP_END))

// erase of the remainder of a guide. Note that if guide iteration has already started, need to call PASS_ARGS(G_ERASE_ LPAREN() guide)
#define G_ERASE_0(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))( , G_ERASE_1 LPAREN())
#define G_ERASE_1(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))( , G_ERASE_0 LPAREN())
#define G_ERASE_ G_ERASE_0
#define G_ERASE(guide) G_ERASE_0(guide OOP_END)

// old probably delete
//#define G_1ST_0(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))( , G_1ST_1 LPAREN())
//#define G_1ST_1(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))( , G_1ST_0 LPAREN())
// return only the first element of the guide.
#define G_1ST_(...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))( , __VA_ARGS__ G_ERASE_ LPAREN())
#define G_1ST(guide) G_1ST_(guide OOP_END)

#define G_IF_0(cond, result) OOP_IF(IS_OOP_END(cond))( , OOP_IF(cond)(result G_ERASE_0 LPAREN(), G_IF_1 LPAREN()))
#define G_IF_1(cond, result) OOP_IF(IS_OOP_END(cond))( , OOP_IF(cond)(result G_ERASE_0 LPAREN(), G_IF_0 LPAREN()))
#define G_IF_ S_IF_0
#define G_IF(cond_guide) G_IF_(guide OOP_END, OOP_END)

// this can probably be replaced by G_JOIN where the func returns a guide element
#define G_TO_G_0(func, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, G_TO_G_NEXT)(func, (__VA_ARGS__), 1)
#define G_TO_G_1(func, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, G_TO_G_NEXT)(func, (__VA_ARGS__), 0)
#define G_TO_G_NEXT(func, vals, next) func vals ) G_TO_G_##next(func, 
#define G_TO_G_ G_TO_G_0
#define G_TO_G(func, guide) G_TO_G_(func, guide OOP_END)

// same as G_TO_G but func takes arguments
#define G_TO_G_A_0(func, args, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, G_TO_G_A_NEXT)(func, args, (__VA_ARGS__), 1)
#define G_TO_G_A_1(func, args, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, G_TO_G_A_NEXT)(func, args, (__VA_ARGS__), 0)
#define G_TO_G_A_NEXT(func, args, vals, next) PASS_ARGS(func EMPTY()(args, PASS_ARGS_ vals)) ) G_TO_G_A_##next(func, args, 
#define G_TO_G_A_ G_TO_G_A_0
#define G_TO_G_A(func, args, guide) G_TO_G_A_(func, args, guide OOP_END)

// useful functions for G_TO_G
#define PREPEND_NEWLINE(stmt) OOP_NEWLINE stmt
#define PREPEND_NEWLINE_1TAB(stmt) OOP_NEWLINE OOP_TAB stmt
#define PREPEND_MACRO(macro, ...) macro##__VA_ARGS__

#define G_FILTER_0(cond_func, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, G_FILTER_NEXT)(cond_func, (__VA_ARGS__), 1)
#define G_FILTER_1(cond_func, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, G_FILTER_NEXT)(cond_func, (__VA_ARGS__), 0)
#define G_FILTER_NEXT(cond_func, vals, next)  OOP_IF(cond_func vals)(PASS_ARGS_ vals RPAREN(), ) G_FILTER_##next(cond_func, 
#define G_FILTER_ G_FILTER_0
#define G_FILTER(cond_func, guide) G_FILTER_(cond_func, guide OOP_END)

// this can probably be replaced by a call to G_JOIN where the func returns a sequence element
#define G_TO_S_0(func, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, G_TO_S_NEXT)(func, (__VA_ARGS__), 1)
#define G_TO_S_1(func, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, G_TO_S_NEXT)(func, (__VA_ARGS__), 0)
#define G_TO_S_NEXT(func, vals, next) (func vals) G_TO_S_##next(func, 
#define G_TO_S_ G_TO_S_0
#define G_TO_S(func, guide) G_TO_S_(func, guide OOP_END)

#define IS_IN_G_0(x, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(0 ERASE_ARGS, IS_IN_G_NEXT)(EQUAL(x, T_INSPECT_0(__VA_ARGS__)), x, 1)
#define IS_IN_G_1(x, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(0 ERASE_ARGS, IS_IN_G_NEXT)(EQUAL(x, T_INSPECT_0(__VA_ARGS__)), x, 0)
#define IS_IN_G_FOUND(x, next) G_ERASE_0(
#define IS_IN_G_NEXT_(x, next) IS_IN_G_##next(x, 
#define IS_IN_G_NEXT(tf, x, next) OOP_IF(tf)(1 IS_IN_G_FOUND, IS_IN_G_NEXT_) (x, next)
#define IS_IN_G_ IS_IN_G_0
#define IS_IN_G(x, guide) IS_IN_G_(x, guide OOP_END)

// can probably generalize this to all transformations by adding an "args" argument so that the function is called func(OOP_IF(IS_PAREN(args)))(PASS_ARGS args, PASS_ARGS(args)), __VA_ARGS__)
#define G_JOIN_0(func, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, G_JOIN_NEXT)(func, (__VA_ARGS__), 1)
#define G_JOIN_1(func, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(ERASE_ARGS, G_JOIN_NEXT)(func, (__VA_ARGS__), 0)
#define G_JOIN_NEXT(func, vals, next) func vals G_JOIN_##next(func, 
#define G_JOIN_ G_JOIN_0
#define G_JOIN(func, guide) G_JOIN_(func, guide OOP_END)

// helper for reverse namespace sequence
#define OOP_GET_ACCESS(seq_out, class, name) OOP_IF(EQUAL(name, class__))(class__->seq_out, name.seq_out)

// reverse a sequence, but does much more
#define S_REV_0(seq_out, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(seq_out ERASE_ARGS, S_REV_NEXT)(seq_out, 1, __VA_ARGS__)
#define S_REV_1(seq_out, ...) OOP_IF(IS_OOP_END(T_INSPECT_0(__VA_ARGS__)))(seq_out ERASE_ARGS, S_REV_NEXT)(seq_out, 0, __VA_ARGS__)
#define S_REV_NEXT(seq_out, next, ...) S_REV_##next(OOP_GET_ACCESS(seq_out, __VA_ARGS__), 
#define S_REV_ S_REV_0
#define S_REV__(guide) S_REV_( , guide OOP_END)
//#define S_REV(seq) OOP_IF(S_IS_EMPTY())(., S_REV__(S_TO_G(seq)))
#define S_REV(seq) OOP_IF(S_IS_EMPTY(seq))(., S_REV__(S_TO_G(seq)))
