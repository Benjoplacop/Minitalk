/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:38:46 by bhennequ          #+#    #+#             */
/*   Updated: 2023/02/09 18:14:20 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*tab;
	size_t			y;

	i = 0;
	y = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	while (s[start + y] && y < len)
		y++;
	tab = (char *)ft_calloc((y + 1), sizeof(char));
	if (!tab)
		return (NULL);
	y = 0;
	while (s[start + y] && y < len)
	{
		tab[i] = s[start + y];
		i++;
		y++;
	}
	return (tab);
}
