/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:23:13 by bhennequ          #+#    #+#             */
/*   Updated: 2023/02/09 18:01:27 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			word++;
		while (str[i] != c && str[i])
			i++;
	}
	return (word);
}

static void	write_split(const char *str, char c, char **tab)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	j = 0;
	while (str[i])
	{
		pos = i;
		while (str[i] != c && str[i])
			i++;
		if (pos != i)
		{
			tab[j] = ft_substr(str, pos, i - pos);
			j++;
		}
		if (str[i])
			i++;
	}
}

char	**ft_split(const char *str, char c)
{
	char	**tab;

	if (!str || ft_strlen(str) == 0)
	{
		tab = malloc(sizeof(char *));
		if (!tab)
			return (NULL);
		tab[0] = NULL;
		return (tab);
	}
	tab = (char **)ft_calloc((count_word(str, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	write_split(str, c, tab);
	return (tab);
}
