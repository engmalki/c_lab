#include <stdio.h>
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

int main ()
{
    CommandHandler CmdHnd1 = {
        .start = StartFunction,
        .stop = StopFunction,
    };
    
    CmdHnd1.start();
    printf (". . . \n");
    CmdHnd1.stop();
 
    return 0;
}