/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 02:07:15 by doriol            #+#    #+#             */
/*   Updated: 2017/05/11 05:43:34 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_parsing		*draw_x(t_fdf *fdf, t_parsing *parsing, int i)
{
	fdf->ox = parsing->x;
	fdf->oy = parsing->y - parsing->height * parsing->parsing[i];
	fdf->dx = parsing->x + (1000 / one(parsing) / 2);
	fdf->dy = parsing->y + (1000 / one(parsing) / 2) -
		parsing->height * parsing->parsing[i + 1];
	if (parsing->parsing[i + 1] * parsing->height > 0 ||
			parsing->parsing[i] * parsing->height > 0)
		draw_line(fdf, 255, 0, 0);
	else if (parsing->parsing[i + 1] * parsing->height < 0 ||
			parsing->parsing[i] * parsing->height < 0)
		draw_line(fdf, 0, 255, 0);
	else
		draw_line(fdf, 0, 0, 255);
	return (parsing);
}

t_parsing		*draw_y(t_fdf *fdf, t_parsing *parsing, int i)
{
	fdf->ox = parsing->x;
	fdf->oy = parsing->y - parsing->height * parsing->parsing[i];
	fdf->dx = parsing->x - (1000 / one(parsing) / 2);
	fdf->dy = parsing->y + (1000 / one(parsing) / 2) - parsing->height *
		parsing->parsing[(int)i + (int)parsing->largeur];
	if (parsing->parsing[(int)i +
			(int)parsing->largeur] * parsing->height > 0 ||
			parsing->parsing[i] * parsing->height > 0)
		draw_line(fdf, 255, 0, 0);
	else if (parsing->parsing[(int)i +
			(int)parsing->largeur] * parsing->height < 0 ||
			parsing->parsing[i] * parsing->height < 0)
		draw_line(fdf, 0, 255, 0);
	else
		draw_line(fdf, 0, 0, 255);
	return (parsing);
}

t_parsing		*init_window(t_parsing *parsing, t_fdf *fdf)
{
	int		i;
	int		line;

	i = 0;
	parsing->x = parsing->xpos + (1000 / one(parsing) / 2) * parsing->hauteur;
	parsing->y = parsing->ypos + 0;
	while (i < (parsing->hauteur * parsing->largeur))
	{
		if ((i + 1) % (int)parsing->largeur)
			draw_x(fdf, parsing, i);
		if (i / parsing->largeur + 1 < (parsing->largeur
					* parsing->hauteur) / parsing->largeur)
			draw_y(fdf, parsing, i);
		parsing->x += (1000 / one(parsing) / 2);
		parsing->y += (1000 / one(parsing) / 2);
		line = i / parsing->largeur + 1;
		if ((i + 1) % (int)parsing->largeur == 0)
		{
			parsing->x = parsing->xpos + ((1000 / one(parsing) / 2)
					* parsing->hauteur) + -(1000 / one(parsing) / 2) * line;
			parsing->y = parsing->ypos + 0 + (1000 / one(parsing) / 2) * line;
		}
		i++;
	}
	return (parsing);
}
