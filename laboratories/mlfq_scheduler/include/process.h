
#ifndef MLFQ_SCHEDULER_PROCESS_H
#define MLFQ_SCHEDULER_PROCESS_H

typedef struct {

    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int start_time;
    int finish_time;
    int first_response_time;
    int current_queue;

} Process;

void init_process(
    Process *p,
    int pid,
    int arrival,
    int burst
);

void execute_cycle(Process *p);
int is_finished(Process *p);
int response_time(Process *p);
int turnaround_time(Process *p);
int waiting_time(Process *p);

#endif //MLFQ_SCHEDULER_PROCESS_H