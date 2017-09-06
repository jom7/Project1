
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
 /*don’t test program with more than this many tokens for input */
 #define MAXARGS 32
 /* structure to hold input data */
 struct PARAM{
 char *inputRedirect;/* file name or NULL */
 char *outputRedirect;            /* file name or NULL */
 int  argumentCount;              /* number of tokens in argument vector */
 char *argumentVector[MAXARGS]; /* array of strings */
         };
typedef struct PARAM Param_t;
Param_t param;
void printParams(Param_t * param);
char *debugptr = "-Debug";

int main(int argc, char *argv[])
{
/* a typedef so we don’t need to use "struct PARAM" all the time */


    char prompt1[100];
    char *prompt = prompt1;
    char exit1[] = "exit\n";
    char *q;
    char *tempString;
    q = exit1;
    int result=3;
    int i=0;
    int leftarrow = 0;
    int rightarrow = 0;

    printf("$$$ ");
    fgets(prompt,sizeof(prompt)*20,stdin);
    
      
    while(strcmp(prompt,q) != 0)
    {
    param.argumentCount=0;
    i=0;
    tempString = strtok(prompt," \t");
   // printf("tempString was %s\n",tempString);
    result = strlen(tempString);
        while (tempString != NULL){
        param.argumentVector[i] = malloc(result * sizeof(char));
        if(tempString[0] == 62 && strlen(tempString) > 1)
	{
		tempString++;
		param.outputRedirect = tempString;
        tempString = strtok(NULL, " \n\t");
		continue;
	}

	//for <
        else if(tempString[0] == 60 && strlen(tempString) > 1)
	{
		tempString++;
		param.inputRedirect = tempString;
        tempString = strtok(NULL, " \n\t");
		continue;
	}
        else if(tempString[0] == 60 && strlen(tempString) == 1)
        {
            tempString = strtok(NULL, " \n\t");
            leftarrow = 1;
            continue;
        }
        else if(tempString[0] == 62 && strlen(tempString) == 1)
        {
            tempString = strtok(NULL, " \n\t");
            rightarrow = 1;
            continue;
        }
        if(rightarrow == 1)
        {
            param.outputRedirect = tempString;
            tempString = strtok(NULL, " \n\t");
            rightarrow = 0;
            continue;
        }
        else if(leftarrow == 1)
        {
            param.inputRedirect = tempString;
            tempString = strtok(NULL, " \n\t");
            leftarrow = 0;
            continue;
        }   
            //printf("tempString at line 87 was %s\n",tempString);
            strcpy (param.argumentVector[param.argumentCount],tempString);
            //printf("%s is the content of param.argumentVector[%i]\n",param.argumentVector[i],i);
            //printf("param.argumentVector[%i] was %s\n",i,param.argumentVector[i]);
            param.argumentCount++;i++;
            //printf("i is %i and param.argumentCount was %i\n",i,param.argumentCount);
            tempString = strtok(NULL," \n\t");
            if (tempString==NULL) break;
            //printf("tempString was %s\n",tempString);//printf("You got here\n");
        }
        for (i=0;i<param.argumentCount;i++)
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
    
//        fgets(prompt, 10, stdin);// system("pause");system("pause");
//////////////////////////DEBUG PRINTOUT///////////////
printParams(&param);
    param.argumentCount=0;
        printf("$$$ ");
        fgets(prompt,sizeof(prompt)*20,stdin);
    }
    if (param.argumentCount>0){    
    for (i=0;i<param.argumentCount;i++)
    free(param.argumentVector[i]);}
    else printf("Auf Wiedersehen!\n");
    return 0;
}

void printParams(Param_t * param)
{
int i;
printf ("InputRedirect: [%s]\n",(param->inputRedirect != NULL)?param->inputRedirect:"NULL");
printf ("OutputRedirect: [%s]\n",(param->outputRedirect != NULL)?param->outputRedirect:"NULL");
printf ("ArgumentCount: [%d]\n", param->argumentCount);
for (i = 0; i < param->argumentCount; i++)printf("ArgumentVector[%2d]: [%s]\n", i, param->argumentVector[i]);
}
   
//printf ("param->argumentCount is %i",param->argumentCount);
