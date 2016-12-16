/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:16:28 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 19:46:51 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	char	*holder;
	char	*from;
	size_t	i;

	i = 0;
	holder = (char*)dst;
	from = (char*)src;
	while (i < n)
	{
		*(holder + i) = *(from + i);
		if (*(from + i) == c)
			return (holder + i + 1);
		i++;
	}
	return (NULL);
}
