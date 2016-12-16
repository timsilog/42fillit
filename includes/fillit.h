/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:43:22 by tjose             #+#    #+#             */
/*   Updated: 2016/12/15 18:13:53 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_board
{
	int			*last_position;
	int			width;
	char		*contents;
	int			current_position;
	int			num_pieces;
	int			size;
}				t_board;
int				is_valid(char *board);
int				is_safe(t_board *board, int *piece);
int				**get_pieces(char *src, int num_pieces, int starting_width);
void			adjust_pieces(int **pieces, int old_width,
		int new_width, int num_pieces);
void			place_piece(t_board *board, int *piece, int current_piece);
void			remove_piece(t_board *board, int *piece);
void			let_it_go(t_board *board);
void			clear_pieces(int **pieces, int num_pieces);
t_board			*get_board(int num_pieces);
t_board			*get_bigger_board(t_board *board);

#endif
