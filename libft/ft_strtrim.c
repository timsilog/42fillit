/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:00:27 by tjose             #+#    #+#             */
/*   Updated: 2016/12/01 16:30:12 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_white(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	int		total;
	char	*fresh;

	if (!s)
		return (NULL);
	i = 0;
	total = ft_strlen(s);
	while (is_white(s[i]))
		i++;
	len = ft_strlen(&s[i]) + 1;
	while ((s[total] == '\0' || is_white(s[total])) && len)
	{
		total--;
		len--;
	}
	if (!(fresh = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	fresh[len] = '\0';
	while (--len >= 0)
		fresh[len] = s[i + len];
	return (fresh);
}
