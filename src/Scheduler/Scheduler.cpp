#include "Scheduler.hpp"

// A cycle of scheduler
void Scheduler::schedulerCycle()
{
    // Step 1: Check all trigger
    triggeredTasksCount = 0;
    for (unsigned short i = 0; i < scheduledTasksCount; i++)
    {
        Task *task = scheduledTasks[i];
        if (task->checkTrigger())
        {
            triggeredTasksIndex[triggeredTasksCount] = i;
            triggeredTasksCount++;
        }
    }

    // Step 2: execute task that is ready
    for (unsigned short i = 0; i < triggeredTasksCount; i++)
    {
        Task *task = scheduledTasks[triggeredTasksIndex[i]];
        task->execute();
    }

    // Step3: Remove all executed tasks from task pool
    unsigned short writePointer = 0;
    unsigned short triggeredTasksIndexListPointer = 0;
    for (unsigned short readPointer = 0; readPointer < scheduledTasksCount; readPointer++)
    {
        if (triggeredTasksIndexListPointer >= triggeredTasksCount)
            break;
        if (readPointer == triggeredTasksIndex[triggeredTasksIndexListPointer])
            continue;
        scheduledTasks[writePointer] = scheduledTasks[readPointer];
    }
    scheduledTasksCount -= triggeredTasksCount;
}

void Scheduler::scheduleGlobalEvent(Task *task)
{
    if (scheduledTasksCount >= MAX_SCHEDULER_TASK)
        return;
    scheduledTasks[scheduledTasksCount] = task;
    scheduledTasksCount++;
}

Scheduler *G_MAIN_SCHEDULER;

Scheduler *getGlobalScheduler()
{
    return G_MAIN_SCHEDULER;
}

void initScheduler()
{
    G_MAIN_SCHEDULER = new Scheduler();
}