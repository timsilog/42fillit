/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 16:42:46 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 17:22:09 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		r_value;
	size_t	hold;

	hold = size;
	i = ft_strlen(dest);
	if (i < size)
		r_value = ft_strlen(src) + i;
	else
		r_value = ft_strlen(src) + size;
	j = 0;
	if (size == 0)
		return (r_value);
	while (i < hold - 1)
	{
		if (src[j] == '\0')
			break ;
		else
			dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (r_value);
}
