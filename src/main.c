/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 12:16:52 by lnqabash          #+#    #+#             */
/*   Updated: 2018/09/22 21:00:51 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int argc, char **argv)
{
	t_env	screen;
	int		*img;

	if (argc != 2)
		ft_putendl("Error: Missing Argument");
	else
	{	
		screen.mlx = mlx_init();
		screen.win = mlx_new_window(screen.mlx, 1100, 750,
				ft_strjoin("Wolf3d - ", argv[1]));
		screen.imgp = mlx_new_image(screen.mlx, 1100, 750);
		img = (int *)mlx_get_data_addr(screen.imgp, &screen.bbp,
				&screen.size, &screen.end);
		screen.img = img;
		screen.x = 10;
		screen.y = 1;
		screen.j = 1800;
		maze_map(&screen);
		print_lines(&screen);
		mlx_key_hook(screen.win, keyevent, &screen);
		mlx_hook(screen.win, 2, (1L << 0), keyevent, &screen);
		mlx_loop(screen.mlx);
	}
	return (0);
}
