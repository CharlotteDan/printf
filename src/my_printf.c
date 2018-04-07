/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"

static int switch3(va_list ap, char *str, int i)
{
	switch (str[i]) {
	case 'p':
		my_putstr("0x");
		my_putnbr_base(va_arg(ap,
				      unsigned int), "0123456789abcdef");
		break;
	case 'o':
		my_putnbr_base(va_arg(ap, long), "01234567");
		break;
	case 'u':
		my_putnbr_base(va_arg(ap, unsigned int), "0123456789");
		break;
	default :
		write(1, "%", sizeof(char));
		write(1, &str[i], sizeof(char));
	}
	return (0);
}

static int switch2(va_list ap, char *str, int i)
{
	switch (str[i]) {
	case 'x':
		my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
		break;
	case 'X':
		my_putnbr_base(va_arg(ap, long), "0123456789ABCDEF");
		break;
	case 'S':
		my_string(va_arg(ap, char *));
		break;
	default:
		switch3(ap, str, i);
	}
	return (0);
}

int switch1(va_list ap, char *str, int i)
{
	if (str[i] == '%') {
		i++;
		switch (str[i]) {
		case 's':
			my_putstr(va_arg(ap, char *));
			break;
		case 'c': my_putchar(va_arg(ap, int)); break;
		case '%':
			my_putchar('%');
			break;
		case 'd':
		case 'i':
			my_put_nbr(va_arg(ap, int));
			break;
		case 'b':
			my_putnbr_base(va_arg(ap, unsigned int), "01");
			break;
		default: switch2(ap, str, i);
		}
	} else if (str[i] == '%')
		my_putchar(str[i]);
	return (0);
}

static int compilation(va_list ap, char *str, int i)
{
	while (str[i] != 0) {
		switch1(ap, str, i);
		if (str[i] == '%')
			i++;
			else if (str [i] != '%')
			my_putchar(str[i]);
		else
			write(1, &str[i], sizeof(char));
		i++;
	}
	return (0);
}

int my_printf(char *str, ...)
{
	int i = 0;
	va_list ap;

	va_start(ap, str);
	compilation(ap, str, i);
	va_end(ap);
	return (0);
}
