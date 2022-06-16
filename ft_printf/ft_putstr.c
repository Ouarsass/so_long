/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:04:15 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/11 04:36:05 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *cp)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)", cp)
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], cp);
		i++;
	}
}
