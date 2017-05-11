/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:07:32 by doriol            #+#    #+#             */
/*   Updated: 2017/05/11 05:59:52 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdio.h>
# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# define X 0
# define Y 1

typedef struct	s_fdf
{
	void		*image;
	int			*finish;
	int			w;
	int			z;
	int			i;
	char		*pixel;
	float		ox;
	float		oy;
	float		dx;
	float		dy;
}				t_fdf;

typedef struct	s_parsing
{
	void		*mlx;
	void		*win;
	int			*parsing;
	void		*image;
	float		height;
	float		x;
	float		y;
	int			xpos;
	int			ypos;
	float		largeur;
	float		hauteur;
}				t_parsing;

typedef struct	s_drawline
{
	double		ratio;
	float		distance;
	float		i;
}				t_drawline;

int				actions_windows(int keycode, void *param);
void			make_window(t_parsing *parsing, float height, int x, int y);
void			pixel_put(char *pixel, int x, int y, int color);
int				draw_line(t_fdf *fdf, int a, int b, int c);
t_parsing		*parsing(int fd);
t_parsing		*init_window(t_parsing *parsing, t_fdf *fdf);
t_parsing		*draw_x(t_fdf *fdf, t_parsing *parsing, int i);
t_parsing		*draw_y(t_fdf *fdf, t_parsing *parsing, int i);
t_parsing		*check_error(int fd2, t_parsing *parsing);
void			put_error(char *str);
void			check_error_read(int fd);
float			one(t_parsing *parsing);

#endif
