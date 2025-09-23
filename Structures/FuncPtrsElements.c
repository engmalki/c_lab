#include <stdio.h>
#include <string.h>
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
    else 
        printf ("Unknwon Command: %s\n",command);

}

// Main function
int main ()
{
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
    // Simulate comman
    executeCommand(&cmdHndlr1,"start");
    executeCommand(&cmdHndlr1,"stop");
    executeCommand(&cmdHndlr1,"pause");
    executeCommand(&cmdHndlr1,"resume");
    executeCommand(&cmdHndlr1,"status");
    executeCommand(&cmdHndlr1,"reset");
    executeCommand(&cmdHndlr1,"shutdown");
    executeCommand(&cmdHndlr1,"reboot");
    executeCommand(&cmdHndlr1,"help");
    executeCommand(&cmdHndlr1,"123");
    printf ("Program Finished \n");
    return 0;
}
