#!/bin/bash

USERNAME=$1

if [ -z "$USERNAME" ]; then
    echo "Specify a username"
    exit 1
fi

if ! id "$USERNAME" &>/dev/null; then
    echo "User does not exist"
    exit 1
fi

if [ "$USERNAME" == "root" ]; then
    echo "Operation not allowed on root"
    exit 1
fi

MAIN_SCRIPT="/usr/local/bin/user-admin"

SUDO_FILE="/etc/sudoers.d/$USERNAME"

echo "Configuring sudo access for $USERNAME"

# Reglas de sudoers
echo "$USERNAME ALL=(ALL) NOPASSWD: $MAIN_SCRIPT" > "$SUDO_FILE"

# Permisos (solo lectura para root)
chmod 440 "$SUDO_FILE"

echo "Sudo access granted ONLY for:"
echo "$MAIN_SCRIPT"