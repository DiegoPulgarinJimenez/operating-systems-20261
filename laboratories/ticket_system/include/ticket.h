#ifndef TICKET_H
#define TICKET_H

typedef struct {
    long radicado;
    int identificacion;
    char *correo;
    char *tipo_reclamacion;
} Ticket;

Ticket *crer_ticket();
void liberar_ticket(Ticket *ticket);
int guardar_ticket(Ticket *ticket);

#endif
