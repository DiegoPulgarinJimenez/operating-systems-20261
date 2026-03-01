#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket.h"
#include "utils.h"
#include <time.h>

#define BUFFER 256

int main() {

	Ticket *ticket = malloc(sizeof(Ticket));
	if (!ticket) {
		printf("Error de memoria\n");
		return 1;
	}

	char buffer[BUFFER];

	printf("Ingrese Identificación: ");
	fgets(buffer, BUFFER, stdin);
	buffer[strcspn(buffer, "\n")] = '\0';

	if (!es_numerico(buffer)){
		printf("Identificación inválida\n");
		liberar_ticket(ticket);
		return 1;
	}

	ticket->identificacion = atoi(buffer);

	printf("Ingrese Correo: ");
	fgets(buffer, BUFFER, stdin);
	buffer[strcspn(buffer, "\n")] = '\0';

	if (!validar_correo(buffer)){
		printf("Correo inválido\n");
		liberar_ticket(ticket);
		return 1;
	}

	ticket->correo = malloc(strlen(buffer) + 1);
	strcpy(ticket->correo, buffer);

	printf("Ingrese tipo de reclamación: ");
	fgets(buffer, BUFFER, stdin);
	buffer[strcspn(buffer, "\n")] = '\0';

	if (cadena_vacia(buffer)) {
		printf("La reclamación no puede estar vacía\n");
		liberar_ticket(ticket);
		return 1;
	}

	ticket->tipo_reclamacion = malloc(strlen(buffer) + 1);
	strcpy(ticket->tipo_reclamacion, buffer);

	ticket->radicado = time(NULL);

	if (!guardar_ticket(ticket)){
		printf("Error creando archivo\n");
		liberar_ticket(ticket);
		return 1;
	}

	printf("Ticket registrado correctamente\n");
	printf("Número de radicado: %ld\n", ticket->radicado);

	liberar_ticket(ticket);
	return 0;
}
