/**
 * NOTE: in templates, you normally cannot directly #include <oopc.h> since many <oopc.h> macros 
 * depend on what the inputs in the top-level macro are. If #include <oopc.h> is present, the 
 * macros must escape <oopc.h> macros
 */ 

#define TEMPLATE(name, ...) TEMPLATE_##name(__VA_ARGS__)
#define TEMPLATE_IMPLEMENTATION(name, ...) TEMPLATE_IMPLEMENTATION_##name(__VA_ARGS__)

# ifndef OOP_MEMBER_void 
    # define OOP_MEMBER_void( x ) x 
#endif 
#ifndef OOP_MEMBER_pvoid 
 	# define OOP_MEMBER_pvoid( x ) x 
#endif 
