#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

void (*hello_message)(const char *);

//a boolean function to represent whethere a library was created or not
bool init_lib(){
    //a pointer to the file
    void *hdl = dlopen("./libHello.so",RTLD_LAZY);
    if(hdl==NULL)
        return false;
    //a pointer function
    hello_message= (void(*)(const char *))dlsym(hdl,"hello_message");
    if (hello_message==NULL)
        return false;
    return true;

}

int main(){
    //using our function
    if(init_lib())
        hello_message("Ariel");
    else
        printf("Library wasn't loaded \n");
    return 0;
    
}
