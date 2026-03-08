
#include "process.h"

void init_process(Process *p, int pid, int arrival, int burst)
{
    p->pid = pid;
    p->arrival_time = arrival;
    p->burst_time = burst;
    p->remaining_time = burst;
    p->start_time = -1;
    p->finish_time = -1;
    p->first_response_time = -1;
    p->current_queue = 0;
}

void execute_cycle(Process *p)
{
    if(p->remaining_time > 0)
        p->remaining_time--;
}

int is_finished(Process *p)
{
    return p->remaining_time == 0;
}

int response_time(Process *p)
{
    return p->first_response_time - p->arrival_time;
}

int turnaround_time(Process *p)
{
    return p->finish_time - p->arrival_time;
}

int waiting_time(Process *p)
{
    return turnaround_time(p) - p->burst_time;
}