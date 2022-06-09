/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:20:28 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/09 01:56:15 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h/get_next_line.h"
#include "ft_printf/ftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	a1;
	unsigned char	a2;

	i = 0;
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	if (n == 0)
		return 0;
	while (a1[i] != '\0' && a2[i] != '\0' && a1[i] == a2[i] && i < n - 1)
	{
		i++;
	}
	return (a1[i] - a2[i]);
}

void	init(t_data *d)
{
	d->exit = 0;
	d->player = 0;
	d->collectible = 0;
	d->space = 0;
}

void	check(int fd, t_data data, char **av, int i)
{
	char *line;
	
	data.len = 0;
	line = get_next_line(fd);
	while (line)
	{
		data.len++
		free (line);
		line = get_next_line(fd);
	}
	data.stock = (char **)malloc(sizeof(char *) * (data.len + 1));
	if (!data.stock || !data.len)
		exit (1);
	if (close (fd) == -1)
	{
		perror ("Error\n");
		exit (1);
	}
	fd = open (av[1], O_RDWR)
	while (i < data.len)
		data.stock[i++] = get_next_line(fd);
	close (fd);
	data.wit = ft_strlen(data.stock[0]) - 1;
	mlx_ft(data);
}
int		main(int ac, char **av)
{
	t_data	data;
	int		fd;

	data.len = 0;
	if (ac != 2)
	{
		ft_printf("Error\nchecking the arguments");
		return (0);
	}
	if (!check_ext(av[i]))
	{
		ft_printf("Error\nExtention");
		return (0);
	}
	fd = open(av[1], O_RDWR);
	if (fd == -1)
	{
		perror("Error\n");
		return (0);
	}
	check(fd, data, av, 0);
	free (data.mlx);
	return (0);
}