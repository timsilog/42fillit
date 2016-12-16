/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:12:13 by tjose             #+#    #+#             */
/*   Updated: 2016/12/01 15:28:55 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *a;

	a = (char*)malloc(sizeof(char) * size);
	if (!a)
		return (NULL);
	else
		a = ft_memset(a, 0, size);
	return (a);
}
