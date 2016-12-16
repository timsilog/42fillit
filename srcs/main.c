/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:51:13 by tjose             #+#    #+#             */
/*   Updated: 2016/12/15 18:12:44 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		handle_end(t_board **board, int *current_piece, int **pieces)
{
	(*board)->current_position = (*board)->last_position[*current_piece];
	if (*current_piece < 0)
	{
		adjust_pieces(pieces, (*board)->width,
				(*board)->width + 1, (*board)->num_pieces);
		if (!(*board = get_bigger_board(*board)))
			return (0);
		(*current_piece)++;
	}
	else
	{
		remove_piece(*board, pieces[*current_piece]);
		(*board)->current_position++;
	}
	return (1);
}

int		is_solved(t_board *board, int **pieces, int current_piece)
{
	place_piece(board, pieces[current_piece], current_piece);
	board->last_position[current_piece] = board->current_position;
	board->current_position = 0;
	while (board->contents[board->current_position] != '.'
			&& board->contents[board->current_position])
		board->current_position++;
	board->current_position--;
	if (current_piece + 1 == board->num_pieces)
	{
		ft_putstr(board->contents);
		let_it_go(board);
		return (1);
	}
	return (0);
}

int		fill_board(t_board *board, int **pieces)
{
	int		current_piece;

	current_piece = 0;
	while (1)
	{
		if (is_safe(board, pieces[current_piece]))
		{
			if (is_solved(board, pieces, current_piece))
				return (1);
			current_piece++;
		}
		board->current_position++;
		if (!board->contents[board->current_position])
		{
			current_piece--;
			if (!handle_end(&board, &current_piece, pieces))
				return (0);
		}
	}
	return (1);
}

void	prepare_pieces(char *all_pieces)
{
	int		**pieces;
	t_board	*board;
	int		num_pieces;

	num_pieces = (ft_strlen(all_pieces) + 1) / 21;
	board = get_board(num_pieces);
	if (board == NULL)
	{
		ft_putstr("error\n");
		return ;
	}
	pieces = get_pieces(all_pieces, num_pieces, board->width);
	if (!fill_board(board, pieces))
		ft_putstr("error\n");
	clear_pieces(pieces, num_pieces);
}

int		main(int argc, char **argv)
{
	char	buff[550];
	int		fd;
	int		ret;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	ret = read(fd, buff, 600);
	buff[ret] = '\0';
	if (!is_valid(buff))
	{
		ft_putstr("error\n");
		return (1);
	}
	prepare_pieces(buff);
	close(fd);
}
