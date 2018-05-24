#include <stdio.h>
#include <stdlib.h>
#include <libunwind.h>

void show_backtrace3(void){
    char name[256];
    unw_cursor_t cursor; unw_context_t uc;

    unw_getcontext(&uc);
    unw_init_local(&cursor, &uc);
}

void show_backtrace2(){
    void *array[10];
    size_t size;
    char **strings;
    int i;

    size = backtrace(array, 10);
    strings = backtrace_symbols((void * const *)array, size);

    for(i=0; i<size; i++){
        printf("%s\n", strings[i]);
    }

    free(strings);
}

void show_backtrace1(){
    // get current address
    void *p = __builtin_return_address(0);
    printf("0x%x\n", p);

    // get callee address
    p = __builtin_return_address(1);
    printf("0x%x\n", p);
}

void dummy_function2(){
    // here will call our back_trace function to
    // display the back_trace
    show_backtrace2();
}

void dummy_function1(){
    dummy_function2();
}

int main(int argc, char **argv){

    dummy_function1();

}
