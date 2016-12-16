/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:45:05 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 17:00:36 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list *temp;
	t_list *head;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	head = temp;
	lst = lst->next;
	while (lst)
	{
		temp->next = f(lst);
		temp = temp->next;
		lst = lst->next;
	}
	return (head);
}
