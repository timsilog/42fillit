/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 21:16:03 by tjose             #+#    #+#             */
/*   Updated: 2016/12/01 16:54:25 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*a1;
	const unsigned char	*a2;
	int					i;

	a1 = (const unsigned char*)s1;
	a2 = (const unsigned char*)s2;
	i = 0;
	while (a1[i] == a2[i] && a1[i] && a2[i])
		i++;
	return (a1[i] - a2[i]);
}
