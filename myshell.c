#include<stdlib.h>
#include<stdio.h>
#include<string.h>
 /*don’t test program with more than this many tokens for input */
 #define MAXARGS 32
 /* structure to hold input data */
 struct PARAM{
 char *inputRedirect;             /* file name or NULL */
 char *outputRedirect;            /* file name or NULL */
 int background;                  /* either 0 (false) or 1 (true) */
 int  argumentCount;              /* number of tokens in argument vector */
 char *argumentVector[MAXARGS];   /* array of strings */
         };
typedef struct PARAM Param_t;

void printParams(Param_t * param);
int main(int argc, char **argv)
{
/* a typedef so we don’t need to use "struct PARAM" all the time */

Param_t arguments;
    char prompt1[100];
    char *prompt = prompt1;
    char exit1[] = "exit\n";
    char debug[] = "-debug";
    char *q;
    char *tempString;
    q = exit1;
    int result=3;
    int i=0;

    printf("$$$ ");
    fgets(prompt,sizeof(prompt)*10,stdin);
    
      //arguments.argumentVector[0]="fuckoffbitch";
    
      arguments.argumentCount=0;
     // printf("argument count:%u\n ",arguments.argumentCount);
      //printf("You passed the part where you printed the argument count\n ");
      
    while(strcmp(prompt,q) != 0)
    {
    tempString = strtok(prompt," ");
    
    arguments.argumentVector[arguments.argumentCount]=tempString;
    printf("argument vector:--- %s--- count is: %u\n",arguments.argumentVector[arguments.argumentCount],arguments.argumentCount);
    while (tempString != NULL){
        printf("Token %u is :%s     ",arguments.argumentCount,tempString);
            arguments.argumentCount=arguments.argumentCount+1;
            arguments.argumentVector[arguments.argumentCount]=tempString;
            if(tempString[0] == 62 && strlen(tempString) > 1)
	   {
		
	arguments.outputRedirect = tempString+1;
      printf("%s will be the output file name",arguments.outputRedirect);
      }
      if(tempString[0] == 60 && strlen(tempString) > 1)
	   {
		
	arguments.inputRedirect = tempString+1;
      printf("%s will be the input file name",arguments.inputRedirect);
      }
            
            tempString = strtok(NULL," ,\n");
            printf("arg vect & count is: %s , %u\n",arguments.argumentVector[arguments.argumentCount],arguments.argumentCount);  
      
      if (arguments.argumentCount==32){printf("too many arguments"); break;}
        }
     /// if (arguments.background){
      //printParams(Param_t arguments);}
      
         arguments.argumentCount=0;
         //if (strcmp(arguments.argumentVector[1],debug){printParams(Param_t * arguments);}
        printf("\n$$$ ");
        fgets(prompt,sizeof(prompt)*10,stdin);
    }
 printf("Auf Wiedersehen!\n");
    return 0;
}
void printParams(Param_t * param)
{
int i;
printf ("InputRedirect: [%s]\n",
 (param->inputRedirect != NULL) ? param->inputRedirect:"NULL");
printf ("OutputRedirect: [%s]\n",
 (param->outputRedirect != NULL) ? param->outputRedirect:"NULL");
printf ("Background: [%d]\n", param->background);
printf ("ArgumentCount: [%d]\n", param->argumentCount);
for (i = 0; i < param->argumentCount; i++)
printf("ArgumentVector[%2d]: [%s]\n", i, param->argumentVector[i]);
}
