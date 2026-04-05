#!/bin/bash

generate_default_password() {
    # Generar conraseña por defecto
    echo "Temp$(date +%s | tail -c 6)!A"
}