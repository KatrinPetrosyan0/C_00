/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpetrosy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:29:01 by kpetrosy          #+#    #+#             */
/*   Updated: 2020/12/02 19:38:01 by kpetrosy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long a;

	a = nb;
	if (a < 0)
	{
		ft_putchar('-');
		a = a * (-1);
	}
	if (a > 9)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
	else
	{
		ft_putchar(a + '0');
	}
}

void	add(int *array, int n)
{
	int z;

	while (1)
	{
		z = 0;
		while (z < n)
		{
			ft_putnbr(array[z]);
			z++;
		}
		if (array[0] != 10 - n)
			write(1, ", ", 2);
		z = n - 1;
		while (array[z] >= ((z - n + 10)) && z >= 0)
			z--;
		if (z == -1)
			break ;
		while (z < n)
		{
			array[z]++;
			if (z != n - 1)
				array[z + 1] = array[z];
			z++;
		}
	}
}

void	ft_print_combn(int n)
{
	int array[n];
	int z;

	if (n > 0 && n < 10)
	{
		z = 0;
		while (z < n)
		{
			array[z] = z;
			z++;
		}
		add(array, n);
	}
}
