/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:54:08 by bhennequ          #+#    #+#             */
/*   Updated: 2023/02/08 13:52:14 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	print_in_tab(char *tab, char c)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	tab[i] = c + '0';
	tab[i + 1] = '\0';
}

static void	recur(long nbr, char *tab)
{
	if (nbr <= 9 && nbr >= 0)
		print_in_tab(tab, nbr);
	if (nbr > 9)
	{
		recur(nbr / 10, tab);
		recur(nbr % 10, tab);
	}
}

char	*ft_itoa(int n)
{
	char	*tab;
	long	nbr;

	nbr = n;
	tab = ft_calloc(nbrlen(n) + 1, sizeof(char));
	if (n < 0)
	{
		tab[0] = '-';
		nbr = -nbr;
	}
	recur(nbr, tab);
	return (tab);
}
