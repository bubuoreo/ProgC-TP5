#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void lire_dossier(char * directory)
{

    DIR * dirp = opendir(directory);

    struct dirent * ent;

    while(1)
    {
        ent = readdir(dirp);
        if (ent == NULL)
        {
            break;
        }

        printf("%s\t", ent->d_name);
    }

    closedir(dirp);
}


void lire_dossier_recursif(char * directory)
{
    DIR * dirp = opendir(directory);

    struct dirent * ent;

    while(1)
    {
        ent = readdir(dirp);
        if (ent == NULL)
        {
            break;
        }
        printf("%s\n", ent->d_name);
        
        if ((ent->d_type == DT_DIR) && strcmp(ent->d_name,".")!=0 && strcmp(ent->d_name,"..")!=0)
        {
            char new_path[256] = "";
            strcpy(new_path,directory);
            strcat(new_path,"/");
            strcat(new_path,ent->d_name);

            char * ptr_new_path = new_path;

            lire_dossier_recursif(ptr_new_path);
        }
    }

    closedir(dirp);
}