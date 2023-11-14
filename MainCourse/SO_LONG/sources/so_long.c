/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <andi-gia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:40 by fbriglia          #+#    #+#             */
/*   Updated: 2023/07/15 15:59:01 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		free(game->map.map[y]);
		y++;
	}
	ft_printf("Time: %d seconds\n", game->counter_calls/20);
	free(game->map.map);
	destroy_image(game);
	exit(0);
}

int	close_game(void)
{
	printf("** EXIT GAME **");
	exit(0);
	return (0);
}

int	render_image(t_game *game)
{
	int		i;
	char	*time;

	if (game->was_coin == 1)
		close_pacman(game);
	else
		update_image(game);
	put_map(game);
	game->counter_calls++;
	if (game->counter_calls == 2147483646)
		game->counter_calls = 0;
	if (game->counter_calls % 20 == 0)
	{
		i = game->counter_calls - 1;
		time = ft_itoa(i / 20);
		mlx_string_put(game->mlx, game->window, ((game->map.cols / 2)) * 32,
			(game->map.rows + 1) * 32, 0x00000000, time);
		free(time);
		time = ft_itoa(game->counter_calls / 20);
		mlx_string_put(game->mlx, game->window, ((game->map.cols / 2)) * 32,
			(game->map.rows + 1) * 32, 0xFFFFFFFF, time);
		free(time);
	}
	// if (game->counter_calls / 20 == 35)
	// {
	// 	ft_printf("YOU lose DUMMY👻");
	// 	ft_exit(game);
	// }
	return (0);
}

void	game_init(t_game *game)
{
	char	*str;
	char	*join;

	put_images(game);
	game->move_counter = 0;
	str = ft_itoa(game->move_counter);
	join = ft_join("Move counter : ", str);
	mlx_string_put(game->mlx, game->window, 32, (game->map.rows + 1) * 32,
		0x0000FF00, join);
	free(str);
	free(join);
	str = ft_itoa(game->counter_calls);
	mlx_string_put(game->mlx, game->window, ((game->map.cols / 2)) * 32,
		(game->map.rows + 1) * 32, 0xFFFFFFFF, str);
	free(str);
	str = ft_itoa(game->collectibles);
	join = ft_join("To collect : ", str);
	mlx_string_put(game->mlx, game->window, ((game->map.cols) - 4) * 32,
		(game->map.rows + 1) * 32, 0xCFFF04, join);
	free(str);
	free(join);
	mlx_hook(game->window, 17, 0, &close_game, game);
	mlx_hook(game->window, 2, 0, &key_handler, game);
	mlx_loop_hook(game->mlx, &render_image, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("%s", "\n **NO INPUT MAP OR TOO MANY INPUTS** \n\n");
		return (1);
	}
	game.counter_calls = 0;
	ft_valid_name(argv[1]);
	ft_parse_map(&game, argv[1]);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map.cols * 32,
			(game.map.rows + 2) * 32, "Neon Pacman");
	game_init(&game);
	ft_exit(&game);
	return (0);
}
