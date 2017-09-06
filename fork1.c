#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>


int main(void){

printf("I'm printed once!\n");
pid_t  pid = fork();
// Now there are two processes running one is parent and another child.
// and each process will print out the next line.
printf("You see this line twice!\nProcess ID is %i",pid);

}

