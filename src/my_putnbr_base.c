/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** my_printf
*/

#include "../include/my.h"

int my_putnbr_base(long int nb, char *base)
{
	if (nb < 0) {
		nb = nb * -1;
		my_putchar('-');
	}
	if ( nb >= my_strlen(base))
		my_putnbr_base( nb / my_strlen(base), base);
	my_putchar(base[nb % my_strlen(base)]);
	return (0);
}
