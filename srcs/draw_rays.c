/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:17:37 by nlence-l          #+#    #+#             */
/*   Updated: 2025/01/29 11:24:33 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	check_horizontal_sub1(t_data *d)
{
	draw_rays_init(d);
	if (d->ra > PI)
	{
		d->ry = (((int) d->py >> 6) << 6) - 0.001;
		d->rx = (d->py - d->ry) * d->aTan + d->px;
		d->yo = -d->squareSize;
		d->xo = -d->yo * d->aTan;
	}
	if (d->ra < PI)
	{
		d->ry = (((int) d->py >> 6) << 6) + d->squareSize;
		d->rx = (d->py - d->ry) * d->aTan + d->px;
		d->yo = d->squareSize;
		d->xo = -d->yo * d->aTan;
	}
	// if (d->ra == 0 || d->ra == PI) //works with Linux
	if (fabs(d->ra) < EPSILON || fabs(d->ra - PI) < EPSILON) //works with MacOs
	{
		d->rx = d->px;
		d->ry = d->py;
		d->dof = d->mapHeight;
	}
}

void	check_horizontal_sub2(t_data *d)
{
	while (d->dof < d->mapHeight)
	{
		d->mx = (int)(d->rx) >> 6;
		d->my = (int)(d->ry) >> 6;
		d->mp = d->my * d->mapWidth + d->mx;
		if ((d->mp > 0 && d->mp < d->mapWidth * d->mapHeight
				&& d->map[d->mp] == '1')
			|| (d->mp > 0 && d->mp < d->mapWidth * d->mapHeight
				&& d->map[d->mp] == '4'))
		{
			if (d->mp > 0 && d->mp < d->mapWidth * d->mapHeight
				&& d->map[d->mp] == '4')
				d->door = 1;
			d->hx = d->rx;
			d->hy = d->ry;
			d->disH = dist(d->px, d->py, d->hx, d->hy);
			d->dof = d->mapHeight;
		}
		else
		{
			d->rx += d->xo;
			d->ry += d->yo;
			d->dof += 1;
		}
	}
}

void	check_horizontal_lines(t_data *d)
{
	check_horizontal_sub1(d);
	check_horizontal_sub2(d);
}

void	draw_rays(t_data *d)
{
	d->cpt = 0;
	d->ra = d->pa - DR * 30;
	d->r = 0;
	reset_pi(&d->ra);
	while (d->r < 120)
	{
		check_horizontal_lines(d);
		check_vertical_lines(d);
		check_wall_hit(d);
		init_for_textures(d);
		checks_for_textures(d);
		check_right_texture(d);
		draw_ceil_and_floor(d);
		d->cpt += (WIDTH / 120 - 1);
		d->ra += DR * 0.5;
		reset_pi(&d->ra);
		d->door = 0;
		d->r++;
	}
}
