#!/bin/bash

# Cargar configuración
source "$(dirname "$0")/../config/defaults.conf"

apply_expiration_policy() {
    local USERNAME="$1"

    echo "Applying password expiration policy to $USERNAME"

    # Establecer expiración
    chage -M "$MAX_DAYS" "$USERNAME"

    # Advertencia antes de expiración
    chage -W "$WARN_DAYS" "$USERNAME"

    # Bloqueo después de expirar
    chage -I "$INACTIVE_DAYS" "$USERNAME"

    echo "Expiration policy applied:"
    echo "   - Max days: $MAX_DAYS"
    echo "   - Warning: $WARN_DAYS days before"
    echo "   - Inactive lock: $INACTIVE_DAYS day(s)"
}
