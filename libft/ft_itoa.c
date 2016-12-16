/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:23:11 by tjose             #+#    #+#             */
/*   Updated: 2016/12/01 17:31:22 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long n)
{
	int		i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*get_num(char *s, long n, int flag)
{
	int		i;
	int		len;

	i = 0;
	len = num_len(n) + flag;
	s[len--] = '\0';
	while (len >= 0)
	{
		s[len--] = n % 10 + '0';
		n /= 10;
	}
	if (flag)
		s[0] = '-';
	return (s);
}

char		*ft_itoa(int n)
{
	int		neg_flag;
	int		i;
	char	*s;
	long	nb;

	i = 0;
	neg_flag = 0;
	nb = n;
	if (nb < 0)
	{
		neg_flag++;
		nb = -nb;
	}
	if (neg_flag)
		s = (char*)malloc(sizeof(char) * num_len(nb) + 2);
	else
		s = (char*)malloc(sizeof(char) * num_len(nb) + 1);
	if (!s)
		return (NULL);
	return (get_num(s, nb, neg_flag));
}
