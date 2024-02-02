/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:36:12 by bhennequ          #+#    #+#             */
/*   Updated: 2023/02/07 20:22:46 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[i] != 0 && i < n)
	{
		j = 0;
		while (str1[i + j] == str2[j] && (i + j) < n)
		{
			if (str2[j + 1] == 0)
				return ((char *)&str1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
