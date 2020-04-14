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

int child1(){
    println("child_thred_1");
}

int child2(){
    println("child_thred_2");
}

int subtask2(){
    //cloneing the process
    int ans1=clone(child1,child_stack+STACK_SIZE,CLONE_PARENT,0);
    int ans2=clone(child2,child_stack+STACK_SIZE,CLONE_PARENT,0);

    printf("clone ans1 = %d\n", ans1);
    printf("clone ans2 = %d\n", ans2);


    println("parent");

    return 0;
}

int main(){
    subtask2();
    return 0;
}