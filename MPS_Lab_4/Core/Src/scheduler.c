#include "scheduler.h"

#define MAX_TASKS 10

typedef struct {
    void (*pFunction)();
    uint32_t delay;
    uint32_t period;
    uint32_t remaining_time;
    uint8_t active;
} Task_t;

Task_t tasks[MAX_TASKS];
uint8_t num_tasks = 0;

void SCH_Init(void) {
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].active = 0;
    }
}

void SCH_Update(void) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].active) {
            if (tasks[i].remaining_time == 0) {
                tasks[i].remaining_time = tasks[i].period;
            } else {
                tasks[i].remaining_time--;
            }
        }
    }
}

void SCH_Dispatch_Tasks(void) {
    for (int i = 0; i < num_tasks; i++) {
        if (tasks[i].active && tasks[i].remaining_time == 0) {
            tasks[i].pFunction();
            tasks[i].remaining_time = tasks[i].period;
        }
    }
}

uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
    if (num_tasks >= MAX_TASKS) {
        return 0;
    }
    tasks[num_tasks].pFunction = pFunction;
    tasks[num_tasks].delay = DELAY;
    tasks[num_tasks].period = PERIOD;
    tasks[num_tasks].remaining_time = DELAY;
    tasks[num_tasks].active = 1;
    num_tasks++;
    return num_tasks;
}

uint8_t SCH_Delete_Task(uint32_t taskID) {
    if (taskID > num_tasks || taskID == 0) {
        return 0;
    }
    for (int i = taskID - 1; i < num_tasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    num_tasks--;
    return 1;
}
