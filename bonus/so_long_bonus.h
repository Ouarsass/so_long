/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:29:02 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/17 23:57:52 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef "SO_LONG_BONUS.H"
# define "SO_LONG_BONUS.H"

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
	void	*empty;.
	void	*mlx;
	void	*mlx_win;
	void	*champignon;
	void	*mario;
	void	*walls;
	void	*door;
	int		a;
	int		b;
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
void	mlx_ft(t_data data);
#endif
