#include <stdio.h>
#include <string.h>

#define MAX_HISTORY             100
#define MAX_COMMAND_LENGTH      100
//Define the structure with function pointers
typedef struct {
                void (* start)      ();
                void (* stop)       ();
                void (* pause)      ();
                void (* resume)     ();
                void (* status)     ();
                void (* reset)      ();
                void (* shutdown)   ();
                void (* reboot)     ();
                void (* help)       ();

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

//Define  the execute Command function
void executeCommand(CommandHandler* cmdHndlr, char* command)
{
    if ((cmdHndlr == NULL) && (command == NULL)) return ;
    else if ((strcmp(command, "start") ==0) && (cmdHndlr -> start))
        cmdHndlr->start();
    else if ((strcmp(command, "stop") ==0) && (cmdHndlr -> stop ))
        cmdHndlr->stop();
    else if ((strcmp(command, "pause") ==0) && (cmdHndlr ->pause ))
        cmdHndlr->pause();
    else if ((strcmp(command, "resume") ==0) && (cmdHndlr -> resume))
        cmdHndlr-> resume();
    else if ((strcmp(command, "status") ==0) && (cmdHndlr -> status))
        cmdHndlr-> status();
    else if ((strcmp(command, "reset") ==0) && (cmdHndlr -> reset))
        cmdHndlr->reset();
    else if ((strcmp(command, "shutdown") ==0) && (cmdHndlr -> shutdown))
        cmdHndlr->shutdown();
    else if ((strcmp(command, "reboot") ==0) && (cmdHndlr -> reboot))
        cmdHndlr->reboot();
    else if ((strcmp(command, "help") ==0) && (cmdHndlr -> help))
        cmdHndlr->help();
    else if (strcmp(command,"history")==0)
    //This will handle in the main
    return ;
    else 
        printf ("Unknwon Command: %s\n",command);

}

// Main function
int main ()
{
    short   history_count = 0;
    char    history [MAX_HISTORY][MAX_COMMAND_LENGTH];
    CommandHandler cmdHndlr1=
    {
        .start = StartFunction,
        .stop = StopFunciton,
        .pause = PauseFunction, 
        .resume = ResumeFunction,
        .status = StatusFunction,
        .reset = ResetFunction,
        .shutdown = ShutdownFunction,
        .reboot = RebootFunction,
        .help = HelpFunciton
    };
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
            continue ;
        }
        
        executeCommand(&cmdHndlr1, input);
    }    
    return 0;
}

