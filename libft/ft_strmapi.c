/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:23:17 by bhennequ          #+#    #+#             */
/*   Updated: 2023/02/07 20:29:45 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*tab;
	size_t		i;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	tab = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tab)
		return (NULL);
	while (i < ft_strlen(s))
	{
		tab[i] = (*f)(i, s[i]);
		++i;
	}
	tab[i] = 0;
	return (tab);
}
