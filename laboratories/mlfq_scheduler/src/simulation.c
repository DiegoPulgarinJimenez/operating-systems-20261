
#include "stdio.h"
#include "simulation.h"
#include "scheduler.h"

void run_simulation(Process processes[], int n)
{
    int time = 0;
    int completed = 0;
    Process *running = NULL;
    int quantum_remaining = 0;
    Scheduler scheduler;

    init_scheduler(&scheduler);

    while(completed < n)
    {

        for(int i = 0; i < n; i++)
        {
            if(processes[i].arrival_time == time)
            {
                add_process(&scheduler, &processes[i]);
            }
        }


        if(time > 0 && time % BOOST_INTERVAL == 0)
        {
            priority_boost(&scheduler);
        }


        if(running == NULL)
        {
            running = select_process(&scheduler);

            if(running != NULL)
            {

                if(running->first_response_time == -1)
                    running->first_response_time = time;

                if(running->start_time == -1)
                    running->start_time = time;


                if(running->current_queue == 0)
                    quantum_remaining = Q0_QUANTUM;

                else if(running->current_queue == 1)
                    quantum_remaining = Q1_QUANTUM;

                else
                    quantum_remaining = Q2_QUANTUM;
            }
        }


        if(running != NULL)
        {
            execute_cycle(running);
            quantum_remaining--;
        }


        if(running != NULL && is_finished(running))
        {
            running->finish_time = time + 1;

            completed++;

            running = NULL;
        }

        else if(running != NULL && quantum_remaining == 0)
        {
            demote_process(&scheduler, running);

            running = NULL;
        }


        time++;
    }
}