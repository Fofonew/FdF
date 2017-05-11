/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:57:11 by doriol            #+#    #+#             */
/*   Updated: 2017/05/11 06:01:04 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pixel_put(char *pixel, int x, int y, int color)
{
	pixel += x * 4 + y * (4 * 1000);
	pixel[0] = color >> 16 & 0xff;
	pixel[1] = color >> 8 & 0xff;
	pixel[2] = color & 0xff;
}

int			draw_line(t_fdf *fdf, int a, int b, int c)
{
	t_drawline	*line;
	float		x;
	float		y;
	float		origin[2];
	float		dest[2];

	origin[0] = fdf->ox;
	origin[1] = fdf->oy;
	dest[0] = fdf->dx;
	dest[1] = fdf->dy;
	if (!(line = malloc(sizeof(t_drawline))))
		put_error("Malloc failed\n");
	line->i = 0;
	line->distance = sqrt(pow((dest[X] - origin[X]), 2) +
			pow((dest[Y] - origin[Y]), 2));
	while (line->i < line->distance)
	{
		line->ratio = (double)line->i / (double)line->distance;
		x = origin[X] + (dest[X] - origin[X]) * line->ratio;
		y = origin[Y] + (dest[Y] - origin[Y]) * line->ratio;
		if (x >= 0 && x < 1000 && y >= 0 && y < 1000)
			pixel_put(fdf->pixel, x, y, (c << 16) + (b << 8) + (a));
		line->i++;
	}
	return (0);
}

t_parsing	*parsing_int(int fd, t_parsing *parsing)
{
	int			i;
	int			y;
	char		**tab;
	char		*tmp;

	y = 0;
	if (!(parsing->parsing = malloc(sizeof(int) * (parsing->hauteur
						* parsing->largeur))))
		put_error("Malloc failed\n");
	while (get_next_line(fd, &tmp))
	{
		i = 0;
		tab = ft_strsplit(tmp, ' ');
		while (tab[i])
		{
			parsing->parsing[y] = ft_atoi(tab[i]);
			i++;
			y++;
		}
		free(tab);
	}
	return (parsing);
}

void		make_window(t_parsing *parsing, float height, int x, int y)
{
	t_fdf		*fdf;
	static	int	i;

	if (!(fdf = malloc(sizeof(t_fdf))))
		put_error("Malloc failed\n");
	fdf->z = 32;
	fdf->w = 4 * 1000;
	fdf->i = 0;
	parsing->image = mlx_new_image(parsing->mlx, 1000, 1000);
	fdf->pixel = mlx_get_data_addr(parsing->image, &fdf->z, &fdf->w, &fdf->i);
	fdf->finish = parsing->parsing;
	parsing->height = height;
	parsing->xpos = x;
	parsing->ypos = y;
	init_window(parsing, fdf);
	mlx_put_image_to_window(parsing->mlx, parsing->win, parsing->image, 0, 0);
	mlx_string_put(parsing->mlx, parsing->win, 2, 2, 0x00E71B3D, "FdF PROJECT");
	mlx_key_hook(parsing->win, actions_windows, parsing);
	if (i == 0)
		system("afplay ./srcs/son.mp3 & ");
	i = 1;
	mlx_loop(parsing->mlx);
	free(fdf);
	free(parsing);
}

int			main(int a, char **v)
{
	int			fd;
	int			fd2;
	int			fd3;
	t_parsing	*parsing;

	if (!(parsing = malloc(sizeof(t_parsing))))
		put_error("Malloc failed\n");
	if (a == 2)
	{
		fd = open(v[1], O_RDONLY);
		fd2 = open(v[1], O_RDONLY);
		fd3 = open(v[1], O_RDONLY);
		check_error_read(fd3);
		check_error(fd2, parsing);
		parsing_int(fd, parsing);
		parsing->mlx = mlx_init();
		parsing->win = mlx_new_window(parsing->mlx, 1000, 1000, "FDF");
		make_window(parsing, 0.05, 0, 0);
		close(fd);
		close(fd2);
		close(fd3);
	}
	else
		put_error("Invalid number's file.\n");
	return (0);
}
