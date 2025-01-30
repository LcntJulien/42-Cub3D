/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:18:40 by nlence-l          #+#    #+#             */
/*   Updated: 2023/12/19 14:35:54 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	move_forward(t_data *d)
{
	int	xo;
	int	yo;

	if (d->pdx < 0)
		xo = -20;
	else
		xo = 20;
	if (d->pdy < 0)
		yo = -20;
	else
		yo = 20;
	if (mlx_is_key_down(d->mlx, MLX_KEY_W))
	{
		if (d->map[(int)(d->py / 64.0) * d->mapWidth
			+ (int)((d->px + xo) / 64.0)] != '1'
			&& d->map[(int)(d->py / 64.0) * d->mapWidth
			+ (int)((d->px + xo) / 64.0)] != '4')
			d->px += d->pdx;
		if (d->map[(int)((d->py + yo) / 64.0) *d->mapWidth
			+ (int)(d->px / 64.0)]
			!= '1' && d->map[(int)((d->py + yo) / 64.0)
			*d->mapWidth + (int)(d->px / 64.0)] != '4')
			d->py += d->pdy;
	}
}

void	move_backwards(t_data *d)
{
	int	xo;
	int	yo;

	if (d->pdx < 0)
		xo = -20;
	else
		xo = 20;
	if (d->pdy < 0)
		yo = -20;
	else
		yo = 20;
	if (mlx_is_key_down(d->mlx, MLX_KEY_S))
	{
		if (d->map[(int)(d->py / 64.0) * d->mapWidth
			+ (int)((d->px - xo) / 64.0)] != '1'
			&& d->map[(int)(d->py / 64.0) * d->mapWidth
			+ (int)((d->px - xo) / 64.0)] != '4')
			d->px -= d->pdx;
		if (d->map[(int)((d->py - yo) / 64.0) *d->mapWidth
			+ (int)(d->px / 64.0)] != '1'
			&& d->map[(int)((d->py - yo) / 64.0)
			*d->mapWidth + (int)(d->px / 64.0)] != '4')
			d->py -= d->pdy;
	}
}

void	move_left(t_data *d)
{
	int	xo;
	int	yo;

	if (cos(d->pa + P2) * 5 < 0)
		xo = -20;
	else
		xo = 20;
	if (sin(d->pa + P2) * 5 < 0)
		yo = -20;
	else
		yo = 20;
	if (mlx_is_key_down(d->mlx, MLX_KEY_A))
	{
		if (d->map[(int)(d->py / 64.0) * d->mapWidth
			+ (int)((d->px - xo) / 64.0)] != '1'
			&& d->map[(int)(d->py / 64.0) * d->mapWidth
			+ (int)((d->px - xo) / 64.0)] != '4')
			d->px -= cos(d->pa + P2) * 5;
		if (d->map[(int)((d->py - yo) / 64.0) *d->mapWidth
			+ (int)(d->px / 64.0)] != '1'
			&& d->map[(int)((d->py - yo) / 64.0)
			*d->mapWidth + (int)(d->px / 64.0)] != '4')
			d->py -= sin(d->pa + P2) * 5;
	}
}

void	move_right(t_data *d)
{
	int	xo;
	int	yo;

	if (cos(d->pa + P2) * 5 < 0)
		xo = -20;
	else
		xo = 20;
	if (sin(d->pa + P2) * 5 < 0)
		yo = -20;
	else
		yo = 20;
	if (mlx_is_key_down(d->mlx, MLX_KEY_D))
	{
		if (d->map[(int)(d->py / 64.0) * d->mapWidth
			+ (int)((d->px + xo) / 64.0)] != '1'
			&& d->map[(int)(d->py / 64.0) * d->mapWidth
			+ (int)((d->px + xo) / 64.0)] != '4')
			d->px += cos(d->pa + P2) * 5;
		if (d->map[(int)((d->py + yo) / 64.0)
			*d->mapWidth + (int)(d->px / 64.0)] != '1'
			&& d->map[(int)((d->py + yo) / 64.0)
			*d->mapWidth + (int)(d->px / 64.0)] != '4')
			d->py += sin(d->pa + P2) * 5;
	}
}

void	change_player_direction(t_data *d)
{
	if (mlx_is_key_down(d->mlx, MLX_KEY_LEFT)
		|| mlx_is_mouse_down(d->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		d->pa -= 0.06;
		if (d->pa < 0)
			d->pa += 2 * PI;
		d->pdx = cos(d->pa) * 5;
		d->pdy = sin(d->pa) * 5;
	}
	if (mlx_is_key_down(d->mlx, MLX_KEY_RIGHT)
		|| mlx_is_mouse_down(d->mlx, MLX_MOUSE_BUTTON_RIGHT))
	{
		d->pa += 0.06;
		if (d->pa > 2 * PI)
			d->pa -= 2 * PI;
		d->pdx = cos(d->pa) * 5;
		d->pdy = sin(d->pa) * 5;
	}
}
