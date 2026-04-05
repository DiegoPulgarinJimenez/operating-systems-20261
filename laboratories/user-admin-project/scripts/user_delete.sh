#!/bin/bash

USERNAME=$1

if [ -z "$USERNAME" ]; then
    echo "Specify a username"
    exit 1
fi

if [ "$USERNAME" == "root" ]; then
    echo "Operation not allowed on root user"
    exit 1
fi

if ! id "$USERNAME" &>/dev/null; then
    echo "User does not exist"
    exit 1
fi

userdel -r "$USERNAME"

echo "User $USERNAME has been deleted"