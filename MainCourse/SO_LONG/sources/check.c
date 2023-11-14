/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <andi-gia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:26:05 by fbriglia          #+#    #+#             */
/*   Updated: 2023/07/15 16:26:36 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_top_border(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y++])
	{
		x = 0;
		if (y == 0)
		{
			while (game->map.map[y][x++])
			{
				if (game->map.map[y][x] != '1')
					ft_exit(game);
			}
		}
		if (y == game->map.rows - 1)
		{
			while (game->map.map[game->map.rows - 1][x])
			{
				if (game->map.map[y][x] != '1')
					ft_exit(game);
				x++;
			}
		}
	}
}

void	check_side_border(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		if (game->map.map[y][x] == 1)
		{
			ft_printf(" %s", "\n **INVALID MAP BORDER** \n\n");
			ft_exit(game);
		}
		y++;
	}
	y = 0;
	while (y < game->map.rows)
	{
		x = game->map.cols - 1;
		if (game->map.map[y][x] != '1')
			ft_exit(game);
		y++;
	}
}

void	count_collectibles(t_game *game)
{
	int	c;
	int	x;
	int	i;

	i = 0;
	c = 0;
	while (game->map.map[i])
	{
		x = 0;
		while (game->map.map[i][x])
		{
			if (game->map.map[i][x] == 'C')
				c++;
			x++;
		}
		i++;
	}
	if (c < 1)
	{
		ft_printf(" %s", "\n **INVALID MAP POPULATION** \n\n");
		ft_exit(game);
	}
	game->collectibles = c;
}

int	count_population(t_game *game)
{
	int	x;
	int	i;
	int	p;
	int	e;

	i = 0;
	e = 0;
	p = 0;
	while (game->map.map[i])
	{
		x = 0;
		while (game->map.map[i][x])
		{
			if (game->map.map[i][x] == 'P')
				p++;
			if (game->map.map[i][x] == 'E')
				e++;
			x++;
		}
		i++;
	}
	if (e != 1 || p != 1)
		return (1);
	else
		return (0);
}

void	ft_check(t_game *game)
{
	int	i;

	check_shape(game);
	check_top_border(game);
	check_side_border(game);
	i = count_population(game);
	if (i == 1)
	{
		ft_printf(" %s", "\n **INVALID MAP POPULATION** \n\n");
		ft_exit(game);
	}
	count_collectibles(game);
}
