/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:07:12 by tjose             #+#    #+#             */
/*   Updated: 2016/12/15 18:12:37 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_lm(char *src)
{
	int i;
	int lm;
	int	hash1;
	int current_col;

	i = -1;
	hash1 = 1;
	while (++i < 20)
	{
		if (src[i] == '#' && hash1)
		{
			hash1--;
			lm = i - (5 * (i / 5));
			i++;
		}
		if (src[i] == '#')
		{
			current_col = i - (5 * (i / 5));
			if (current_col < lm)
				lm = current_col;
		}
	}
	return (lm);
}

int		*get_next_piece(char *src, int *piece)
{
	int		current_pos;
	int		zero_pos;
	int		leftmost;
	int		current_hash;

	current_pos = -1;
	current_hash = 0;
	leftmost = get_lm(src);
	while (++current_pos < 20)
	{
		if (src[current_pos] == '#' && current_hash == 0)
		{
			if (current_pos > 4)
				zero_pos = current_pos - (current_pos % 5 - leftmost % 5);
			else
				zero_pos = current_pos - (current_pos - leftmost);
			piece[current_hash] = current_pos - zero_pos;
			current_hash++;
			current_pos++;
		}
		if (src[current_pos] == '#')
			piece[current_hash++] = current_pos - zero_pos;
	}
	return (piece);
}

int		**get_pieces(char *src, int num_pieces, int starting_width)
{
	int		**all_pieces;
	int		i;
	int		j;

	all_pieces = (int**)malloc(sizeof(int*) * num_pieces);
	i = -1;
	j = 0;
	while (++i < num_pieces)
	{
		all_pieces[i] = (int*)malloc(sizeof(int) * 4);
		all_pieces[i] = get_next_piece(&src[j], all_pieces[i]);
		j += 21;
	}
	if (starting_width != 5)
		adjust_pieces(all_pieces, 5, starting_width, num_pieces);
	return (all_pieces);
}

void	clear_pieces(int **pieces, int num_pieces)
{
	int i;

	i = -1;
	while (++i < num_pieces)
		free(pieces[i]);
	free(pieces);
}
