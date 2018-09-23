/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 17:04:31 by lnqabash          #+#    #+#             */
/*   Updated: 2018/09/23 01:27:30 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		esc(void)
{
	exit(1);
	return (0);
}

int		keyevent(int key, t_env *screen)
{
	float	y;
	float	x;

	x = -1;
	y = -1;
	if (key == 53)
		esc();
	if (key == 126)
	{
		x = screen->x + (0.1 * cos((screen->j / 180) * M_PI));
		y = screen->y + (0.1 * sin((screen->j / 180) * M_PI));
	}
	else if (key == 125)
	{
		x = screen->x - (0.1 * cos((screen->j / 180) * M_PI));
		y = screen->y - (0.1 * sin((screen->j / 180) * M_PI));
	}
	screen->j -= (key == 124) & (1);
	screen->j += (key == 123) & (1);
	draw_line(screen, x, y);
	return (1);
}

void	pixel_put_to_image(t_env *screen, int x, int color)
{
	int	i;
	int	h;
	int	c;
	int	y;
	int	z;

	h = (750 / (2 * screen->i));
	y = ((750 / 2) * screen->size) + (x * screen->bbp / 8);
	i = 0;
	while (i < h)
	{
		c = 0;
		while (c < (screen->bbp / 8))
		{
			z = y - (i * screen->size);
			screen->img[(c + z) / 4] = color;
			++c;
		}
		++i;
	}
	pixel_put_to_image_down(screen, y, h, color);
}

void	pixel_put_to_image_down(t_env *screen, int y, int h, int color)
{
	int	c;
	int	i;
	int	z;

	i = 0;
	while (i < h)
	{
		c = 0;
		while (c < (screen->bbp / 8))
		{
			z = y + (i * screen->size);
			screen->img[(c + z) / 4] = color;
			++c;
		}
		++i;
	}
}
