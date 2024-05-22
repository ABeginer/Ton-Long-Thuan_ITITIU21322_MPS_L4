#include "stm32f1xx_hal.h"
#include "scheduler.h"
#include "main.h"

// Function prototypes for task functions
void Task_LED_RED_On(void);

int main(void) {
    // Initialize the scheduler
    SCH_Init();

    // Add tasks to the scheduler
    SCH_Add_Task(Task_LED_RED_On, 0, 500); // Turn on LED_RED every 0.5 seconds

    // Start main loop
    while (1) {
        // Dispatch tasks
        SCH_Dispatch_Tasks();
        // Other main program code here
    }
}

// Task function to turn on LED_RED on PA1
void Task_LED_RED_On(void) {
    // Turn on LED_RED
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
}
