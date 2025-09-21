#include <stdio.h>
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
void StartFunction()
{
    printf("System Started\n");
}
void StopFunciton()
{
    printf("System Stoped\n");
}
void PauseFunction()
{
    printf("System Paused \n");
}
void ResumeFunction()
{
    printf("System Resumed \n");
}
void StatusFunction()
{
    printf("Status: System is running normally\n");
}
void ResetFunction()
{
    printf("System Reset\n");
}
void ShutdownFunction() 
{
    printf("System Shutdown\n");
}
void RebootFunction()
{
    printf("System Rebooting\n");
}
void HelpFunciton ()
{
    printf("Command Help Excuted \n");
}

//Define  the execute Command function
void executeCommand(CommandHandler* cmdHndlr, char* command)
{
    if ((cmdHndlr == NULL) && (command == NULL)) return ;
    else if ((command == "start") && (cmdHndlr -> start))
        cmdHndlr->start();
    else if ((command == "stop") && (cmdHndlr -> stop ))
        cmdHndlr->stop();
    else if ((command == "pause") && (cmdHndlr ->pause ))
        cmdHndlr->pause();
    else if ((command == "resume") && (cmdHndlr -> resume))
        cmdHndlr-> resume();
    else if ((command == "status") && (cmdHndlr -> status))
        cmdHndlr-> status();
    else if ((command == "reset") && (cmdHndlr -> reset))
        cmdHndlr->reset();
    else if ((command == "shutdown") && (cmdHndlr -> shutdown))
        cmdHndlr->shutdown();
    else if ((command == "reboot") && (cmdHndlr -> reboot))
        cmdHndlr->reboot();
    else if ((command == "help") && (cmdHndlr -> help))
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
