/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pionter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:25:31 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/10 21:40:48 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(unsigned long n, const char *base, int *cp)
{
	if (n >= 16)
		ft_pointer(n / 16, base, cp);
	ft_putchar(base[n % 16], cp);
}
