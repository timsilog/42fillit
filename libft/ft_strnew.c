/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:42:54 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 19:44:36 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;
	size_t	i;

	i = 0;
	fresh = (char*)malloc(sizeof(char) * size + 1);
	if (!fresh)
		return (NULL);
	while (i < size + 1)
		fresh[i++] = '\0';
	return (fresh);
}
