### Objetivo: Subir el lab0 a GitHub.

### Inicializa el repositorio en ~/operating-systems-20261/
❯ git init

### Agregar todos los cambios al staging area
❯ git add .

### Se hace el primer commit con los avances 
❯ git commit -m "lab0 operating systems"

### Se conecta al repositorio local con el repositorio creado en GitHub
❯ git remote add origin https://github.com/DiegoPulgarinJimenez/operating-systems-20261.git

### Envía la rama main al repositorio en GitHub. -u sirve para establecer la relación de seguimiento, después solo se hace git push 
❯ git push -u origin main

### Propietario del repositorio
Username for 'https://github.com': DiegoPulgarinJimenez

# Ahora se usa token
Password for 'https://DiegoPulgarinJimenez@github.com': 
Enumerating objects: 18, done.
Counting objects: 100% (18/18), done.
Delta compression using up to 8 threads
Compressing objects: 100% (15/15), done.
Writing objects: 100% (18/18), 3.66 KiB | 3.66 MiB/s, done.
Total 18 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/DiegoPulgarinJimenez/operating-systems-20261.git
 * [new branch]      main -> main
branch 'main' set up to track 'origin/main'.git push -u origin main
