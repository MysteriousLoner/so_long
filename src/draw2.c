/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:50:34 by yalee             #+#    #+#             */
/*   Updated: 2023/03/22 19:23:01 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_program *program, t_vector v)
{
	static int	frame;

	frame++;
	if (frame == ANIMATION_FRAMES)
		v.y += 2;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		v.y -= 2;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->player.reference, v.x, v.y);
}
