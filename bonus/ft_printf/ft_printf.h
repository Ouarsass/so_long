/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:55:44 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/11 04:35:35 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>

void	ft_putchar(char c, int *cp);
void	ft_putnbr(int n, int *cp);
int		printf(const char *tmp, ...);
void	ft_putnbr_unsigned(unsigned int n, int *cp);
void	ft_hexa(unsigned int n, const char *base, int *cp);
void	ft_putstr(char *str, int *cp);
void	ft_pionter(unsigned long n, const char *base, int *cp);

#endif
