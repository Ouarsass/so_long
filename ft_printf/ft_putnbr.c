/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:54:30 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/10 22:03:26 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *cp)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*cp = *cp + 11;
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-', cp);
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar(n + '0', cp)
	}
	else
	{
		ft_putnbr(n / 10, cp);
		ft_putchar(n % 10 + 48, cp);
	}
}
