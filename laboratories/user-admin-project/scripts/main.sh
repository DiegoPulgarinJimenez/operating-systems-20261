#!/bin/bash

# Validar que sea root / EUID --> Effective user ID 0=root
if [ "$EUID" -ne 0 ]; then
    echo "Root needed"
    exit 1
fi

# Validar que se pasen argumentos 
if [ $# -lt 1 ]; then
    echo "Uso: $0 {list|create|lock|unlock|delete}"
    exit 1
fi

COMMAND=$1
USERNAME=$2

case "$COMMAND" in
    list)
        awk -F: '$3 >= 1000 {print $1}' /etc/passwd
        ;;
    
    create)
        ./scripts/create_user.sh "$USERNAME"
        ;;
    
    *)
        echo "Not valid command"
        ;;
esac
