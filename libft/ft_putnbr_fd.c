/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:05:30 by tjose             #+#    #+#             */
/*   Updated: 2016/11/30 14:04:36 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursiveputnbr(long nb, int fd)
{
	int remainder;

	if (nb == 0)
		return ;
	recursiveputnbr(nb / 10, fd);
	remainder = nb % 10;
	ft_putchar_fd(remainder + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long holder;

	holder = n;
	if (holder == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (holder < 0)
	{
		ft_putchar_fd('-', fd);
		holder = -holder;
	}
	recursiveputnbr(holder, fd);
}
