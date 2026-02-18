# Objetivo: Borrar los primeros 10 y los últimos 20 archivos

# se usa rm y de nuevo expansión por llaves en cada uno de los directorios

❯ rm example/file{1..10}
❯ rm example/file{81..100}

❯ rm music/file{1..10}
❯ rm music/file{81..100}

❯ rm photos/file{1..10}
❯ rm photos/file{81..100}

❯ rm projects/file{1..10}
❯ rm projects/file{81..100}

# se verifica que se hayan eliminado correctamente
❯ ls projects | wc -l
70
