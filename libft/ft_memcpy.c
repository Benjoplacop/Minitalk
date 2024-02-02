/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:52:45 by bhennequ          #+#    #+#             */
/*   Updated: 2023/02/07 18:23:20 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*des;
	const unsigned char		*st;

	if (!dest && !src)
		return (dest);
	des = dest;
	st = src;
	i = 0;
	while (i < n)
	{
		des[i] = st[i];
		i++;
	}
	return (dest);
}
