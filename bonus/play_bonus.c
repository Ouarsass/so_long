/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:34:08 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/17 23:30:48 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "ft_printf/ft_printf.h"

int	destroy_window(t_data *data)
{
	ft_free(data);
	mlx_destroy_image(data->mlx, data->mlx_win);
	ft_printf("closing the window!\n");
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_exit(t_data *data, int i)
{
	if (i == 0)
		ft_printf("You win");
	if (i == 1)
		ft_printf("Game over");
	free (data->stock);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

void	player_moves(t_data *data, int i, int j)
{
	if (data->stock[data->p_x + i][data->p_y + j] != '1')
	{
		if (data->stock[data->p_x + i][data->p_y + j] == 'C')
			data->collectible--;
		else if (data->stock[data->p_x + i][data->p_y + j] == 'E' \
				&& data->collectible == 0)
			ft_exit(data, 0);
		else if (data->stock[data->p_x + i][data->p_y + j] == 'E' \
				&& data->collectible != 0)
			return ;
		else if (data->stock[data->p_x + i][data->p_y + j] == 'I')
			ft_exit(data, 1);
		data->moves++;
		data->stock[data->p_x + i][data->p_y + j] = 'P';
		data->stock[data->p_x][data->p_y] = '0';
		data->p_x += i;
		data->p_y += j;
		ft_printf("Moves ; %d\n", data->moves);
		draw(data, 0, 0);
	}
}

int	key_hook(int key_code, t_data *data)
{
	if (key_code == ESC)
		destroy_window(data);
	else if (key_code == A)
		player_moves(data, 0, -1);
	else if (key_code == W)
		player_moves(data, -1, 0);
	else if (key_code == D)
		player_moves(data, 0, 1);
	else if (key_code == S)
		player_moves(data, 1, 0);
	return (0);
}
