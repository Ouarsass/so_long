/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:36:55 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/10 21:45:49 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *cp)
{
	if (n < 10)
		ft_putchar(n + '0', cp);
	else
	{
		ft_putnbr(n / 10, cp);
		ft_putchar((n % 10) + 48, cp);
	}
}
