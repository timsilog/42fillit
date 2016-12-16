/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:49:26 by tjose             #+#    #+#             */
/*   Updated: 2016/12/01 17:27:06 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_str(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	next_len(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**splitloop(char **fresh, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			fresh[j] = (char*)malloc(sizeof(char) * next_len(&s[i], c) + 1);
			if (!fresh[j])
				return (NULL);
			while (s[i] != c && s[i])
				fresh[j][k++] = s[i++];
			fresh[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	fresh[j] = NULL;
	return (fresh);
}

char		**ft_strsplit(char const *s, char c)
{
	char **fresh;

	if (!s)
		return (NULL);
	else
	{
		if (!(fresh = (char**)malloc(sizeof(char*) * num_str(s, c) + 1)))
			return (NULL);
		return (splitloop(fresh, s, c));
	}
}
