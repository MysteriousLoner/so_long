/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:26:49 by yalee             #+#    #+#             */
/*   Updated: 2023/03/23 00:46:11 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_program *program, t_vector v)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->wall.reference, v.x, v.y);
}

void	draw_bg(t_program *program, t_vector v)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->bg.reference, v.x, v.y);
}

void	draw_loot(t_program *program, t_vector v)
{
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->loot.reference, v.x, v.y);
}

void	draw_exit(t_program *program, t_vector v)
{
	static int	frame;

	if (program->isdone != 1)
	{
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->exit.reference, v.x, v.y);
		return ;
	}
	frame++;
	if (frame == ANIMATION_FRAMES)
		v.y += 2;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		v.y -= 2;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->exit_open.reference, v.x, v.y);
}

void	draw_enemy(t_program *program, t_vector v)
{
	static int	frame;

	if (program->enemynum == 0)
		return ;
	frame++;
	if (frame == ANIMATION_FRAMES)
		v.y += 5;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		v.y -= 5;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->enemies.reference, v.x, v.y);
}
