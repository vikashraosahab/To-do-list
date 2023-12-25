/*
********* CREATE A PROGRAM THAT CREATE TO-DO LIST *************
******************** FEATURES *********************************
****** WEEKS TO-DO LIST WITH THEIR RESPECTIVE NAMES AND ASSGIN TAKS *********
****** STOP MAKE TO-DO LIST WHEN IT EN-COUNTER WITH DONE JUMP TO OTHER DAY TO-DO TASK ***********
****** 
*/

// PREPROCESSOR DIRECTIVE HEADER FILE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MAIN () FUNCTION OF THE PROGRAM
int main (int argv, char *argc[]) {
  // VARIABLES DECLARATIONS 
  int flag,list_size,task_lists;
  char weekdayname[10];
  char weekday[10];
  char *to_do_list[50];
  char choice[5];
  // FILE CREATE
  FILE *STORAGE_TASK = fopen ("Notes.text","a+");

  if (STORAGE_TASK != NULL) {
     flag = 1;

     while (flag) {
       
       begin : printf("\nLet's create To-do lists ......\n");
       fprintf(STORAGE_TASK,"%s","TO-DO LIST -------\n");
       printf("Enter weekday ...... \n");
       scanf("%s",&weekday);
       fprintf(STORAGE_TASK,"WEEK DAY IS - %d\n",weekday);
       printf("Enter week day name ..........\n");
       getchar();
       scanf("%[^\n]",&weekdayname);
       fprintf(STORAGE_TASK,"TO-DO'S OF %s\n",weekdayname);
       
       // DYNAMIC MEMORY ALLOCATION
       printf("Enter TO-DO LIST TASK ----- \n");
       for (int i = 0; i < 5; i++) {
        to_do_list[i] = (char *) malloc (50 * sizeof(char));
          getchar();
         scanf("%40[^\n]s",to_do_list[i]);
       }
       for (int j = 0; j < 5; j++) {
         fprintf(STORAGE_TASK,"o %s \n",to_do_list[j]);
       }
       getchar();
       printf("Close TO-DO LIST TASK ----\n");
       printf("enter 'yes' for exit and 'no' for exit...\n");
       scanf ("%s",&choice);
       if (strcmp (choice,"yes") == 0) {
         goto exit;
       }
       else {
        goto begin;
       }
     }
  }
  else {
    printf("SORRY YOUR FILE IS NOT OPENNED\n");
  }

  exit : printf("To-do is closed now!");
  return 0; // IT INDICATE THAT PROGRAM EXECUTE SUCCESSFULLY
}