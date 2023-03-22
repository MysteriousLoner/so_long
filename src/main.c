/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:38:50 by yalee             #+#    #+#             */
/*   Updated: 2023/03/23 00:32:11 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	quitting(t_program *program)
{
	t_vector	v;
	t_vector	v2;

	v.x = 0;
	v.y = 0;
	v2.x = program->player_pos.x / 64;
	v2.y = program->player_pos.y / 64;
	program->player = ft_new_sprite(program->mlx, "sprites/exit2.xpm");
	ft_printf("You escaped with all the fossils!\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_program	program;
	t_vector	v;

	v.x = 0;
	v.y = 0;
	argc = 0;
	program.mlx = mlx_init();
	readmap(argv[1], &program);
	if (ft_error(&program))
	{
		ft_printf("invalid map!\n");
		return (0);
	}
	loadgame(&program);
	program.window = ft_new_window(program.mlx, program.window.size.x,
			program.window.size.y, "so_long");
	mlx_key_hook(program.window.reference, *ft_input, &program);
	mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
}
