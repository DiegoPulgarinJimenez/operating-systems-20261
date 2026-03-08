
#include <stdio.h>
#include "export.h"

void export_csv(Process processes[], int n)
{
    FILE *file = fopen("assets/results.csv", "w");

    if(file == NULL)
    {
        printf("Error creating results.csv\n");
        return;
    }

    fprintf(
        file,
        "PID,Arrival,Burst,Start,Finish,Response,Turnaround,Waiting\n"
    );

    for(int i = 0; i < n; i++)
    {
        fprintf(
            file,
            "%d,%d,%d,%d,%d,%d,%d,%d\n",
            processes[i].pid,
            processes[i].arrival_time,
            processes[i].burst_time,
            processes[i].start_time,
            processes[i].finish_time,
            response_time(&processes[i]),
            turnaround_time(&processes[i]),
            waiting_time(&processes[i])
        );
    }

    fclose(file);
}