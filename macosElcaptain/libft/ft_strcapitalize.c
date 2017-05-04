/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 21:08:48 by doriol            #+#    #+#             */
/*   Updated: 2017/04/16 03:06:53 by doriol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[0] >= 97) && (str[0] <= 122))
			str[0] = str[0] - 32;
		if ((str[i] >= 97) && (str[i] <= 122))
		{
			if ((str[i - 1] < 97 || str[i - 1] > 122)
				&& (str[i - 1] < 65 || str[i - 1] > 90))
				str[i] = str[i] - 32;
		}
		if ((str[i] >= 65) && (str[i] <= 90))
		{
			if (((str[i - 1] >= 97) && (str[i - 1] <= 122))
				|| ((str[i - 1] >= 65) && (str[i - 1] <= 90))
				|| ((str[i - 1] >= 48) && (str[i - 1] <= 57)))
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}