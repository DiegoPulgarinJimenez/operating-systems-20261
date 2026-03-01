#include <string.h>
#include "utils.h"

int es_numerico(const char *str){
    if (*str == '\0') return 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int validar_correo(const char *str) {
    return strchr(str, '@') != NULL;
}

int cadena_vacia(const char *str) {
    return str==NULL || strlen(str) == 0;
}