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

# Dar permisos
RUN chmod +x /app/scripts/*.sh

CMD ["/bin/bash"]
