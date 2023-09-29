/* tuple access */
#define T_AT_0(_0, ...) _0
#define T_AT_1(_0,_1,...) _1
#define T_AT_2(_0,_1,_2,...) _2
#define T_AT_3(_0,_1,_2,_3,...) _3
#define T_AT_4(_0,_1,_2,_3,_4,...) _4
#define T_AT_5(_0,_1,_2,_3,_4,_5,...) _5
#define T_AT_6(_0,_1,_2,_3,_4,_5,_6,...) _6
#define T_AT_7(_0,_1,_2,_3,_4,_5,_6,_7,...) _7
#define T_AT_8(_0,_1,_2,_3,_4,_5,_6,_8,...) _8
#define T_AT_9(_0,_1,_2,_3,_4,_5,_6,_9,...) _9
#define T_AT_10(_0,_1,_2,_3,_4,_5,_6,_10,...) _10
#define T_INSPECT_0(...) T_AT_0(__VA_ARGS__, UNUSED)
#define T_INSPECT_1(...) T_AT_1(__VA_ARGS__, UNUSED)
#define T_INSPECT_2(...) T_AT_2(__VA_ARGS__, UNUSED)
#define T_INSPECT_3(...) T_AT_3(__VA_ARGS__, UNUSED)
#define T_INSPECT_4(...) T_AT_4(__VA_ARGS__, UNUSED)
#define T_INSPECT_5(...) T_AT_5(__VA_ARGS__, UNUSED)
#define T_INSPECT_6(...) T_AT_6(__VA_ARGS__, UNUSED)
#define T_INSPECT_7(...) T_AT_7(__VA_ARGS__, UNUSED)
#define T_INSPECT_8(...) T_AT_8(__VA_ARGS__, UNUSED)
#define T_INSPECT_9(...) T_AT_9(__VA_ARGS__, UNUSED)
#define T_INSPECT_10(...) T_AT_10(__VA_ARGS__, UNUSED)

/* VARIADICS */
#define VARIADIC_SIZE(...) VARIADIC_SIZE_(__VA_ARGS__, _64, _63, _62, _61, _60, _59, _58, _57, _56, _55, _54, _53, _51, _52, _50, _49, _48, _47, _46, _45, _44, _43, _42, _41, _40, _39, _38, _37, _36, _35, _34, _33, _32, _31, _30, _29, _28, _27, _26, _25, _24, _23, _22, _21, _20, _19, _18, _17, _16, _15, _14, _13, _12, _11, _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, _0, UNUSED)
#define VARIADIC_SIZE_(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, size, ...) size

#define VARIADIC_SIZE_T(...) VARIADIC_SIZE_(__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 51, 52, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, UNUSED)
#define VARIADIC_SIZE_(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, size, ...) size

/* tuple conversion DOES NOT CURRENTLY WORK FOR 0 arguments. CURRENTLY, must pass at least one argument */
#define T2S_1(_1) (_1)
#define T2S_2(_1, _2) (_1)(_2)
#define T2S_3(_1, _2, _3) (_1)(_2)(_3)
#define T2S_4(_1, _2, _3, _4) (_1)(_2)(_3)(_4)
#define T2S_5(_1, _2, _3, _4, _5) (_1)(_2)(_3)(_4)(_5)
#define T2S_6(_1, _2, _3, _4, _5, _6) (_1)(_2)(_3)(_4)(_5)(_6)
#define T2S_7(_1, _2, _3, _4, _5, _6, _7) (_1)(_2)(_3)(_4)(_5)(_6)(_7)
#define T2S_8(_1, _2, _3, _4, _5, _6, _7, _8) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)
#define T2S_9(_1, _2, _3, _4, _5, _6, _7, _8, _9) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)
#define T2S_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)
#define T2S_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)
#define T2S_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)
#define T2S_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)
#define T2S_14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)
#define T2S_15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)
#define T2S_16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)
#define T2S_17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)
#define T2S_18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)
#define T2S_19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)
#define T2S_20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)
#define T2S_21(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)
#define T2S_22(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)
#define T2S_23(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)
#define T2S_24(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)
#define T2S_25(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)
#define T2S_26(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)
#define T2S_27(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)
#define T2S_28(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)
#define T2S_29(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)
#define T2S_30(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)
#define T2S_31(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)
#define T2S_32(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)
#define T2S_33(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)
#define T2S_34(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)
#define T2S_35(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)
#define T2S_36(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)
#define T2S_37(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)
#define T2S_38(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)
#define T2S_39(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)
#define T2S_40(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)
#define T2S_41(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)
#define T2S_42(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)
#define T2S_43(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)
#define T2S_44(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)
#define T2S_45(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)
#define T2S_46(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)
#define T2S_47(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)
#define T2S_48(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)
#define T2S_49(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)
#define T2S_50(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)
#define T2S_51(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)
#define T2S_52(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)
#define T2S_53(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)
#define T2S_54(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)(_54)
#define T2S_55(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)(_54)(_55)
#define T2S_56(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)(_54)(_55)(_56)
#define T2S_57(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)(_54)(_55)(_56)(_57)
#define T2S_58(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)(_54)(_55)(_56)(_57)(_58)
#define T2S_59(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)(_54)(_55)(_56)(_57)(_58)(_59)
#define T2S_60(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)(_54)(_55)(_56)(_57)(_58)(_59)(_60)
#define T2S_61(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)(_54)(_55)(_56)(_57)(_58)(_59)(_60)(_61)
#define T2S_62(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)(_54)(_55)(_56)(_57)(_58)(_59)(_60)(_61)(_62)
#define T2S_63(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)(_54)(_55)(_56)(_57)(_58)(_59)(_60)(_61)(_62)(_63)
#define T2S_64(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64) (_1)(_2)(_3)(_4)(_5)(_6)(_7)(_8)(_9)(_10)(_11)(_12)(_13)(_14)(_15)(_16)(_17)(_18)(_19)(_20)(_21)(_22)(_23)(_24)(_25)(_26)(_27)(_28)(_29)(_30)(_31)(_32)(_33)(_34)(_35)(_36)(_37)(_38)(_39)(_40)(_41)(_42)(_43)(_44)(_45)(_46)(_47)(_48)(_49)(_50)(_51)(_52)(_53)(_54)(_55)(_56)(_57)(_58)(_59)(_60)(_61)(_62)(_63)(_64)
#define T_TO_S(...) CAT(T2S, VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__)