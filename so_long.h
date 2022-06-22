/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:20:48 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/17 22:59:32 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct s_data
{
	int		hauteur;
	int		larg;
	char	**stock;
	int		player;
	int		p_x;
	int		p_y;
	int		collectible;
	int		space;
	int		wall;
	int		exit;
	void	*empty;
	void	*mlx;
	void	*mlx_win;
	void	*champignon;
	void	*mario;
	void	*walls;
	void	*door;
	int		img_hauteur;
	int		img_largeur;
	int		moves;
}		t_data;

int		check_ext(char *map);
void	check_rectangle(t_data data);
void	check_walls(t_data data);
void	open_window(t_data *data);
void	draw(t_data *data);
int		check_content(t_data *d, int i, int j);
void	init(t_data *d);
size_t	ft_strlen(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_free(t_data *data);
int		destroy_window(t_data *data);
int		key_hook(int key_code, t_data *data);
void	mlx_function(t_data data);
#endif
