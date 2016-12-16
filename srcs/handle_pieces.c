/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:39:26 by tjose             #+#    #+#             */
/*   Updated: 2016/12/15 17:37:35 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_safe(t_board *board, int *piece)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (board->current_position + piece[i] > board->size)
			return (0);
		if (board->contents[board->current_position + piece[i]] != '.')
			return (0);
	}
	return (1);
}

void	place_piece(t_board *board, int *piece, int current_piece)
{
	int i;

	i = -1;
	while (++i < 4)
		board->contents[board->current_position +
			piece[i]] = current_piece + 'A';
}

void	remove_piece(t_board *board, int *piece)
{
	int i;

	i = -1;
	while (++i < 4)
		board->contents[board->current_position + piece[i]] = '.';
}
