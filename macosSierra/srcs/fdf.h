/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:07:32 by doriol            #+#    #+#             */
/*   Updated: 2017/05/04 18:41:42 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdio.h>
# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# define X 0
# define Y 1

typedef struct	s_fdf
{
	void		*win;
	void		*mlx;
	void		*image;
	int			w;
	int			z;
	int			i;
}				t_fdf;

typedef struct	s_drawline
{
	double		ratio;
	int			distance;
	int			i;
}				t_drawline;

#endif
