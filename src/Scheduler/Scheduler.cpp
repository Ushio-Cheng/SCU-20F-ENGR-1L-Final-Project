#include "Scheduler.hpp"

void Scheduler::schedulerCycle(){
    triggeredTasksCount = 0;
    for(unsigned short i = 0; i<scheduledTasksCount; i++) {
        Task* task = scheduledTasks[i];
        if (task->trigger()) {
            triggeredTasksIndex[triggeredTasksCount] = i;
            triggeredTasksCount++;
        }
    }

    for (unsigned short i = 0; i < triggeredTasksCount; i++) {
        Task* task = scheduledTasks[triggeredTasksIndex[i]];
        task->exec();
    }
    
    // Remove all triggered tasks from task pool
    unsigned short writePointer = 0;
    unsigned short triggeredTasksIndexListPointer = 0;
    for (unsigned short readPointer = 0; readPointer < scheduledTasksCount; readPointer++) {
        if (triggeredTasksIndexListPointer>=triggeredTasksCount) break;
        if (readPointer==triggeredTasksIndex[triggeredTasksIndexListPointer]) continue;
        scheduledTasks[writePointer] = scheduledTasks[readPointer];
    }
    scheduledTasksCount -= triggeredTasksCount;
}

Scheduler::Scheduler(){}

Scheduler::~Scheduler(){}

void Scheduler::scheduleGlobalEvent(Task* task){
    if (scheduledTasksCount>=MAX_SCHEDULER_TASK)
        return;
    scheduledTasks[scheduledTasksCount] = task;
    scheduledTasksCount++;
}
