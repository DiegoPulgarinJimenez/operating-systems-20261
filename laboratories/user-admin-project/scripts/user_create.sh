#!/bin/bash

# Importar política de contraseñas
source "$(dirname "$0")/password_policy.sh"

USERNAME=$1

if [ -z "$USERNAME" ]; then
    echo "Specify a username"
    exit 1
fi

# Verificar si existe
if id "$USERNAME" &>/dev/null; then
    echo "The user already exists"
    exit 1
fi

# Pedir contraseña segura 
while true; do
	read -s -p "Enter password: " PASSWORD
	echo
	read -s -p "Confirm password: " CONFIRM
	echo

	if [ "$PASSWORD" != "$CONFIRM" ]; then 
		echo "Passwords do not match"
		continue
	fi

	validate_password "$PASSWORD"
	if [ $? -eq 0 ]; then
		break
	fi
done

# Crear usuario

echo "Creating user: $USERNAME"

useradd -m -s /bin/bash "$USERNAME"

echo "User created"

echo "$USERNAME:$PASSWORD" | chpasswd

# Forzar cambio en el primer login
chage -d 0 "$USERNAME"

echo "You must change your password at the first loging"
