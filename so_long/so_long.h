/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:21:26 by akiss             #+#    #+#             */
/*   Updated: 2024/11/24 20:24:45 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
#include <errno.h>

typedef struct s_images
{
	void	*img_floor;
	void	*img_wall;
	void	*img_ply;
	void	*img_chest;
	void	*img_exit;
	void	*img_enemy;
	int		img_width;
	int		img_height;
}	t_images;

typedef struct s_vars
{
	t_images	images;
	void		*mlx;
	void		*win;
	char		**map;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			enemy_x;
	int			enemy_y;
	int			is_enemy;
	int			collectible;
	int			moves;
	int			player_position_set;
	int			enemy_position_set;
	int			rect_width;
	int			rect_height;
	int			color_bg;
}	t_vars;

int		ft_calc_width(char *argv);
int		ft_calc_height(char *argv);
int		ft_is_c(char **map, t_vars var);
int		ft_is_one_p_e(char **map, t_vars var);
int		ft_is_one_row(char **map, t_vars var);
int		ft_is_one_column(char **map, t_vars var);
int		ft_check_map(char **map, t_vars var);
char	**copy_map(char **map, int height);
int		is_valid_position(t_vars *var, int x, int y, char **visited);
int		flood_fill(t_vars *var, int x, int y, char **visited);
int		is_map_solvable(char **map, t_vars var);
int		ft_so_long(char **map, t_vars var);
void	update_player_image(t_vars *var, char *image_path);
void	handle_keycode(int keycode, t_vars *var, int *new_x, int *new_y);
void	handle_keycode(int keycode, t_vars *var, int *new_x, int *new_y);
int		ft_esc(int keycode, t_vars *var);
void	ft_init_images(t_vars *vars);
void	ft_set_position(t_vars *vars, int i, int j);
void	ft_set_player(t_vars *var, int prev_x, int prev_y);
void	ft_print(char *line, t_vars *var, int j);
void	ft_show_map(char *argv, t_vars *vars);
void	ft_free_images(t_vars *var);
int		ft_free_map(t_vars *var);
int		ft_close(t_vars *var);
void	ft_initializes_mlx(t_vars *var, char *argv);
int		main(int argc, char **argv);
int		ft_all_chr(char **map, t_vars var);
void	ft_print_enemy(char *line, t_vars *var, int i, int j);
void	ft_moves_window(t_vars *var);

#endif