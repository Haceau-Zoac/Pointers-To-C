typedef char* va_list;

#define va_start(arg_ptr, arg) arg_ptr = (char*)&arg + sizeof(arg)
#define va_arg(arg_ptr, type) *((tyoe*)arg_ptr)++
#define va_end(arg_ptr)
