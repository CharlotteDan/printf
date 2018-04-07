/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** my_printf
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
	int i = 0;

	if (str == 0) {
		my_putstr("(null)");
		return (84);
	}
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
	}
	return (0);
}
