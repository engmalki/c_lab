#include <stdio.h>
#include <string.h>

#define MAX_HISTORY             100
#define MAX_COMMAND_LENGTH      100
//Define the structure with function pointers
typedef struct { 
                    char * command;
                    void (* Function)      ();
                
} CommandHandler;

//Define the actual functions
void StartFunction()    {   printf("System Started\n"); }
void StopFunciton()     {   printf("System Stoped\n");}
void PauseFunction()    {   printf("System Paused \n");}
void ResumeFunction()   {   printf("System Resumed \n");}
void StatusFunction()   {   printf("Status: System is running normally\n");}
void ResetFunction()    {   printf("System Reset\n"); }
void ShutdownFunction() {   printf("System Shutdown\n");}
void RebootFunction()   {   printf("System Rebooting\n");}
void HelpFunciton ()    
{   
    printf("  Available Commands:\n");
    printf("  start     -   Start the system\n");
    printf("  stop      -   Stop the system\n");
    printf("  pause     -   Pause the system\n");
    printf("  resume    -   Resume the system\n");   
    printf("  status    -   Show system status\n");
    printf("  reset     -   Reset the system\n");
    printf("  shutdown  -   Shutdown the system\n");
    printf("  reboot    -   Rebot the system\n");
    printf("  help      -   Show the help message\n");
    printf("  history   -   Show the command history\n");
    printf("  exit      -   Exit the program\n");
}
//Command Handler that contains the Table of commands with their corresponding functions 
CommandHandler cmdHndlr1[]={
        {"start",   StartFunction},
        {"stop",    StopFunciton},
        {"pause",   PauseFunction}, 
        {"resume",  ResumeFunction},
        {"status",  StatusFunction},
        {"reset",   ResetFunction},
        {"shutdown",ShutdownFunction},
        {"reboot",  RebootFunction},
        {"help",    HelpFunciton}        
    };
const short NumOfCmds = sizeof(cmdHndlr1)/ (sizeof(cmdHndlr1[0]));

//Define the execute Command function
void executeCommand(char* input)
{
    for (short i=0; i < NumOfCmds; i++)
    {
        if (strcmp (input, cmdHndlr1[i].command)==0)
        {
            cmdHndlr1[i].Function();
            
            return ;// Command found and executed no need to continue with the loop
        }
    }
    printf ("Unknown command:%s.\n",input);
}

// Main function
int main ()
{
    short   history_count = 0;
    char    history [MAX_HISTORY][MAX_COMMAND_LENGTH];
   
    char input[MAX_COMMAND_LENGTH];
    
    printf("Type 'help' to see available commands.\n");
    while (1)
    {
        printf("\n>");
        scanf("%s", input);
        if (history_count < MAX_HISTORY)
        {
            strncpy(history[history_count],input,MAX_COMMAND_LENGTH-1);
            history[history_count][MAX_COMMAND_LENGTH-1]='\0';
            history_count++;
        }
        if (strcmp(input,"exit")==0)
        {
            printf("Exiting Program.\n");
            break;
        }
        else if(strcmp(input,"history")==0)
        {
            printf("Command History:\n");
            for (int i=0;i<history_count;i++)
            {
                printf("%d- %s\n",i+1,history[i]);
            }
            continue;// quite from the current loop as the history is requested, executeCommand will not called.
        }
        executeCommand(input);
    }    
    return 0;
}

