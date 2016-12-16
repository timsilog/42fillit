/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:55:02 by tjose             #+#    #+#             */
/*   Updated: 2016/12/15 17:11:15 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_double(char *board, int i)
{
	int		flag;

	flag = 0;
	if (i + 5 < (int)ft_strlen(board))
	{
		if (board[i + 5] == '#')
			flag++;
	}
	if (i - 5 >= 0)
	{
		if (board[i - 5] == '#')
			flag++;
	}
	if (i + 1 < (int)ft_strlen(board))
	{
		if (board[i + 1] == '#')
			flag++;
	}
	if (i - 1 >= 0)
	{
		if (board[i - 1] == '#')
			flag++;
	}
	return (flag > 1);
}

int		check_hash(char *board, int i)
{
	if (i + 5 < (int)ft_strlen(board))
	{
		if (board[i + 5] == '#')
			return (1);
	}
	if (i - 5 >= 0)
	{
		if (board[i - 5] == '#')
			return (1);
	}
	if (i + 1 < (int)ft_strlen(board))
	{
		if (board[i + 1] == '#')
			return (1);
	}
	if (i - 1 >= 0)
	{
		if (board[i - 1] == '#')
			return (1);
	}
	return (0);
}

int		row_check(char *board, int *i, int *hash_flag, int *hash_count)
{
	int width;

	width = -1;
	while (++width < 4)
	{
		if (board[*i] != '.' && board[*i] != '#')
			return (0);
		if (board[*i] == '#')
		{
			(*hash_count)++;
			if (!check_hash(board, *i))
				return (0);
			*hash_flag += check_double(board, *i);
		}
		(*i)++;
	}
	return (1);
}

int		valid_piece(char *board, int *i)
{
	int height;
	int hash_flag;
	int hash_count;

	hash_count = 0;
	if (!board[*i])
		return (0);
	height = 0;
	hash_flag = 0;
	while (board[*i] && (height < 4))
	{
		if (!row_check(board, i, &hash_flag, &hash_count))
			return (0);
		if (board[*i] != '\n')
			return (0);
		(*i)++;
		height++;
	}
	if (height != 4 || !hash_flag || hash_count != 4)
		return (0);
	return (1);
}

int		is_valid(char *board)
{
	int i;

	i = 0;
	if (!board[i])
		return (0);
	while (board[i])
	{
		if (i)
		{
			if (board[i] != '\n')
				return (0);
			i++;
		}
		if (!valid_piece(board, &i))
			return (0);
	}
	return (1);
}
