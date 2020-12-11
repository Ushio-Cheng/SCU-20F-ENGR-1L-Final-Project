#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

/**
 * Scheduler Task
 * WARNING: each task should be finished in 100ms.
 * Task is originally designed to accept function pointers that is created inline
 *     by using lambda expression. However, since lambda expression capature list
 *     would make it fail to convert to function pointer, the only way to access
 *     private member of other class would be to write a child class for each task.
 */
class Task
{
    /**
     * Trigger is a function pointer that accepts nothing and returns bool.
     * event would execute on true
     */
    bool (*trigger)();
    /**
     * Function to execute on event.
     */
    void (*exec)();

public:
    /**
     * Default constructor that is intended to be used in extended classes.
     */
    Task()
    {
        Task([] { return true; }, [] {});
    }
    /** 
     * Full constructor to allow construct inline with lambda expression.
     */
    Task(bool (*trigger)(), void (*exec)())
    {
        this->trigger = trigger;
        this->exec = exec;
    };

    /*
     * Virtual functions to be overrided by sub-classes
     */

    /**
     * Check Trigger Condition, scheduler would call this method to see if it is ready
     * If this method return true, scheduler would call this->execute()
     */
    virtual bool checkTrigger()
    {
        return trigger();
    }
    /**
     * Code to execute when conditions are met
     */
    virtual void execute()
    {
        exec();
    }
};

/**
 * MAX amount of tasks in scheduler at a time
 * Mostly just an arbitary limit. 
 * However, when more than one task is triggered, the execution of all triggered task would add up.
 */
#define MAX_SCHEDULER_TASK 64

/**
 * Schedular
 * Only suppose to be instantiazed once.
 */
class Scheduler
{
private:
    Task *scheduledTasks[MAX_SCHEDULER_TASK];
    unsigned int scheduledTasksCount = 0;
    unsigned int triggeredTasksIndex[MAX_SCHEDULER_TASK];
    unsigned int triggeredTasksCount = 0;

public:
    Scheduler() {}
    ~Scheduler() {}
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
     * CAVEAT: this would not give any error (since arduino cannot log error anyway) if MAX_SCHEDULER_TASK is reached
     */
    void scheduleGlobalEvent(Task *task);
};

/**
 * A function to get Global Scheduler Pointer
 * @return pointer to Global Scheduler
 */
Scheduler *getGlobalScheduler();

/**
 * A function to dynamically create Global Scheduler on startup, only supposed to be called by Main.setup()
 */
void initScheduler();

#endif