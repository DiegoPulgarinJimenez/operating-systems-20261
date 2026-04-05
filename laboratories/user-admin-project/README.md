# User Administration System (Bash + Docker)

## Descripción

Este proyecto consiste en el desarrollo de una herramienta de administración de usuarios en sistemas Linux, implementada mediante Bash scripting y ejecutada dentro de un contenedor Docker basado en Kali Linux.

El sistema permite gestionar usuarios desde la línea de comandos, aplicando políticas de seguridad como:

* Control de contraseñas
* Expiración y advertencias
* Bloqueo automático
* Restricción de privilegios mediante sudo

---

## Objetivos

### Objetivo general

Desarrollar un sistema para la administración de usuarios en Linux utilizando Bash scripting.

### Objetivos específicos

* Crear, eliminar, bloquear y desbloquear usuarios
* Aplicar políticas de seguridad en contraseñas
* Gestionar expiración de credenciales
* Restringir privilegios mediante sudoers
* Ejecutar el sistema dentro de un contenedor Docker

---

## Estructura del proyecto

```
user-admin-project/
│
├── docker/
│   └── Dockerfile
│
├── scripts/
│   ├── main.sh
│   ├── user_create.sh
│   ├── user_delete.sh
│   ├── user_lock.sh
│   ├── user_unlock.sh
│   ├── user_list.sh
│   ├── password_policy.sh
│   ├── expiration_policy.sh
│   ├── sudo_manager.sh
│   └── password_warning.sh
│
├── config/
│   └── defaults.conf
│
└── README.md
```

---

## Docker

### ¿Por qué Docker?

Se utiliza Docker para:

* Aislar el entorno del sistema
* Evitar afectar el sistema operativo real
* Garantizar reproducibilidad

---

### Construcción de la imagen

```bash
sudo docker build -t user-admin-kali -f docker/Dockerfile .
```

---

### Ejecución del contenedor

```bash
sudo docker run -it --name user-admin user-admin-kali /bin/bash
```

---

## Uso del sistema

Todos los comandos se ejecutan como root:

```bash
user-admin <comando> [usuario]
```

---

### Listar usuarios

```bash
user-admin list
```

---

### Crear usuario

```bash
user-admin create [usuario]
```

* Se crea con contraseña por defecto
* Se fuerza cambio en el primer login
* Se aplica política de expiración

---

### Bloquear usuario

```bash
user-admin lock [usuario]
```

---

### Desbloquear usuario

```bash
user-admin unlock [usuario]
```

---

### Eliminar usuario

```bash
user-admin delete [usuario]
```

---

### Asignar permisos sudo restringidos

```bash
user-admin grant-sudo [usuario]
```

El usuario solo podrá ejecutar:

```
/app/scripts/main.sh
```

---

## Políticas de seguridad

### Contraseñas

* Sin espacios en blanco
* Al menos una letra mayúscula
* Al menos un carácter especial

---

### Expiración de contraseñas

Configurado mediante:

* Expiración máxima: 30 días
* Advertencia: 10 días antes
* Bloqueo automático tras expiración

---

### Mensaje personalizado

Se implementa mediante `/etc/profile`, mostrando advertencias al iniciar sesión si la contraseña está próxima a expirar.

---

## Configuración

Archivo:

```
config/defaults.conf
```

Permite modificar:

```bash
MAX_DAYS=30
WARN_DAYS=10
INACTIVE_DAYS=1
```

---

## Diseño del sistema

El proyecto sigue principios de diseño modular:

* Separación de responsabilidades: cada script tiene una función específica
* Reutilización: funciones compartidas mediante `source`
* Configuración desacoplada: parámetros externos en archivo `.conf`
* Control centralizado: `main.sh` actúa como punto de entrada único

---

## Seguridad

* Solo el usuario root puede ejecutar acciones administrativas
* Uso de `/etc/sudoers.d/` para control de privilegios
* Restricción de comandos permitidos
* Protección contra modificación de usuarios críticos (ej: root)

---

## Tecnologías utilizadas

* Bash scripting
* Docker
* Kali Linux
* Herramientas Linux:

    * `useradd`
    * `usermod`
    * `userdel`
    * `chage`
    * `sudo`

---

## Conclusión

Este proyecto implementa un sistema completo de administración de usuarios en Linux, integrando:

* Seguridad
* Automatización
* Buenas prácticas de diseño
* Aislamiento mediante contenedores

Simula un entorno real de administración de sistemas, aplicando conceptos utilizados en entornos profesionales.

---
