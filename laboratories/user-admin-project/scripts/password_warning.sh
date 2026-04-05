#!/bin/bash

USERNAME=$(whoami)

# Evitar ejecutar para root
if [ "$USERNAME" == "root" ]; then
    exit 0
fi

# Obtener info de expiración
EXPIRATION_INFO=$(chage -l "$USERNAME")

# Extraer días restantes
DAYS_LEFT=$(echo "$EXPIRATION_INFO" | grep -i "expires" | awk -F: '{print $2}')

# Convertir fechas a días restantes
EXP_DATE=$(date -d "$DAYS_LEFT" +%s 2>/dev/null)
TODAY=$(date +%s)

if [ -n "$EXP_DATE" ]; then
    DIFF_DAYS=$(( (EXP_DATE - TODAY) / 86400 ))

    if [ "$DIFF_DAYS" -le 10 ] && [ "$DIFF_DAYS" -gt 0 ]; then
        echo "WARNING: Your password will expire in $DIFF_DAYS days."
        echo "Contact admin or update it using the appropriate command."
    fi
fi