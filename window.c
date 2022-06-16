/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:21:07 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/16 02:04:49 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"

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
	mlx_hook(data.mlx_larg);
}