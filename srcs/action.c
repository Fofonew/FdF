/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 02:41:37 by doriol            #+#    #+#             */
/*   Updated: 2017/05/11 06:00:00 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			actions_windows(int keycode, void *param)
{
	t_parsing	*fdf;

	fdf = (t_parsing*)param;
	if (keycode == 53)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		system("killall afplay");
		exit(0);
	}
	if (keycode == 69 || keycode == 24)
		make_window(fdf, fdf->height + 0.25, fdf->xpos, fdf->ypos);
	if (keycode == 78 || keycode == 27)
		make_window(fdf, fdf->height - 0.25, fdf->xpos, fdf->ypos);
	if (keycode == 124)
		make_window(fdf, fdf->height, fdf->xpos + 10, fdf->ypos);
	if (keycode == 123)
		make_window(fdf, fdf->height, fdf->xpos - 10, fdf->ypos);
	if (keycode == 125)
		make_window(fdf, fdf->height, fdf->xpos, fdf->ypos + 10);
	if (keycode == 126)
		make_window(fdf, fdf->height, fdf->xpos, fdf->ypos - 10);
	return (0);
}
