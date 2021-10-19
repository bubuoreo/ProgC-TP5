#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "repertoire.h"


int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        printf("Pas possible d'effectuer le compteur sans nom de dossier\n");
        return 0;
    }
    
    else
    {
        lire_dossier_recursif(argv[1]);
    }
    

    return 0;
}
