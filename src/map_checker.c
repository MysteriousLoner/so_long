/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:48:44 by yalee             #+#    #+#             */
/*   Updated: 2023/03/23 00:37:07 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mapsize(t_program *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map[i])
	{
		j = 0;
		while (a->map[i][j])
			j++;
		i++;
	}
	if (i == j)
		return (1);
	a->len = j;
	a->height = i;
	return (0);
}

int	validity(t_program *a)
{
	a->e.c = 0;
	a->e.e = 0;
	a->e.p = 0;
	a->e.i = 0;
	a->e.h = 0;
	while (a->map[a->e.i])
	{
		a->e.j = 0;
		while (a->map[a->e.i][a->e.j])
		{
			if (a->map[a->e.i][a->e.j] == 'C')
				a->e.c++;
			if (a->map[a->e.i][a->e.j] == 'P')
				a->e.p++;
			if (a->map[a->e.i][a->e.j] == 'E')
				a->e.e++;
			if (a->map[a->e.i][a->e.j] == 'H')
				a->e.h++;
			a->e.j++;
		}
		a->e.i++;
	}
	if (a->e.c < 1 || a->e.p != 1 || a->e.e < 1 || a->e.h > 1)
		return (1);
	return (0);
}

int	colwall(t_program *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (a->map[i])
	{
		j = 0;
		if (a->map[i][j] != '1')
			return (1);
		while (a->map[i][j])
			j++;
		if (a->map[i][j - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	rowwall(t_program *a)
{
	int	i;
	int	j;

	i = 0;
	while (a->map[i])
	{
		j = 0;
		if (i == 0)
		{
			while (a->map[i][j])
			{
				if (a->map[i][j] != '1')
					return (1);
				j++;
			}
		}
		i++;
	}
	j = -1;
	while (a->map[i - 1][++j])
		if (a->map[i - 1][j] != '1')
			return (1);
	return (0);
}

int	ft_error(t_program *a)
{
	if (mapsize(a) == 1)
		return (1);
	if (validity(a) == 1)
		return (1);
	if (rowwall(a) == 1)
		return (1);
	if (colwall(a) == 1)
		return (1);
	if (evalid(a) == 1)
		return (1);
	if (is_good_map(a->map))
		return (1);
	return (0);
}
