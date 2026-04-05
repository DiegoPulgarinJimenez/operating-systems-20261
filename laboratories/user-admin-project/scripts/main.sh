#!/bin/bash

# Validar que sea root / EUID --> Effective user ID 0=root
if [ "$EUID" -ne 0 ]; then
    echo "Root needed"
    exit 1
fi

# Validar que se pasen argumentos
if [ $# -lt 1 ]; then
    echo "Usage: $0 {list|create|lock|unlock|delete|grant-sudo}"
    exit 1
fi

COMMAND=$1
USERNAME=$2

SCRIPT_PATH="$(readlink -f "$0")"
BASE_DIR="$(dirname "$SCRIPT_PATH")"

case "$COMMAND" in
    list)
        "$BASE_DIR/user_list.sh"
        ;;
    create)
        "$BASE_DIR/user_create.sh" "$USERNAME"
        ;;
    lock)
        "$BASE_DIR/user_lock.sh" "$USERNAME"
        ;;
    unlock)
        "$BASE_DIR/user_unlock.sh" "$USERNAME"
        ;;
    delete)
        "$BASE_DIR/user_delete.sh" "$USERNAME"
        ;;
    grant-sudo)
        "$BASE_DIR/sudo_manager.sh" "$USERNAME"
        ;;
    *)
        echo "Invalid command"
        ;;
esac
