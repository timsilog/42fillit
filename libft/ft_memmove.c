/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:45:51 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 14:35:35 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!len)
		return (dst);
	d = (char*)dst;
	s = (char*)src;
	i = -1;
	if (d > s)
		while ((int)(--len) >= 0)
			d[len] = s[len];
	else
		while (++i < len)
			d[i] = s[i];
	return (d);
}
