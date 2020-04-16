#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 1000

char child_stack[STACK_SIZE+1];

//an helping function for cloneing
void println(const char *text){
    for (int i=0;i<CYCLES;i++){
        printf("Hey there! I am using processes : %s\n", text);
        usleep(1000000);
    }
}

int t_clone(void * input){
    char* args[]= {"./clone",NULL};
    execvp(args[0],args);
}

int t_daemon(void * input){
    char* args[]= {"./daemon",NULL};
    execvp(args[0],args);
}


int main(){
    int result2 = clone(t_daemon,child_stack+STACK_SIZE,CLONE_PARENT,0);
    printf("clone result2 = %d\n", result2);
    
    pid_t pid1 = fork();
    printf("pid is: %d",pid1);
    if(pid1==0) {
        char* args[] = {"./fork",NULL};
        int result1 = clone(t_clone,child_stack+STACK_SIZE,CLONE_PARENT,0);
        printf("clone result1 = %d\n", result1);
        execvp(args[0],args);
    }

    else{
        println("parent");
    }

    return 0;
}
