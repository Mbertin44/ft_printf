/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:59:36 by mbertin           #+#    #+#             */
/*   Updated: 2022/06/09 14:05:26 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"
#include <stdlib.h>

void	ft_printf_arg(const char *str, va_list params, int *len)
{
	if (*str == 'd' || *str == 'i')
		ft_putnbr((int)va_arg(params, int), len);
	if (*str == 'c')
		ft_putchar((char)va_arg(params, int), len);
	if (*str == 's')
		ft_putstr((char *)va_arg(params, char *), len);
	if (*str == 'x' || *str == 'X')
		ft_puthex((size_t)va_arg(params, size_t), len, *str, 16);
	if (*str == 'u')
		ft_puthex(va_arg(params, unsigned int), len, *str, 10);
	if (*str == 'p')
	{
		*len += 2;
		write(1, "0x", 2);
		ft_puthex(va_arg(params, unsigned long), len, *str, 16);
	}
	if (*str == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	int		*len;
	int		i;
	va_list	params;

	len = malloc(sizeof(int));
	if (!len)
		return (0);
	va_start(params, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			ft_printf_arg(&format[++i], params, len);
		else
			ft_putchar(format[i], len);
		i++;
	}
	return (*len);
}

int	main(int argc, char const *argv[])
{
	int		a;
	int		b;
	char	c;
	char	str[] = "coucou";

	a = -2147483648;
	b = 10;
	c = 'c';
	printf("FLAG d\n");
	ft_printf("J'ai %d caracteres\n", ft_printf("MIEN: %d\n", a));
	printf("J'ai %d caracteres\n", printf("REEL: %d\n", a));
	printf("\nFLAG i\n");
	ft_printf("J'ai %d caracteres\n", ft_printf("MIEN: %i\n", b));
	printf("J'ai %d caracteres\n", printf("REEL: %i\n", b));
	printf("\nFLAG c\n");
	ft_printf("J'ai %d caracteres\n", ft_printf("MIEN: %c\n", c));
	printf("J'ai %d caracteres\n", printf("REEL: %c\n", c));
	printf("\nFLAG s\n");
	ft_printf("J'ai %d caracteres\n", ft_printf("MIEN: %s\n", str));
	printf("J'ai %d caracteres\n", printf("REEL: %s\n", str));
	printf("\nFLAG X\n");
	ft_printf("J'ai %d caracteres\n", ft_printf("MIEN: %X\n", a));
	printf("J'ai %d caracteres\n", printf("REEL: %X\n", a));
	printf("\nFLAG x\n");
	ft_printf("J'ai %d caracteres\n", ft_printf("MIEN: %x\n", 154));
	printf("J'ai %d caracteres\n", printf("REEL: %x\n", 154));
	printf("\nFLAG u\n");
	ft_printf("J'ai %d caracteres\n", ft_printf("MIEN: %u\n", 4294967296));
	printf("J'ai %d caracteres\n", printf("REEL: %u\n", 4294967296));
	printf("\nFLAG p\n");
	ft_printf("J'ai %d caracteres\n", ft_printf("MIEN: %p\n", &a));
	printf("J'ai %d caracteres\n", printf("REEL: %p\n", &a));
	printf("\nFLAG %%\n");
	ft_printf("J'ai %d caracteres\n", ft_printf("MIEN: %%\n"));
	printf("J'ai %d caracteres\n", printf("REEL: %%\n"));
	return (0);
}
