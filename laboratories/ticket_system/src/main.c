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

	while (1) {

		printf("Ingrese Identificación (o escriba 'exit' para salir): ");

		if (fgets(buffer, BUFFER, stdin) == NULL) {
			printf("Error leyendo datos\n");
			liberar_ticket(ticket);
			return 1;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0) {
			printf("Saliendo del programa...\n");
			liberar_ticket(ticket);
			return 0;
		}

		if (cadena_vacia(buffer)) {
			printf("La identificación no puede estar vacía\n");
			continue;
		}

		if (!es_numerico(buffer)) {
			printf("La identificación debe ser numérica\n");
			continue;
		}

		ticket->identificacion = atoi(buffer);
		break;
	}

	while (1) {

		printf("Ingrese Correo (o escriba 'exit' para salir): ");

		if (fgets(buffer, BUFFER, stdin) == NULL) {
			printf("Error leyendo datos\n");
			liberar_ticket(ticket);
			return 1;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0) {
			printf("Saliendo del programa...\n");
			liberar_ticket(ticket);
			return 0;
		}

		if (cadena_vacia(buffer)) {
			printf("El correo no puede estar vacío\n");
			continue;
		}

		if (!validar_correo(buffer)) {
			printf("Correo inválido\n");
			continue;
		}

		ticket->correo = malloc(strlen(buffer) + 1);

		if (!ticket->correo) {
			printf("Error de memoria\n");
			liberar_ticket(ticket);
			return 1;
		}

		strcpy(ticket->correo, buffer);
		break;
	}

	while (1) {

		printf("Ingrese tipo de reclamación (o escriba 'exit' para salir): ");

		if (fgets(buffer, BUFFER, stdin) == NULL) {
			printf("Error leyendo datos\n");
			liberar_ticket(ticket);
			return 1;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0) {
			printf("Saliendo del programa...\n");
			liberar_ticket(ticket);
			return 0;
		}

		if (cadena_vacia(buffer)) {
			printf("La reclamación no puede estar vacía\n");
			continue;
		}

		ticket->tipo_reclamacion = malloc(strlen(buffer) + 1);

		if (!ticket->tipo_reclamacion) {
			printf("Error de memoria\n");
			liberar_ticket(ticket);
			return 1;
		}

		strcpy(ticket->tipo_reclamacion, buffer);

		break;
	}

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
