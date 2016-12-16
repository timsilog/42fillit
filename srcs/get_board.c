/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:07:07 by tjose             #+#    #+#             */
/*   Updated: 2016/12/15 16:38:34 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		let_it_go(t_board *board)
{
	free(board->last_position);
	free(board->contents);
	free(board);
}

void		fill_dots(t_board *temp)
{
	int i;
	int j;

	i = -1;
	while (++i < temp->size)
	{
		j = -1;
		while (++j < temp->width - 1)
			temp->contents[i++] = '.';
		temp->contents[i] = '\n';
	}
	temp->contents[i] = '\0';
}

t_board		*init_board(int starting_size, int num_pieces)
{
	t_board	*temp;
	int		i;

	temp = malloc(sizeof(t_board));
	if (!temp)
		return (NULL);
	temp->last_position = (int*)malloc(sizeof(int) * num_pieces);
	temp->contents = (char*)malloc(sizeof(char) *
			(starting_size * (starting_size + 1) + 1));
	if (!temp->contents || !temp->last_position)
		return (NULL);
	temp->current_position = 0;
	temp->num_pieces = num_pieces;
	temp->width = starting_size + 1;
	temp->size = temp->width * starting_size;
	fill_dots(temp);
	i = -1;
	while (++i < num_pieces)
		temp->last_position[i] = 0;
	return (temp);
}

t_board		*get_board(int num_pieces)
{
	int		starting_size;
	t_board	*board;

	starting_size = ft_sqrt(num_pieces * 4);
	if ((starting_size * starting_size) < (num_pieces * 4))
		starting_size++;
	board = init_board(starting_size, num_pieces);
	if (!board)
		return (NULL);
	return (board);
}

t_board		*get_bigger_board(t_board *board)
{
	t_board	*temp;

	temp = init_board(board->width, board->num_pieces);
	if (!temp)
		return (NULL);
	let_it_go(board);
	return (temp);
}
