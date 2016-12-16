/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:06:36 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 19:34:22 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	loop_check(int nb)
{
	int	guess;

	guess = 5;
	while (guess * guess <= nb)
	{
		if (nb % 3 == 0)
			return (0);
		if (nb % guess == 0)
			return (0);
		if (nb % (guess + 2) == 0)
			return (0);
		guess += 6;
	}
	return (1);
}

int			ft_isprime(int nb)
{
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 3 == 0 || nb % 2 == 0 || nb < 2)
		return (0);
	if (!loop_check(nb))
		return (0);
	return (1);
}
