/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_physics_functions_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:26:34 by yalee             #+#    #+#             */
/*   Updated: 2023/03/22 19:50:44 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_enemy(char m, t_vector v, t_program *program)
{
	if (m == 'r')
	{
		if (is_wall_e(v.x + 64, v.y, program))
			return (0);
	}
	else if (m == 'l')
	{
		if (is_wall_e(v.x - 64, v.y, program))
			return (0);
	}
	else if (m == 'u')
	{
		if (is_wall_e(v.x, v.y - 64, program))
			return (0);
	}
	else if (m == 'd')
	{
		if (is_wall_e(v.x, v.y + 64, program))
			return (0);
	}
	return (1);
}
