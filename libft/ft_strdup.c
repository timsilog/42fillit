/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 12:21:36 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 17:45:41 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*holder;

	holder = (char*)malloc(ft_strlen(src) + 1);
	if (holder == NULL)
		return (NULL);
	holder = ft_strcpy(holder, src);
	return (holder);
}
