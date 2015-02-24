#define define_list(type) \
    struct _list_##type;\
    typedef struct {\
        int (*describe) (const struct _list_##type *);\
    } _list_functions_##type;\
    typedef struct {\
        type data;\
        struct _list_##type *next;\
    } _list_element_##type;\
    typedef struct _list_##type {\
        size_t size;\
        list_element_##type* first;\
        list_element_##type* last;\
        _list_functions_##type *_functions;\
    } List_##type;\
    int describe_##type(const List_##type* list);\
    int describe_##type(const List_##type* list) {\
        printf("Hello I am of type: "##type"\n");\
    }\
    _list_functions_##type _list_funcs_##type = {\
        &describe_##type\
    };\
    List_##type* new_list_##type() {\
        List_##type* res = (List_##type*) malloc(sizeof(List_##type));\
        res->size = 0;\
        res->first = res->last = NULL;\
        return res;\
    }

#define List(type) \
    List_##type

#define new_list(type) \
    new_list_##type()
