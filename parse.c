/*parse.c by Jeffrey Murphy and Timothy Stewart*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parse.h"
#define MAXARGS 32
   char *debugptr = "-Debug";//debug pointer
   void printParams(Param_t * param);//prototype for printing and debugging the arguments

struct PARAM{
 char *inputRedirect;/* file name or NULL */
 char *outputRedirect;            /* file name or NULL */
 int  argumentCount;              /* number of tokens in argument vector */
 char *argumentVector[MAXARGS];
 };
 Param_t param;
 
            /*MALLOC FOR STRUCTURE*/
//Param_t param = malloc ( sizeof ( Param_t ) );
//if (param == NULL){
// printf("NO WAY JOSE");return;}

  //param->argumentCount = 0;//malloc(sizeof(int));
  //int i;
        //for(i = 0;i < MAXARGS;i++){
           //param->argumentVector = malloc(128 * sizeof(char));
            //}

//printf("This will parse the arguments sent by the file that the shell uses");
/* structure to hold input data */

void parse(char *prompt){//function to parse the arguments
  
  printf("you passed in this %s--",prompt);
  //printf("inputString was %s\n",inputString);
   printf("Prompt is :%s----",prompt);
   char *tempString;//=prompt;
   
   //tempString=*&prompt;
   int result=3;
   int leftarrow = 0;
   int rightarrow = 0;
 strcpy(tempString,prompt);
  printf("at least you made it past stringcopy\n");
  puts(tempString);
  // puts(prompt);
    int i=0;
    result = strlen(tempString);
    printf("stringlength of tempString was %i\n",result);
    strtok(prompt," \t");
 //  tempString = strtok(prompt," \t\n");
  //   printf("tempString was %s\n",tempString);
    //result = strlen(tempString);
    while (prompt != NULL){
       // while (prompt != NULL){
        param->argumentVector[i] = malloc(result * sizeof(char));
        if(prompt[0] == 62 && strlen(tempString) > 1)
	{
		prompt++;
		param->outputRedirect = prompt;
        strtok(NULL, " \n\t");
		continue;
	}

	//for <
        else if(prompt[0] == 60 && strlen(prompt) > 1)
	{
		prompt++;
		param->inputRedirect = prompt;
        strtok(NULL, " \n\t");
		continue;
	}
        else if(prompt[0] == 60 && strlen(prompt) == 1)
        {
            strtok(NULL, " \n\t");
            leftarrow = 1;
            continue;
        }
        else if(prompt[0] == 62 && strlen(prompt) == 1)
        {
            strtok(NULL, " \n\t");
            rightarrow = 1;
            continue;
        }
        if(rightarrow == 1)
        {
            param->outputRedirect = prompt;
            strtok(NULL, " \n\t");
            rightarrow = 0;
            continue;
        }
        else if(leftarrow == 1)
        {
            param->inputRedirect = prompt;
            strtok(NULL, " \n\t");
            leftarrow = 0;
            continue;
        }   
            //printf("tempString at line 87 was %s\n",tempString);
            strcpy (param->argumentVector[param->argumentCount],tempString);
            //printf("%s is the content of param.argumentVector[%i]\n",param.argumentVector[i],i);
            //printf("param.argumentVector[%i] was %s\n",i,param.argumentVector[i]);
            param->argumentCount++;i++;
            //printf("i is %i and param.argumentCount was %i\n",i,param.argumentCount);
            tempString = strtok(NULL," \n\t");
            if (tempString==NULL) break;
            //printf("tempString was %s\n",tempString);//printf("You got here\n");
        }
        for (i=0;i<param->argumentCount;i++)
        //printf("%s is the content of param.argumentVector[%i]\n",param.argumentVector[i],i);
        //printf("%i total params entered into structure fields.\n",param.argumentCount);
        i++;
        //printf("%s is the content of outputRedirect\n",param.outputRedirect);
        //printf("%s is the content of inputRedirect\n",param.inputRedirect);
    //result = strcmp(q,prompt);
    //printf("The string compare has returned %i as a result.\n", result);
    //printf("Your input has put you here.");
    //printf("This is what you said: \n\"%s\"\n",prompt);
    //printf("This is what q is though: \n\"%s\"\n",q);

//////////////////////////DEBUG PRINTOUT///////////////
//printParams(&param);
return ;
 }
 //freeParam(param);
//back to main
//}
