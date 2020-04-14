#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void println(const char *text){
    for (int i=0;i<20;i++){
        printf("Hey there! I am using processes : %s\n", text);
        usleep(1000000);
    }
}

int subtask1(){
    //creat child
    pid_t pid = fork();
    if (pid==0){

        //this is the child
        //create the grandchild

        pid_t pid=fork();

        if(pid==0){
            //this is the grandchild
            println("grand child"); 

            // char* args[2]= {"./GreatFile",NULL};
            // execvp(args[0],args);
        }
        else
            println("child");
    }
    else
        println("parent");


return 0;
}

int main(){
    subtask1();
    return 0;
}