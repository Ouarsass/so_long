/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 23:48:45 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/17 23:48:43 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"

int	check_ext(char *map)
{
	int		i;
	char	*str;

	i = ft_strlen(map);
	str = map + i - 4;
	if (!ft_strncmp(str, ".ber", 4))
		return (1);
	else
		return (0);
}

void	check_rectangle(t_data data)
{
	int	n;
	int	i;
	int	v;

	n = 0;
	i = 0;
	v = 1;
	while (v <= data.hauteur)
	{
		if (i == data.hauteur - 1)
			n = ft_strlen(data.stock[i]);
		else
			n = ft_strlen(data.stock[i]);
		if (data.larg != n)
		{
			ft_printf("Error\ndidn't read the map");
			exit(1);
		}
		v++;
		i++;
	}
}

void	check_walls(t_data data)
{
	int	i;

	i = 0;
	while (i < data.larg)
	{
		if (data.stock[0][i] != '1' || data.stock[data.hauteur - 1][i] != '1')
		{
			ft_printf("Error\nproblem of the walls");
			exit (1);
		}
		i++;
	}
}

void	help(t_data *d, int i, int j)
{
	if (d->stock[i][j] == 'P')
	{
		d->player++;
		d->p_x = i;
		d->p_y = j;
	}
	else if (d->stock[i][j] == 'C')
		d->collectible++;
	else if (d->stock[i][j] == 'E')
		d->exit++;
	else if (d->stock[i][j] == '0')
		d->empty++;
	else if (d->stock[i][j] == '1')
		d->wall++;
	else
	{
		ft_printf("Error : undefined character");
		exit (1);
	}
}

int	chaeck_content(t_data *d, int i, int j)
{
	while (i < d->larg)
	{
		j = 0;
		while (j < d->larg)
		{
			help(d, i, j);
			j++;
		}
		i++;
	}
	if (d->collectible > 0 && d->exit > 0 && d->player == 1 \
		&& d->empty > 0 && d->wall > 0)
		return (1);
	return (0);
}
