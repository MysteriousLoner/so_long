/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_physics_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:36:28 by yalee             #+#    #+#             */
/*   Updated: 2023/03/23 00:51:08 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gg(void)
{
	ft_printf("Droge ate you!\n");
	exit(0);
}

int	is_wall(int valx, int valy, t_program *program)
{
	if (program->map[valy / 64][valx / 64] == 'H')
		gg();
	if (program->map[valy / 64][valx / 64] == '1')
		return (1);
	if (program->map[valy / 64][valx / 64] == 'C')
	{
		program->loot_count += 1;
		program->map[valy / 64][valx / 64] = '0';
		if (program->loot_count == program->loot_num)
			program->isdone = 1;
		return (1);
	}
	if (program->loot_count == program->loot_num)
		program->isdone = 1;
	if (program->map[valy / 64][valx / 64] == 'E' && program->isdone == 0)
		return (1);
	if (program->map[valy / 64][valx / 64] == 'E' && program->isdone == 1)
		quitting(program);
	return (0);
}

int	valid(char m, t_vector v, t_program *program)
{
	if (m == 'r')
	{
		if (is_wall(v.x + 64, v.y, program))
			return (0);
	}
	else if (m == 'l')
	{
		if (is_wall(v.x - 64, v.y, program))
			return (0);
	}
	else if (m == 'u')
	{
		if (is_wall(v.x, v.y - 64, program))
			return (0);
	}
	else if (m == 'd')
	{
		if (is_wall(v.x, v.y + 64, program))
			return (0);
	}
	return (1);
}

int	is_car(int valx, int valy, t_program *program)
{
	if (program->map[valy / 64][valx / 64] == 'E')
		return (1);
	return (0);
}

int	is_wall_e(int valx, int valy, t_program *program)
{
	if (program->map[valy / 64][valx / 64] == '1')
		return (1);
	if (program->map[valy / 64][valx / 64] == 'C')
		return (1);
	if (program->map[valy / 64][valx / 64] == 'E')
		return (1);
	if (program->map[valy / 64][valx / 64] == 'P')
		gg();
	return (0);
}
