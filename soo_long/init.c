/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:34:39 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/21 13:31:33 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_init(t_game *game)
{
	game->player = mlx_xpm_file_to_image
		(game->mlx, "assets/player.xpm", &game->row, &game->collum);
	if (!game->player)
		free_images(game, "Player xpm error!\n");
	game->floor = mlx_xpm_file_to_image
		(game->mlx, "assets/floor.xpm", &game->row, &game->collum);
	if (!game->floor)
		free_images(game, "Floor xpm error!\n");
	game->wall = mlx_xpm_file_to_image
		(game->mlx, "assets/wall.xpm", &game->row, &game->collum);
	if (!game->wall)
		free_images(game, "Wall xpm error!\n");
	game->coin = mlx_xpm_file_to_image
		(game->mlx, "assets/coin.xpm", &game->row, &game->collum);
	if (!game->coin)
		free_images(game, "Coin xpm error!\n");
	game->exit = mlx_xpm_file_to_image
		(game->mlx, "assets/exit.xpm", &game->row, &game->collum);
	if (!game->exit)
		free_images(game, "Exit xpm error!\n");
}

static void	get_window_size(t_game *game)
{
	int	i;

	game->win_w = ft_strlen(game->map[0]) * IMG_SIZE;
	i = 0;
	while (game->map[i])
		i++;
	game->win_h = i * IMG_SIZE;
}

void	init_solong(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->player = NULL;
	game->wall = NULL;
	game->floor = NULL;
	game->coin = NULL;
	game->exit = NULL;
	game->mlx = mlx_init();
	get_window_size(game);
	game->win = mlx_new_window(game->mlx, game->win_w, game->win_h, "so_long");
	game->move_counter = 0;
	game->gameover = 0;
	img_init(game);
	generate_map(game);
}

void	ft_bzero(void *s, size_t n)
{
	char	*vs;

	if (!s)
		return ;
	vs = s;
	while (n--)
		*vs++ = '\0';
}

void	free_stuff(int fd, char *line, char *msg)
{
	if (line)
		free(line);
	if (fd)
		close(fd);
	if (msg)
		pexit(msg, 1);
}
