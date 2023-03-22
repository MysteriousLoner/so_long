/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:34:28 by yalee             #+#    #+#             */
/*   Updated: 2023/03/22 19:28:32 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_win_size(char **map, t_window *window)
{
	int	xn;
	int	yn;

	xn = 0;
	yn = 0;
	while (map[yn][xn])
		xn++;
	while (map[yn])
		yn++;
	window->size.x = xn * 64;
	window->size.y = yn * 64;
}

t_vector	get_pos(char **map, char c)
{
	t_vector	v;
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				v.x = j * 64;
				v.y = i * 64;
			}
			j++;
		}
		i++;
	}
	return (v);
}
