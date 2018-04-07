/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** epitech
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unist.h>
#include <dirent.h>
#include <stdio.h>
#include "../include/my.h>"

void info(struct dirent *entry)
{
        my_printf("%s ", entry->d_name);
}

int my_ls_a(int ac)
{
        DIR     *dir;
        struct dirent *entry;

        if (ac == 1) {
                dir = opendir ("./");
                entry = readdir(dir);
                while (entry != 0) {
                        info(entry);
                        entry = readdir(dir);
                }
        }
        closedir(dir);
        return (0);
}
