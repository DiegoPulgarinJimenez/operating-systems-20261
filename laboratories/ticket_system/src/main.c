#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket/ticket.h"

#define BUFFER 256

int main() {

    Ticket *ticket = (Ticket *) malloc(sizeof(Ticket));

    if (ticket == NULL) {
    	printf("Error de memoria\n");
    	return 1;
    }

    char buffer[BUFFER];
    
    ticket->radicado = 12345;
    ticket->identificacion = 1001;
    
    printf("Ingrese Identificación: ");
    if (fgets(buffer, BUFFER, stdin) == NULL) {
    	printf("Error leyendo datos\n");
    	free(ticket);
    	return 1;
    }

    buffer[strcspn(buffer, "\n")] = '\0';
    
    printf("Usted escribió: %s\n", buffer);

    free(ticket);
    return 0;
}
