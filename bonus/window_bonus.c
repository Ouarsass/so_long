/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:21:07 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/30 21:37:45 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"

int	update(t_data *data)
{
	data->count++;
	if (data->count <= 90)
	{
		if (data->count >= 0)
			data->enemy = mlx_xpm_file_to_image(data->mlx, \
			"bonus/image/enemy.xpm", &data->img_largeur, &data->img_hauteur);
		if (data->count >= 50)
			data->enemy = mlx_xpm_file_to_image(data->mlx, \
			"bonus/image/enemy1.xpm", &data->img_largeur, &data->img_hauteur);
	}
	else
		data->count = 0;
	draw(data, 0, 0);
	return (0);
}

void	mlx_function(t_data data)
{
	init(&data);
	check_rectangle(data);
	check_walls(data);
	if (!check_content(&data, 0, 0))
	{
		ft_printf("Error\nProblem in the contents of the map");
		exit (0);
	}
	open_window(&data);
	data.count = 0;
	mlx_loop_hook(data.mlx, &update, &data);
	mlx_hook(data.mlx_win, 17, 0, destroy_window, &data);
	mlx_hook(data.mlx_win, 2, 0, key_hook, &data);
	mlx_loop(data.mlx);
}

void	put_image(void *txt, int i, int j, t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		txt, j * 64, i * 64);
}

void	draw(t_data *data, int i, int j)
{
	while (i < data->hauteur)
	{
		j = 0;
		while (j < data->larg)
		{
			if (data->stock[i][j] == '1')
				put_image(data->walls, i, j, data);
			else
			{
				put_image(data->empty, i, j, data);
				if (data->stock[i][j] == 'P')
					put_image(data->mario, i, j, data);
				else if (data->stock[i][j] == 'C')
					put_image(data->champignon, i, j, data);
				else if (data->stock[i][j] == 'E')
					put_image(data->door, i, j, data);
				else if (data->stock[i][j] == 'I')
					put_image(data->enemy, i, j, data);
			}
			j++;
		}
		i++;
	}
	show_moves(data);
}

void	open_window(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 64 * data->larg, \
		64 * data->hauteur, "so_long");
	data->door = mlx_xpm_file_to_image(data->mlx, \
		"bonus/image/door.xpm", &data->img_hauteur, &data->img_largeur);
	data->champignon = mlx_xpm_file_to_image(data->mlx, \
		"bonus/image/champignon.xpm", &data->img_hauteur, &data->img_largeur);
	data->mario = mlx_xpm_file_to_image(data->mlx, \
		"bonus/image/mario.xpm", &data->img_hauteur, &data->img_largeur);
	data->walls = mlx_xpm_file_to_image(data->mlx, \
		"bonus/image/walls.xpm", &data->img_hauteur, &data->img_largeur);
	data->empty = mlx_xpm_file_to_image(data->mlx, \
		"bonus/image/empty.xpm", &data->img_hauteur, &data->img_largeur);
	data->enemy = mlx_xpm_file_to_image(data->mlx, \
		"bonus/image/enemy.xpm", &data->img_hauteur, &data->img_largeur);
	if (!data->walls || !data->mario || !data->champignon || !data->door \
		|| !data->empty)
	{
		ft_printf("Error\npicture problem");
		exit(0);
	}
	draw(data, 0, 0);
}
