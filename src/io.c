/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:38:29 by yalee             #+#    #+#             */
/*   Updated: 2023/03/23 01:04:57 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_program *program)
{
	int	mode;

	if (program->enemynum == 0)
		return ;
	mode = rand() % 4;
	program->map[program->enemies_pos.y / 64]
	[program->enemies_pos.x / 64] = '0';
	if (mode == 0 && valid_enemy('r', program->enemies_pos, program))
		program->enemies_pos.x += 64;
	else if (mode == 1 && valid_enemy('l', program->enemies_pos, program))
		program->enemies_pos.x -= 64;
	else if (mode == 2 && valid_enemy('d', program->enemies_pos, program))
		program->enemies_pos.y += 64;
	else if (mode == 3 && valid_enemy('u', program->enemies_pos, program))
		program->enemies_pos.y -= 64;
	program->map[program->enemies_pos.y / 64]
	[program->enemies_pos.x / 64] = 'H';
}

int	ft_input(int key, t_program *program)
{
	program->map[program->player_pos.y / 64][program->player_pos.x / 64] = '0';
	if (key == 53)
		exit(0);
	else if (key == 124 && valid('r', program->player_pos, program))
		program->player_pos.x += program->player.size.x;
	else if (key == 123 && valid('l', program->player_pos, program))
		program->player_pos.x -= program->player.size.x;
	else if (key == 125 && valid('d', program->player_pos, program))
		program->player_pos.y += program->player.size.y;
	else if (key == 126 && valid('u', program->player_pos, program))
		program->player_pos.y -= program->player.size.y;
	if (program->isdone == 1 && is_car(program->player_pos.x / 64,
			program->player_pos.y / 64, program))
		program->player = ft_new_sprite(program->mlx, "sprites/exit2.xpm");
	program->map[program->player_pos.y / 64][program->player_pos.x / 64] = 'P';
	program->steps++;
	return (0);
}
