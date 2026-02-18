# Objetivo: Crear la estructura de carpetas en la ruta especificada --> ~/operating-systems-20261/laboratories/lab0
# Comandos usados: 
❯ pwd 
# para revisar el directorio actual
/home/diego
❯ cd ~ 
# para ir a ~
❯ mkdir -p ~/operating-systems-20261/laboratories/lab0
# para crear el directorio. -p permite crear los directorios padre si no existen 
❯ ls
# para verificar que se haya creado la carpeta
 Desktop     nano.2399.save            Pictures         Public
 Documents   nano.2402.save           'Postman Agent'   Templates
 Downloads   operating-systems-20261   proyectos        test.raw
 Music       packages.microsoft.gpg    pt               Videos
❯ cd operating-systems-20261
# para ingresar a la carpeta
❯ tree
# para listar el directorio en modo árbol 
.
└── laboratories
    └── lab0

3 directories, 0 files
