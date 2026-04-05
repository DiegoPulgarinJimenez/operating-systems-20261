FROM kalilinux/kali-rolling

RUN apt update && apt install -y \
    sudo \
    passwd \
    login \
    nano

# Crear directorio de trabajo
WORKDIR /app

# Copiar scripts
COPY ../scripts /app/scripts
COPY ../config /app/config

# Dar permisos
RUN chmod -R 755 /app/scripts
# RUN chmod +x /app/scripts/*.sh

# Enlace simbólico en la ruta del PATH
RUN ln -s /app/scripts/main.sh /usr/local/bin/user-admin

RUN echo '\n# Custom password warning\nif [ -f /app/scripts/password_warning.sh ]; then\n source /app/scripts/password_warning.sh\nfi' >> /etc/profile
CMD ["/bin/bash", "-l"]
