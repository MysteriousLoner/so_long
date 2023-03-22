/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:49:33 by yalee             #+#    #+#             */
/*   Updated: 2023/03/22 19:48:37 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_vchar(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E' || c == 'H')
		return (1);
	return (0);
}

int	is_good_map(char **map)
{
	int	x;
	int	y;
	int	total;

	total = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && is_vchar(map[y][x]))
		{
			total++;
			x++;
		}
		y++;
	}
	y = 0;
	x = 0;
	while (map[y][x])
		x++;
	while (map[y])
		y++;
	if (total != x * y)
		return (1);
	return (0);
}

void	restore(t_program *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map[i])
	{
		j = 0;
		while (a->map[i][j])
		{
			if (a->map[i][j] == '3')
				a->map[i][j] = '0';
			if (a->map[i][j] == '4')
				a->map[i][j] = 'C';
			if (a->map[i][j] == '5')
				a->map[i][j] = 'E';
			if (a->map[i][j] == '6')
				a->map[i][j] = '2';
			j++;
		}
		i++;
	}
}

void	valid_c(t_program *a, int i, int j, int *c)
{
	if (a->t != *c)
		return ;
	if (i < 1 || j < 1 || a->height < i || a->len < j)
		return ;
	if (a->map[i][j] == '3' || a->map[i][j] == 'E' || a->map[i][j] == '1' || \
	a->map[i][j] == '4' || a->map[i][j] == '5' || a->map[i][j] == '6')
		return ;
	if (a->map[i][j] == 'P')
	{
		(*c)++;
		return ;
	}
	if (a->map[i][j] == 'C')
		a->map[i][j] = '4';
	if (a->map[i][j] == 'E')
		a->map[i][j] = '5';
	if (a->map[i][j] == '2')
		a->map[i][j] = '6';
	if (a->map[i][j] == '0')
		a->map[i][j] = '3';
	valid_c(a, i - 1, j, c);
	valid_c(a, i + 1, j, c);
	valid_c(a, i, j - 1, c);
	valid_c(a, i, j + 1, c);
}

int	collect(t_program *a)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (a->map[i])
	{
		j = 0;
		while (a->map[i][j])
		{
			if (a->map[i][j] == 'C')
			{
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}
