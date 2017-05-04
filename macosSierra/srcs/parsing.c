/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:57:11 by doriol            #+#    #+#             */
/*   Updated: 2017/05/04 18:41:46 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	pixel_put(char *pixel, int x, int y, int color)
{
	pixel += x * 4 + y * (4 * 1000);
	pixel[0] = color >> 16 & 0xff;
	pixel[1] = color >> 8 & 0xff;
	pixel[2] = color & 0xff;
}

int		actions_windows(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		exit(0);
	}
	return (0);
}

int		draw_line(int ox, int oy, int dx, int dy, char *pixel)
{
	t_drawline	*line;
	int			x;
	int			y;
	int			origin[2];
	int			dest[2];

	origin[0] = ox;
	origin[1] = oy;
	dest[0] = dx;
	dest[1] = dy;
	if (!(line = malloc(sizeof(t_drawline))))
		return (-1);
	line->i = 0;
	line->distance = sqrt(pow((dest[X] - origin[X]), 2) +
			pow((dest[Y] - origin[Y]), 2));
	while (line->i < line->distance)
	{
		line->ratio = (double)line->i / (double)line->distance;
		x = origin[X] + (dest[X] - origin[X]) * line->ratio;
		y = origin[Y] + (dest[Y] - origin[Y]) * line->ratio;
		pixel_put(pixel, x, y, (255 << 16) + (255 << 8) + (255));
		line->i++;
	}
	return (0);
}

/*int		parsing(int fd)
{
	char	str[100000];
	int		i;
	int		y;
	char	c;

	i = 0;
	y = 0;
	while (get_next_line(fd, &line))
	{
		tmp = str ? ft_strjoin(str, line) : line;
		if (str)
			free(str);
		str = tmp;
	}
	while (read(fd, &c, 1) != '\0')
		str[i++] = c;
	str[i] = '\0';
	return (0);
}*/

int		main(int a, char **v)
{
	int		fd;
	t_fdf	*fdf;
	char	*pixel;

	fdf = malloc(sizeof(t_fdf));
	fdf->z = 16;
	fdf->w = 4 * 1000;
	fdf->i = 0;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1000, 1000, "FDF");
	if (a == 2)
	{
		fd = open(v[1], O_RDONLY);
		//parsing(fd);
		close(fd);
	}
	fdf->image = mlx_new_image(fdf->mlx, 1000, 1000);
    pixel = mlx_get_data_addr(fdf->image, &fdf->z, &fdf->w, &fdf->i);
	draw_line(0, 0, 1000, 1000, pixel);
	draw_line(0, 1000, 1000, 0, pixel);
	draw_line(0, 500, 1000, 500, pixel);
	draw_line(500, 0, 500, 1000, pixel);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	mlx_key_hook(fdf->win, actions_windows, fdf);
	mlx_loop(fdf->mlx);
	free(fdf);
	return (0);
}
