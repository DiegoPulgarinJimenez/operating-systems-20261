#!/bin/bash

echo "System users (UID >= 1000):"

awk -F: '$3 >= 1000 {print $1}' /etc/passwd