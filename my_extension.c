#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"

#define PHP_MY_EXTENSION_VERSION "1.0"
#define PHP_MY_EXTENSION_EXTNAME "my_extension"

extern zend_module_entry my_extension_module_entry;
#define phpext_my_extension_ptr &my_extension_module_entry

// declaration of a custom my_function()
PHP_FUNCTION(my_function);
PHP_FUNCTION(my_PI);
PHP_FUNCTION(my_add);

// list of custom PHP functions provided by this extension
// set {NULL, NULL, NULL} as the last record to mark the end of list
static function_entry my_functions[] = {
    PHP_FE(my_function, NULL)
    PHP_FE(my_PI, NULL)
    PHP_FE(my_add, NULL)
    {NULL, NULL, NULL}
};

// the following code creates an entry for the module and registers it with Zend.
zend_module_entry my_extension_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MY_EXTENSION_EXTNAME,
    my_functions,
    NULL, // name of the MINIT function or NULL if not applicable
    NULL, // name of the MSHUTDOWN function or NULL if not applicable
    NULL, // name of the RINIT function or NULL if not applicable
    NULL, // name of the RSHUTDOWN function or NULL if not applicable
    NULL, // name of the MINFO function or NULL if not applicable
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MY_EXTENSION_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(my_extension)

// implementation of a custom my_function()
PHP_FUNCTION(my_function)
{
    RETURN_STRING("This is my function", 1);
}

// implementation of my_PI()
PHP_FUNCTION(my_PI)
{
    double _pi = 3.1415926535;
    RETURN_DOUBLE(_pi);
}

// implementation of my_add()
PHP_FUNCTION(my_add)
{
    long a;
    double b;
    zend_bool return_long = 0;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ld|b", &a, &b, &return_long) == FAILURE) {
        RETURN_NULL();
    }

    if (return_long) {
        RETURN_LONG(a + b);
    } else {
        RETURN_DOUBLE(a + b);
    }
}
