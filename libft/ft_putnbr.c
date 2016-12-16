/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:07:22 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 17:44:03 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursiveputnbr(long nb)
{
	int remainder;

	if (nb == 0)
		return ;
	recursiveputnbr(nb / 10);
	remainder = nb % 10;
	ft_putchar(remainder + '0');
}

void		ft_putnbr(int n)
{
	long holder;

	holder = n;
	if (holder == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (holder < 0)
	{
		ft_putchar('-');
		holder = -holder;
	}
	recursiveputnbr(holder);
}
