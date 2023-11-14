/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andi-gia <andi-gia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:26:05 by fbriglia          #+#    #+#             */
/*   Updated: 2023/07/15 16:26:36 by andi-gia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int chase_vertical(t_game *game)
{
    int col;
    int line;
    int vertical;

    vertical = game->x_enemy - game->x_player;
    col = game->x_enemy;
    line = game->y_enemy;
    col--;
    if (vertical > 0 && valid(game, col, line) == 1 && game->prev_move != 'S')
    {
        ft_moven(game, col, line);
        game->prev_move = 'N';
        return (1);
    }
    col++;
    col++;
    if (vertical < 0 && valid(game, col, line) == 1 && game->prev_move != 'N')
    {
        ft_moves(game, col, line);
        game->prev_move = 'S';
        return (1);
    }
    return (0);
}

int chase_horizontal(t_game *game)
{
    int col;
    int line;
    int horizontal;

    horizontal = game->y_enemy - game->y_player;
    col = game->x_enemy;
    line = game->y_enemy;
    line--;
    if (horizontal > 0 && valid(game, col, line) == 1 && game->prev_move != 'E')
    {
        ft_movew(game, col, line);
        game->prev_move = 'W';
        return (1);
    }
    line++;
    line++;
    if (horizontal < 0 && valid(game, col, line) == 1 && game->prev_move != 'W')
    {
        ft_movee(game, col, line);
        game->prev_move = 'E';
        return (1);
    }
    return (0);
}

int chase_player(t_game *game)
{
    int vertical;
    int horizontal;

    vertical = game->x_enemy - game->x_player;
    horizontal = game->y_enemy - game->y_player;
    if (horizontal < 0)
        horizontal *= -1;
    if (vertical < 0)
        vertical *= -1;
    if (vertical > horizontal)
    {
        if (chase_vertical(game) == 1)
            return (1);
        if (chase_horizontal(game) == 1)
            return (1);
    }
    else if (horizontal > vertical)
    {
        if (chase_horizontal(game) == 1)
            return (1);
        if (chase_vertical(game) == 1)
            return (1);
    }
    return (0);
}