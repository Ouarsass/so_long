/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 02:53:04 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/25 02:54:38 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->hauteur)
	{
		free (data->stock[i]);
		i++;
	}
	free (data->stock);
}
