#!/bin/bash

source "$(dirname "$0")/password_policy.sh"
source "$(dirname "$0")/expiration_policy.sh"
source "$(dirname "$0")/utils.sh"

USERNAME=$1

if [ -z "$USERNAME" ]; then
    echo "Specify a username"
    exit 1
fi

if [ "$USERNAME" == "root" ]; then
    echo "Operation not allowed on root user"
    exit 1
fi

if id "$USERNAME" &>/dev/null; then
    echo "The user already exists"
    exit 1
fi

echo "Creating user: $USERNAME"

useradd -m -s /bin/bash "$USERNAME"

# contraseña por defecto
DEFAULT_PASS=$(generate_default_password)

echo "$USERNAME:$DEFAULT_PASS" | chpasswd

echo "Default password: $DEFAULT_PASS"

# Forzar cambio en primer login
chage -d 0 "$USERNAME"

# Aplicar expiración de contraseña
apply_expiration_policy "$USERNAME"

echo "User must change password on first login"