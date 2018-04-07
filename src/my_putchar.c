/*
** EPITECH PROJECT, 2017
** my putchar
** File description:
** my_printf
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
