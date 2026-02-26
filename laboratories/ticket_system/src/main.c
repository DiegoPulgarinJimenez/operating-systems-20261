#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ticket/ticket.h"

#define BUFFER 256

int es_numerico(const char *str){
    if (*str == '\0') return 0;

    for (int i = 0; str[i] != '\0'; i++){
    	if (str[i] < '0' || str[i] > '9')
    	    return 0;
    }
    return 1;
}

int main() {

    Ticket *ticket = (Ticket *) malloc(sizeof(Ticket));

    if (ticket == NULL) {
    	printf("Error de memoria\n");
    	return 1;
    }

    char buffer[BUFFER];

    printf("Ingrese Identificación: ");
    if (fgets(buffer, BUFFER, stdin) == NULL) {
    	printf("Error leyendo datos\n");
    	free(ticket);
    	return 1;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    if (!es_numerico(buffer)){
	printf("La identificación debe ser numerica\n");
	free(ticket);
	return 1;
    }

    ticket->identificacion = atoi(buffer);

    printf("Ingrese Correo: ");
    if(fgets(buffer, BUFFER, stdin) == NULL){
	printf("Error leyendo datos\n");
	free(ticket);
	return 1;
    }

    buffer[strcspn(buffer, "\n")] = '0';

    if (strchr(buffer, '@') == NULL){
	printf("Correo invalido\n");
	free(ticket);
	return 1;
    }

    ticket->correo = (char *) malloc(strlen(buffer) + 1);

    if (ticket->correo == NULL){
    	printf("Error de memoria\n");
    	free(ticket);
	return 1;
    }

    strcpy(ticket->correo, buffer);

    printf("Ingrese tipo de reclamacion: ");
    if (fgets(buffer, BUFFER, stdin) == NULL) {
        printf("Error leyendo datos\n");
        free(ticket->correo);
        free(ticket);
        return 1;
    }

    buffer[strcspn(buffer, "\n")] = '\0';
    ticket->tipo_reclamacion = (char *) malloc(strlen(buffer) + 1);

    if (ticket->tipo_reclamacion == NULL) {
	printf("Error de memoria\n");
    	free(ticket->correo);
    	free(ticket);
    	return 1;
    }


    strcpy(ticket->tipo_reclamacion, buffer);

    ticket->radicado = (long) time(NULL);

    /*TODO ¿Crear archivo acá?*/

    printf("Radicado generado: %ld\n", ticket->radicado);

    free(ticket->correo);
    free(ticket->tipo_reclamacion);
    free(ticket);

    return 0;
}
