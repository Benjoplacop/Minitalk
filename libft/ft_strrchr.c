/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:31:55 by bhennequ          #+#    #+#             */
/*   Updated: 2023/02/06 18:26:21 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*j;

	j = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			j = (char *)str;
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (j);
}
