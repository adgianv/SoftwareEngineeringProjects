/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <andi-gia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:53 by fbriglia          #+#    #+#             */
/*   Updated: 2023/07/15 18:33:41 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_image(t_game *game)
{
	int	len;

	len = SPRITE_SIZE;
	if (game->keycode == KEY_A || game->keycode == KEY_LEFT)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./img/player_sx.xpm", &len, &len);
	else if (game->keycode == KEY_W || game->keycode == KEY_UP)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./img/player_up.xpm", &len, &len);
	else if (game->keycode == KEY_D || game->keycode == KEY_RIGHT)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./img/player_dx.xpm", &len, &len);
	else if (game->keycode == KEY_S || game->keycode == KEY_DOWN)
		game->map.player = mlx_xpm_file_to_image(game->mlx,
				"./img/player_down.xpm", &len, &len);
}

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map.player);
	mlx_destroy_image(game->mlx, game->map.floor);
	mlx_destroy_image(game->mlx, game->map.wall);
	mlx_destroy_image(game->mlx, game->map.enemy);
	mlx_destroy_image(game->mlx, game->map.coin);
	mlx_destroy_image(game->mlx, game->map.exit);
	mlx_destroy_window(game->mlx, game->window);
}

void	put_images(t_game *game)
{
	int	len;

	len = 32;
	game->map.wall = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &len,
			&len);
	game->map.player = mlx_xpm_file_to_image(game->mlx, "./img/player_dx.xpm",
			&len, &len);
	game->map.floor = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", &len,
			&len);
	game->map.exit = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &len,
			&len);
	game->map.coin = mlx_xpm_file_to_image(game->mlx, "./img/coin.xpm", &len,
			&len);
	game->map.enemy = mlx_xpm_file_to_image(game->mlx, "./img/enemy_dx.xpm",
			&len, &len);
}

void	mlx_put_image(int x, int y, t_game *game)
{
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->map.wall, x * 32,
			y * 32);
	if (game->map.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->map.floor, x
			* 32, y * 32);
	if (game->map.map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->map.player, x
			* 32, y * 32);
	if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->map.exit, x * 32,
			y * 32);
	if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->map.coin, x * 32,
			y * 32);
	if (game->map.map[y][x] == 'X')
		mlx_put_image_to_window(game->mlx, game->window, game->map.enemy, x
			* 32, y * 32);
}

void	put_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	if (game->counter_calls % 3 == 0)
		move_enemy(game);
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x] != '\0')
		{
			mlx_put_image(x, y, game);
			x++;
		}
		y++;
	}
}
