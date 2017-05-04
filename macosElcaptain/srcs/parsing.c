/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:57:11 by doriol            #+#    #+#             */
/*   Updated: 2017/05/03 20:47:06 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int		parsing(int fd)
{
	char	str[100000];
	int		i;
	int		y;
	char	c;

	i = 0;
	y = 0;
//	while (get_next_line(fd, &line))
//	{
		//tmp = str ? ft_strjoin(str, line) : line;
		//if (str)
		//	free(str);
		//str = tmp;
//		tab
//	}
	while (read(fd, &c, 1) != '\0')
		str[i++] = c;
	str[i] = '\0';
//	tab = ft_strsplit(
	printf("%s\n", str);
	return (0);
}

int		main(int a, char **v)
{
	int		fd;
	t_fdf	*fdf;
	void	*image;
	char	*test;
	int		w;
	int		z;
	int		i;

	z = 32;
	w = 7680;
	i = 0;
	fdf = malloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "FDF");
	if (a == 2)
	{
		fd = open(v[1], O_RDONLY);
		parsing(fd);
		close(fd);
	}
	image = mlx_new_image(fdf->mlx, 500, 500);
    test = mlx_get_data_addr (image, &z, &w, &i);
	printf("%s\n", test);
	mlx_put_image_to_window(fdf->mlx, fdf->win, image, 500, 500);
	mlx_key_hook(fdf->win, actions_windows, fdf);
	mlx_loop(fdf->mlx);
	free(fdf);
	return (0);
}
