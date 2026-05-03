#include "ft_printf.h"

int ft_printptr(void *adress)
{
	long n;

	n = count_hex((unsigned long)adress) + 2;
	write(1, "0x", 2);
	write_hexa((unsigned long)adress, 'x');
	return (n);
}

void	ft_putnbr_u(unsigned int nb)
{
	unsigned int	n;
	char			c;

	n = nb;
	if (n > 9)
		ft_putnbr_u(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}