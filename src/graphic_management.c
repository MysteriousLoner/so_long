/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:31:12 by yalee             #+#    #+#             */
/*   Updated: 2023/03/23 00:58:06 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putnum(t_program *a)
{
	char	*num;
	char	*final;
	char	*l;
	char	*lf;
	char	*total;

	num = ft_itoa(a->steps);
	final = ft_strjoin("STEPS : ", num);
	l = ft_itoa(a->loot_count);
	lf = ft_strjoin("FOSSILS COLLECTED : ", l);
	lf = ft_strjoin1(lf, " / ");
	total = ft_itoa(a->loot_num);
	lf = ft_strjoin(lf, total);
	mlx_string_put(a->mlx, a->window.reference, 10, 10, 0xFFFF, final);
	mlx_string_put(a->mlx, a->window.reference, 10, 30, 0xFFFF00, lf);
	free(num);
	free(final);
	free(l);
	free(lf);
}

void	render_map(t_program *program, int x, int y, t_vector v)
{
	while (program->map[y])
	{
		x = 0;
		v.x = 0;
		while (program->map[y][x])
		{
			if (program->map[y][x] == '1')
				draw_wall(program, v);
			else if (program->map[y][x] == '0')
				draw_bg(program, v);
			else if (program->map[y][x] == 'P')
				draw_player(program, v);
			else if (program->map[y][x] == 'C')
				draw_loot(program, v);
			else if (program->map[y][x] == 'H')
				draw_enemy(program, v);
			else if (program->map[y][x] == 'E')
				draw_exit(program, v);
			x++;
			v.x += 64;
		}
		v.y += 64;
		y++;
	}
	putnum(program);
}

int	ft_update(t_program *program)
{
	t_vector	v;
	static int	frame;

	v.x = 0;
	v.y = 0;
	frame++;
	if (frame == 15)
		move_enemy(program);
	else if (frame >= 15)
		frame = 0;
	render_map(program, 0, 0, v);
	return (0);
}
