/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:18:33 by lnqabash          #+#    #+#             */
/*   Updated: 2018/09/23 01:01:11 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	frame_work(t_env *screen)
{
	int	index;

	index = 0;
	while (index < (screen->size * 750 / 2))
	{
		screen->img[index / 4] = 0x040507 - ((index * 0.01) / 10000);
		++index;
	}
	while (index < (screen->size * 750))
	{
		screen->img[index / 4] = 0x000000 + ((index * 0.01) / 10000);
		index++;
	}
}

float	raycasting(t_env *screen, float x1, float y1, int *color)
{
	int		x;
	int		y;
	int		*hue;
	float	index;

	index = 1;
	hue = color;
	x = screen->x + (index * (x1 - screen->x));
	y = screen->y + (index * (y1 - screen->y));
	while (screen->tab[x][y] == 0)
	{
		x = screen->x + (index * (x1 - screen->x));
		y = screen->y + (index * (y1 - screen->y));
		index += 0.001;
	}
	paint_wall(hue, x, y);
	return (index);
}

void	draw_line(t_env *screen, float x, float y)
{
	int		index;
	int		count;

	index = x;
	count = y;
	if (x >= 0 && x <= 19 && y >= 0 && y <= 19 &&
			screen->tab[index][count] == 0)
	{
		screen->x = x;
		screen->y = y;
	}
	print_lines(screen);
	mlx_put_image_to_window(screen->mlx, screen->win, screen->imgp, 0, 0);
}

void	print_lines(t_env *screen)
{
	int			color;
	float		index;
	t_regulate	p;

	frame_work(screen);
	p.angle = ((screen->j / 180) * M_PI);
	index = 0;
	while (index <= 1100)
	{
		p.x1 = 1;
		p.y1 = ((1 * ((1100 / 2) - index)) / 1100);
		p.mortal = p.x1;
		p.x1 = (p.mortal * cos(p.angle)) - (p.y1 * sin(p.angle));
		p.y1 = (p.mortal * sin(p.angle)) + (p.y1 * cos(p.angle));
		p.x1 = p.x1 + screen->x;
		p.y1 = p.y1 + screen->y;
		screen->i = raycasting(screen, p.x1, p.y1, &color);
		pixel_put_to_image(screen, index, color);
		++index;
	}
	mlx_put_image_to_window(screen->mlx, screen->win, screen->imgp, 0, 0);
}
