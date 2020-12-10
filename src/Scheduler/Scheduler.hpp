#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

/**
 * Scheduler Task
 * WARNING: each task should be finished in 100ms.
 */
class Task
{
public:
    Task(){
        this->trigger = []{return true;};
        this->exec = []{};
    }
    // Default full constructor to construct inline.
    Task(bool (*trigger)(),void (*exec)()){this->trigger = trigger; this->exec = exec;};
    

    /**
     * Trigger is a function pointer that accepts nothing and returns bool.
     * event would execute on true
     */
    bool (*trigger)();
    virtual bool checkTrigger(){
        trigger();
    }
    /**
     * Code to execute on event.
     */
    void (*exec)();
    virtual void execute(){
        exec();
    }
};

#define MAX_SCHEDULER_TASK 64

/**
 * Schedular
 * Only suppose to be instantiazed once in main class/global scope.
 */
class Scheduler
{
private:
    Task* scheduledTasks[MAX_SCHEDULER_TASK];
    int scheduledTasksCount = 0;
    int triggeredTasksIndex[MAX_SCHEDULER_TASK];
    int triggeredTasksCount = 0;
public:
    Scheduler();
    ~Scheduler();
    /**
     * Run event cycle.
     * WARNING: This method is only supposed to be called from main func.
     */
    void schedulerCycle();
    /**
     * Add a task.
     * @param task A Task to perform on trigger.
     * WARNING: Task must be dynamically allocated to be safe, 
     *          disposal would be handled by scheduler.
     */
    void scheduleGlobalEvent(Task* task);
};

#endif