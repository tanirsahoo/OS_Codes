#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	char* command="ls";
	char* argument_list[]={"ls","-l",NULL};
	printf("Before calling execvp()\n");
	printf("Creating another process using fork()..\n");

	if(fork()==0){
		int status_code = execvp(command, argument_list);
		if(status_code==-1){
			printf("Process did not terminate correctly\n");
			exit(1);
		}
	}
	else{
		printf("This line will be printed for parent");
	}
	return 0;
}