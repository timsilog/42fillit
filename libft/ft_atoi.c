/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 19:34:44 by tjose             #+#    #+#             */
/*   Updated: 2016/11/28 17:44:04 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	num;
	int		count;
	int		neg_flag;

	count = 0;
	num = 0;
	neg_flag = 0;
	while (ft_is_wp(str[count]))
		count++;
	if (str[count] == '-')
	{
		neg_flag = 1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while (ft_isdigit(str[count]))
	{
		num *= 10;
		num += (str[count] - 48);
		count++;
	}
	if (neg_flag)
		num = -num;
	return (num);
}
