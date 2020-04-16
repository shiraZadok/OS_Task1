#include <syslog.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int subtask3(){
    //creating a new process 
    pid_t pid = fork();
    if(pid==0){

     //this is the child
    //chmod to root
        chdir("/");

        //moving the new child we created to a new session
        //so when the parent will be closed- it won't effect it
        setsid();

        printf("The new daemon process is starting\n");

        //close output channels 
        close(STDERR_FILENO);
        close(STDIN_FILENO);
        close(STDOUT_FILENO);

        //open log
        openlog ("newdaemon", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "Hi, I'm a new daemon\n");
        usleep(3000000);
        syslog(LOG_NOTICE, "Still working, please do not interrupt\n");
        usleep(3000000);
        syslog(LOG_NOTICE, "Now I'm done.. Carry on.\n");
        usleep(3000000);
    }
    else
        printf("Daemon PID %d\n",pid);
    
    return 0;
    
}

int main(){
    subtask3();
    return 0;
}
