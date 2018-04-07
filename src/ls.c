/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** epitech
*/

#include <time.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include "../include/my.h"

int my_ls()
{
        DIR *dir = NULL;
        struct dirent *entry = NULL;

        dir = opendir(".");
        if (dir == NULL)
                perror("");
        while ((entry = readdir(dir)) != NULL) {
                if (entry->d_name[0] != '.') {
                        my_putstr(entry->d_name);
                        my_putchar(' ');
                }
        }
        closedir(dir);
        return (0);
}
