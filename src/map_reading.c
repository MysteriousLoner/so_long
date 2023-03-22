/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:32:46 by yalee             #+#    #+#             */
/*   Updated: 2023/03/23 00:57:54 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_join1(char *hold, char *buffer)
{
	char	*dest;

	dest = ft_strjoin1(hold, buffer);
	free(hold);
	return (dest);
}

void	readmap(char *map, t_program *program)
{
	char	*line;
	char	*final;
	int		fd;

	line = "";
	final = ft_strdup("");
	fd = open(map, O_RDWR);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		final = ft_join1(final, line);
		free(line);
	}
	free(line);
	program->map = ft_split(final, '\n');
	program->ep = get_pos(program->map, 'E');
	program->player_pos = get_pos(program->map, 'P');
	program->enemies_pos = get_pos(program->map, 'H');
}

int	ft_close(void)
{
	exit(0);
}

void	value_ini(t_program *program)
{
	program->steps = 0;
	program->loot_count = 0;
	program->enemynum = program->e.h;
	program->isdone = 0;
}

void	loadgame(t_program *program)
{
	int	i;
	int	j;

	i = 0;
	program->wall = ft_new_sprite(program->mlx, "sprites/wall.xpm");
	program->player = ft_new_sprite(program->mlx, "sprites/player.xpm");
	program->bg = ft_new_sprite(program->mlx, "sprites/grassbg.xpm");
	program->loot = ft_new_sprite(program->mlx, "sprites/bone.xpm");
	program->enemies = ft_new_sprite(program->mlx, "sprites/droge.xpm");
	program->exit = ft_new_sprite(program->mlx, "sprites/exit.xpm");
	program->exit_open = ft_new_sprite(program->mlx, "sprites/exit2.xpm");
	program->loot_num = 0;
	while (program->map[i])
	{
		j = 0;
		while (program->map[i][j])
		{
			if (program->map[i][j] == 'C')
				program->loot_num++;
			j++;
		}
		i++;
	}
	get_win_size(program->map, &program->window);
	value_ini(program);
}
