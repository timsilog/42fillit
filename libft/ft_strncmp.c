/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 22:51:16 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 15:37:55 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*a1;
	const unsigned char *a2;
	size_t				i;

	if (!n)
		return (0);
	a1 = (const unsigned char*)s1;
	a2 = (const unsigned char*)s2;
	i = 0;
	while (i < n - 1 && a1[i] == a2[i] && a1[i] && a2[i])
		i++;
	return (a1[i] - a2[i]);
}
