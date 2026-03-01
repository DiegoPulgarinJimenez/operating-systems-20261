#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ticket.h"

int guardar_ticket(Ticket *ticket){

    char nombre_archivo[100];
    snprintf(nombre_archivo, sizeof(nombre_archivo),
             "assets/ticket_%ld.txt",
             ticket->radicado);

    FILE *archivo = fopen(nombre_archivo, "w");

    if (archivo == NULL)
        return 0;

    fprintf(archivo, "Radicado: %ld\n", ticket->radicado);
    fprintf(archivo, "Identificación: %d\n", ticket->identificacion);
    fprintf(archivo, "Correo: %s\n", ticket->correo);
    fprintf(archivo, "Tipo de reclamación: %s\n", ticket->tipo_reclamacion);

    fclose(archivo);
    return 1;
}

void liberar_ticket(Ticket *ticket){
    if (ticket == NULL) return;

    free(ticket->correo);
    free(ticket->tipo_reclamacion);
    free(ticket);
}