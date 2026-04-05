#!/bin/bash

validate_password() {
    local PASSWORD="$1"

    # No permitir espacios en blanco
    if [[ "$PASSWORD" =~ [[:space:]] ]]; then
        echo "No blank spaces allowed"
        return 1
    fi

    # Debe tener al menos una mayúscula
    if [[ ! "$PASSWORD" =~ [A-Z] ]]; then
        echo "Must have at least one capital letter"
        return 1
    fi

    # Debe tener al menos un carácter especial
    if [[ ! "$PASSWORD" =~ [^a-zA-Z0-9] ]]; then
        echo "Must have at least one special character"
        return 1
    fi

    return 0
}
