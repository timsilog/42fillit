/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:36:34 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 18:50:54 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*holder;
	char	*from;
	size_t	i;

	i = -1;
	holder = (char*)dst;
	from = (char*)src;
	while (++i < n)
		holder[i] = from[i];
	return (dst);
}
