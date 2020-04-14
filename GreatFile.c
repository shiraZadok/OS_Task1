#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//an helping function for forking
void println(const char *text){
    int i;
    for (i=0;i<20;i++){
        printf("Hey there! I am using processes :) %s\n", text);
        usleep(1000000);
    }
}

int main(){
    println("GreatFile");
}