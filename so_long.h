/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:20:48 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/09 02:45:27 by mouarsas         ###   ########.fr       */
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
# define w 13
# define ESC 53

typedef struct s_data
{
	int		len;
	
}		t_data;

int		check_ext(char *map);
void	check_rectangle(t_data data);
void	check_walls(t_data data);
void	open_window(t_data *data);
void	draw(t_data *data);
int		check_content(t_data *d, int i, int j);
void	init(t_data *d);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_free(t_data *data);
int		destroy_window(t_data *data);
int		key_hook(int key_code, t_data *data);
void	mlx_ft(t_data data);
#endif