/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 20:14:39 by doriol            #+#    #+#             */
/*   Updated: 2017/05/11 05:42:23 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			put_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

void			check_error_read(int fd)
{
	char	c;
	int		rd;

	while ((rd = read(fd, &c, 1)))
		if (rd == -1)
			put_error("Not valid file.\n");
}

t_parsing		*check_error(int fd2, t_parsing *parsing)
{
	int		l;
	int		h;
	int		x;
	char	*tmp;
	char	**tab;

	l = 0;
	h = 0;
	x = 0;
	while (get_next_line(fd2, &tmp))
	{
		tab = ft_strsplit(tmp, ' ');
		while (tab[l])
			l++;
		h++;
		if (h == 1)
			x = l;
		if (l != x)
			put_error("Not valid file.\n");
		l = 0;
	}
	parsing->largeur = x;
	parsing->hauteur = h;
	return (parsing);
}

float			one(t_parsing *parsing)
{
	int	i;

	i = parsing->hauteur > parsing->largeur ?
		parsing->hauteur : parsing->largeur;
	return (i);
}
