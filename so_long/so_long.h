/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akiss <akiss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:21:26 by akiss             #+#    #+#             */
/*   Updated: 2024/11/19 12:17:28 by akiss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_images
{
	void	*img_floor;
	void	*img_wall;
	void	*img_ply;
	void	*img_chest;
	void	*img_exit;
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
	int			moves;
	int			player_position_set;
}	t_vars;

void	ft_init_images(t_vars *vars);
void	ft_show_map(char *argv, t_vars *vars);
int		ft_calc_height(char *argv);
int		ft_calc_width(char *argv);
void	ft_print(char *line, t_vars *vars, int j);
int		ft_check_map(char **map, t_vars var);
int		ft_close(t_vars *vars);
int		ft_esc(int keycode, t_vars *var);
void	ft_set_player(t_vars *var, int j, int i);
void	render_map(t_vars *var);

#endif