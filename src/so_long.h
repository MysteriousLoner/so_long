/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:51:29 by yalee             #+#    #+#             */
/*   Updated: 2023/03/23 00:58:34 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_check
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;
	int	h;
}	t_check;

typedef struct s_program
{
	void		*mlx;
	char		**map;
	int			loot_num;
	int			loot_count;
	int			isdone;
	int			height;
	int			len;
	int			t;
	int			enemynum;
	int			steps;
	t_window	window;
	t_image		enemies;
	t_image		player;
	t_image		bg;
	t_image		wall;
	t_image		loot;
	t_image		exit;
	t_image		exit_open;
	t_vector	player_pos;
	t_vector	enemies_pos;
	t_vector	ep;
	t_check		e;
}				t_program;

int			mapsize(t_program *a);
int			validity(t_program *a);
int			colwall(t_program *a);
int			rowwall(t_program *a);
int			ft_error(t_program *a);
void		draw_wall(t_program *program, t_vector v);
void		draw_bg(t_program *program, t_vector v);
void		draw_loot(t_program *program, t_vector v);
void		draw_exit(t_program *program, t_vector v);
void		draw_enemy(t_program *program, t_vector v);
void		draw_player(t_program *program, t_vector v);
int			is_car(int valx, int valy, t_program *program);
int			valid(char m, t_vector v, t_program *program);
int			valid_enemy(char m, t_vector v, t_program *program);
int			is_wall(int valx, int valy, t_program *program);
void		render_map(t_program *program, int x, int y, t_vector v);
int			ft_update(t_program *program);
t_window	ft_new_window(void *mlx, int width, int height, char *name);
t_image		ft_new_image(void *mlx, int width, int height);
t_image		ft_new_sprite(void *mlx, char *path);
int			ft_input(int key, t_program *program);
void		quitting(t_program *program);
void		restore(t_program *a);
void		valid_c(t_program *a, int i, int j, int *c);
void		valid_e(t_program *a, int i, int j, int *e);
void		safety(t_program *a, int i, int j, int *c);
void		get_win_size(char **map, t_window *window);
int			evalid(t_program *a);
t_vector	get_pos(char **map, char c);
int			mapsize(t_program *a);
int			validity(t_program *a);
int			colwall(t_program *a);
int			rowwall(t_program *a);
int			ft_error(t_program *a);
char		*ft_join1(char *hold, char *buffer);
void		readmap(char *map, t_program *program);
int			ft_close(void);
void		loadgame(t_program *program);
int			is_good_map(char **map);
int			is_vchar(char c);
void		move_enemy(t_program *program);
int			is_wall_e(int valx, int valy, t_program *program);
int			collect(t_program *a);
#endif