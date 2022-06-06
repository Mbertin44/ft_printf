/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:01:43 by mbertin           #+#    #+#             */
/*   Updated: 2022/06/06 14:28:00 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
				/* Ici je dois mettre entre parenthese mon *len car je veux qu'il 
				comprenne que je veux incrémenter la valeur du pointeur est non 
				pas l'adresse. La lecture des règles ce fait de droit a gauche
				et le fais de désigner la valeur d'un pointeur ou d'incrémenter 
				une valeur on la même priorité donc la syntaxe -> *len++ voulait
				dire incrémente l'adresse delen puis désigné que je parle de la
				valeur de len et non pas son adresse. 
				
			 (*len)++ veut bien dire incrémente la valeur à l'adresse de len*/
}

void	ft_putstr(char *str, int *len)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], len);
		i++;
	}
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
		ft_putstr("-2147483648", len);
	else if (n < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(-n, len);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10, len);
		}
		ft_putchar(48 + n % 10, len);
	}
}
