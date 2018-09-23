/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnqabash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:52:03 by lnqabash          #+#    #+#             */
/*   Updated: 2018/09/23 01:01:28 by lnqabash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_regulate
{
	float		angle;
	float		mortal;
	float		x1;
	float		y1;
}				t_regulate;

typedef	struct	s_env
{
	int			*img;
	int			bbp;
	int			tab[20][20];
	int			size;
	int			end;
	void		*mlx;
	float		x;
	float		y;
	int			x1;
	int			y1;
	void		*imgp;
	void		*win;
	float		i;
	float		j;
}				t_env;

int				keyevent(int key, t_env *screen);
void			print_lines(t_env *screen);
void			frame_work(t_env *screen);
t_env			*init(void);
void			paint_wall(int *color, int x, int y);
void			cast_map(int tab[20][20], t_env *screen);
void			pixel_put_to_image(t_env *screen, int x, int color);
void			maze_map(t_env *screen);
float			raycasting(t_env *screen, float x, float y, int *color);
int				open_file(t_env *screen, char *k);
void			pixel_put_to_image_down(t_env *screen, int y, int h, int color);
void			draw_line(t_env *screen, float x, float y);

#endif
