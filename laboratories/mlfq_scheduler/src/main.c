
#include <stdio.h>
#include "process.h"
#include "export.h"
#include "simulation.h"

int main()
{
    Process processes[4];

    init_process(&processes[0], 1, 0, 8);
    init_process(&processes[1], 2, 1, 4);
    init_process(&processes[2], 3, 2, 9);
    init_process(&processes[3], 4, 3, 5);

    int n = 4;

    run_simulation(processes, n);

    for(int i = 0; i < n; i++)
    {

        printf(
            "P%d -> Response:%d Turnaround:%d Waiting:%d\n",
            processes[i].pid,
            response_time(&processes[i]),
            turnaround_time(&processes[i]),
            waiting_time(&processes[i])
        );
    }

    export_csv(processes, n);

    return 0;
}
