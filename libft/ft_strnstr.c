/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:21:40 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 15:59:31 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	int		j;
	size_t	r_address;

	i = 0;
	if (!to_find[i])
		return ((char*)str);
	while (str[i] && i < n)
	{
		j = 0;
		if (str[i] == to_find[0])
		{
			r_address = i;
			while (to_find[j] != '\0' && (i + j < n))
			{
				if (to_find[j] != str[i + j])
					break ;
				j++;
			}
			if (to_find[j] == '\0')
				return ((char*)&str[r_address]);
		}
		i++;
	}
	return (0);
}
