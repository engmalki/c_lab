#include <stdio.h>
#include <string.h>
typedef struct 
{
    void (*start) (void);
    void (*stop) (void);

}CommandHandler;
void StartFunction()
{
    printf ("System Started.\n");
}
void StopFunction ()
{
    printf ("System Stopped.\n");
}
void executeCommand(CommandHandler *handler, const char * command )
{
    if (command == NULL || handler == NULL) return;
    else if (strcmp (command , "start") == 0 && handler -> start )
        handler -> start();
    else if (strcmp (command, "stop") == 0 && handler ->stop)
        handler-> stop();
    else
        printf("Unknown Command %s\n", command );
    
}
int main ()
{
    CommandHandler CmdHnd1 = {
        .start = StartFunction,
        .stop = StopFunction,
    };
    executeCommand(&CmdHnd1, "start"); 
    printf (". . . \n");
    executeCommand(&CmdHnd1, "123");
    printf (". . . \n");
    executeCommand(&CmdHnd1, "stop");
 
    return 0;
}