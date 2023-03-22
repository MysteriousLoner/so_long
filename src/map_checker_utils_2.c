/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:45:08 by yalee             #+#    #+#             */
/*   Updated: 2023/03/22 19:48:48 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_e(t_program *a, int i, int j, int *e)
{
	if (*e > 0)
		return ;
	if (i < 1 || j < 1 || a->height < i || a->len < j)
		return ;
	if (a->map[i][j] == '3' || a->map[i][j] == '1' || \
	a->map[i][j] == '4' || a->map[i][j] == '5' || a->map[i][j] == '6')
		return ;
	if (a->map[i][j] == 'P')
	{
		(*e)++;
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
	valid_e(a, i - 1, j, e);
	valid_e(a, i + 1, j, e);
	valid_e(a, i, j - 1, e);
	valid_e(a, i, j + 1, e);
}

void	safety(t_program *a, int i, int j, int *c)
{
	a->t = *c;
	valid_c(a, i, j, c);
}

int	evalid(t_program *a)
{
	int	i;
	int	j;
	int	c;
	int	e;

	i = -1;
	c = 0;
	e = 0;
	while (a->map[++i])
	{
		j = -1;
		while (a->map[i][++j])
		{
			if (a->map[i][j] == 'C')
				safety(a, i, j, &c);
			restore(a);
			if (a->map[i][j] == 'E')
				valid_e(a, i, j, &e);
			restore(a);
		}
	}
	if (c != collect(a) || e <= 0)
		return (1);
	return (0);
}
