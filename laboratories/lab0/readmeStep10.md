# Objetivo: Eliminar los archivos dentro de projects (no los directorios)

# se intenta borrar pero ésta línea identifica los directorios como archivos. Por eso al final muestra 73 en el conteo 
# si se ejecuta igual daría un error debido a que por defecto rm no elimina directorios (no lo ejecuté, pero creo que eliminaría los archivos regulares más no los directorios)
❯ rm -v projects/*>output.txt
zsh: sure you want to delete all 73 files in /home/diego/operating-systems-20261/laboratories/lab0/projects [yn]? n
❯ ls projects | wc -l
73
# comando correcto: con (.) se especifica el borrado de archivos regulares y envía el resultado a output.txt
❯ rm -v projects/*(.)>output.txt

# se verifica que se hayan eliminado correctamente

❯ cd projects
❯ ls
example  music  photos
