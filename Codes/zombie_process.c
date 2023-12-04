#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int pid = fork() ;
    if(pid == 0){
        for (int i = 0; i < 2; i++)
        {
            printf("I am child.\n") ;
        }
     }
        else if(pid > 0){
            printf("I am parent.\n") ;
            while(1) ;
        }
        else{
        printf("Pid failed.\n") ;
    }
    return 0 ;
}