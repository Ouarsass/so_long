/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:55:06 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/11 04:34:41 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned int n, const char *base, int *cp)
{
	if (n < 16)
		ft_putchar(base[n], cp);
	else
	{
		ft_hexa(n / 16, base, cp);
		ft_putchar(base[n % 16], cp);
	}
}
