/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:35:15 by bhennequ          #+#    #+#             */
/*   Updated: 2023/02/14 18:43:31 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t size)
{
	void	*tab;
	size_t	x;

	x = nelem * size;
	if (nelem == 0 || size == 0)
		return ((void *)malloc(0));
	if (x / nelem != size)
		return (NULL);
	tab = (void *)malloc(x);
	if (!tab)
		return (NULL);
	ft_bzero(tab, x);
	return (tab);
}
