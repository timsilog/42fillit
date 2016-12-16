/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:37:11 by tjose             #+#    #+#             */
/*   Updated: 2016/12/01 13:28:10 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	if (!s || start > ft_strlen(s))
		return (NULL);
	i = 0;
	if (!(fresh = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len && s)
		fresh[i++] = s[start++];
	fresh[i] = '\0';
	return (fresh);
}
