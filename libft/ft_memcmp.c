/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:28:52 by tjose             #+#    #+#             */
/*   Updated: 2016/12/15 16:52:57 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*a1;
	const unsigned char	*a2;

	if ((s1 == NULL && s2 == NULL) || !n)
		return (0);
	a1 = (const unsigned char*)s1;
	a2 = (const unsigned char*)s2;
	i = 0;
	while (a1[i] == a2[i] && i < n)
	{
		i++;
		if (i == n)
			return (0);
	}
	return (a1[i] - a2[i]);
}
