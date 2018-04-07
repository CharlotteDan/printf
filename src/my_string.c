/*
** EPITECH PROJECT, 2017
** my_String
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../include/my.h"

int my_string(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (((str[i] >= 0) && (str[i] < 32)) || str[i] == 127) {
			my_putchar('\\');
			str[i] < 32 ? my_putchar('0') : 0;
			str[i] < 8 ? my_putchar('0') : 0;
			my_putnbr_base(str[i], "01234567");
		} else if (str[i] >= 32 && str[i] < 127) {
			my_putchar(str[i]);
		}
		i++;
	}
	return (0);
}
