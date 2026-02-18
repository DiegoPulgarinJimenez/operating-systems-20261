# Objetivo: crear los archivos en los directorios internos

# Se usa touch y expansión con llaves (zsh lo permite) para crear los 100 archivos con un solo comando
❯ touch example/file{1..100}
❯ touch music/file{1..100}
❯ touch photos/file{1..100}
❯ touch photos/file{1..100}

# Se lista y se usa wc -l para contar las palabras y verificar el número de archivos. Se usa | para ejecutar ambos comandos al mismo tiempo
ls example | wc -l
