#include <stdio.h>
#include <unistd.h>  // For sleep()

// Define traffic light states
typedef enum TrafficLightState {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;

// Simulate timer delay (in seconds)
void wait(int seconds) {
    sleep(seconds);
}

// Display current state
void displayState(TrafficLightState state) {
    switch (state) {
        case RED:
            printf("State: RED\n");
            break;
        case GREEN:
            printf("State: GREEN\n");
            break;
        case YELLOW:
            printf("State: YELLOW\n");
            break;
    }
}

// FSM logic
int main() {
    TrafficLightState currentState = RED;

    while (1) {
        displayState(currentState);

        switch (currentState) {
            case RED:
                wait(5);  // RED for 5 seconds
                currentState = GREEN;
                break;
            case GREEN:
                wait(5);  // GREEN for 5 seconds
                currentState = YELLOW;
                break;
            case YELLOW:
                wait(2);  // YELLOW for 2 seconds
                currentState = RED;
                break;
        }
    }

    return 0;
}