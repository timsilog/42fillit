/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:24:38 by tjose             #+#    #+#             */
/*   Updated: 2016/12/15 16:37:37 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	adjust_up(int **pieces, int old_width, int new_width, int num_pieces)
{
	int i;
	int j;

	while (old_width < new_width)
	{
		i = -1;
		while (++i < num_pieces)
		{
			j = -1;
			while (++j < 4)
				pieces[i][j] += pieces[i][j] / old_width;
		}
		old_width++;
	}
}

void	adjust_down(int **pieces, int old_width, int new_width, int num_pieces)
{
	int i;
	int j;

	while (old_width > new_width)
	{
		i = -1;
		while (++i < num_pieces)
		{
			j = -1;
			while (++j < 4)
				pieces[i][j] -= pieces[i][j] / old_width;
		}
		old_width--;
	}
}

void	adjust_pieces(int **pieces, int old_width,
		int new_width, int num_pieces)
{
	if (new_width > old_width)
		adjust_up(pieces, old_width, new_width, num_pieces);
	else
		adjust_down(pieces, old_width, new_width, num_pieces);
}
