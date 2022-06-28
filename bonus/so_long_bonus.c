/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:20:28 by mouarsas          #+#    #+#             */
/*   Updated: 2022/06/28 02:47:49 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*b2;

	i = 0;
	a1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (a1[i] != '\0' && b2[i] != '\0' && a1[i] == b2[i] && i < n - 1)
		i++;
	return (a1[i] - b2[i]);
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
	char	*line;

	data.hauteur = 0;
	line = get_next_line(fd);
	while (line)
	{
		data.hauteur++;
		free (line);
		line = get_next_line(fd);
	}
	data.stock = (char **)malloc(sizeof(char *) * (data.hauteur + 1));
	if (!data.stock || !data.hauteur)
		exit (1);
	if (close (fd) == -1)
	{
		perror ("Error\n");
		exit (1);
	}
	fd = open (av[1], O_RDWR);
	while (i < data.hauteur)
		data.stock[i++] = get_next_line(fd);
	close (fd);
	data.larg = ft_strlen(data.stock[0]) - 1;
	mlx_function(data);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	data.hauteur = 0;
	if (ac != 2)
	{
		ft_printf("Error\nchecking the arguments");
		return (0);
	}
	if (!check_ext(av[1]))
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
