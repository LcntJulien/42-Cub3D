/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:17:45 by nlence-l          #+#    #+#             */
/*   Updated: 2025/01/29 11:24:22 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	check_vertical_sub1(t_data *d)
{
	draw_rays_init2(d);
	if (d->ra > P2 && d->ra < P3)
	{
		d->rx = (((int) d->px >> 6) << 6) - 0.001;
		d->ry = (d->px - d->rx) * d->nTan + d->py;
		d->xo = -d->squareSize;
		d->yo = -d->xo * d->nTan;
	}
	if (d->ra < P2 || d->ra > P3)
	{
		d->rx = (((int) d->px >> 6) << 6) + d->squareSize;
		d->ry = (d->px - d->rx) * d->nTan + d->py;
		d->xo = d->squareSize;
		d->yo = -d->xo * d->nTan;
	}
	// if (d->ra == 0 || d->ra == PI) //works with Linux
	if (fabs(d->ra) < EPSILON || fabs(d->ra - PI) < EPSILON) //works with MacOs
	{
		d->rx = d->px;
		d->ry = d->py;
		d->dof = d->mapWidth;
	}
}

void	check_vertical_sub2(t_data *d)
{
	while (d->dof < d->mapWidth)
	{
		d->mx = (int)(d->rx) >> 6;
		d->my = (int)(d->ry) >> 6;
		d->mp = d->my * d->mapWidth + d->mx;
		if ((d->mp > 0 && d->mp < d->mapWidth * d->mapHeight
				&& d->map[d->mp] == '1')
			|| (d->mp > 0 && d->mp < d->mapWidth * d->mapHeight
				&& d->map[d->mp] == '4'))
		{
			d->vx = d->rx;
			d->vy = d->ry;
			d->disV = dist(d->px, d->py, d->vx, d->vy);
			d->dof = d->mapWidth;
		}
		else
		{
			d->rx += d->xo;
			d->ry += d->yo;
			d->dof += 1;
		}
	}
}

void	check_vertical_lines(t_data *d)
{
	check_vertical_sub1(d);
	check_vertical_sub2(d);
}

void	check_right_texture(t_data *d)
{
	if (d->vertical)
	{
		if (d->east)
			draw_east_texture(d);
		else
			draw_west_texture(d);
	}
	else
	{
		if (d->north)
		{
			if (d->door)
				draw_door_texture(d);
			else
				draw_north_texture(d);
		}
		else
		{
			if (d->door)
				draw_door_texture(d);
			else
				draw_south_texture(d);
		}
	}
}

void	draw_ceil_and_floor(t_data *d)
{
	int		i;
	t_point	pc1;
	t_point	pc2;
	t_point	pf1;
	t_point	pf2;

	i = 0;
	while (i < WIDTH / 120)
	{
		pc1.x = d->r + i + d->cpt;
		pc1.y = 0;
		pc2.x = d->r + i + d->cpt;
		pc2.y = (int)d->lineO;
		pf1.x = d->r + i + d->cpt;
		pf1.y = (int)d->lineH + (int)d->lineO;
		pf2.x = d->r + i + d->cpt;
		pf2.y = HEIGHT;
		draw_line_ceil(&pc1, &pc2, d);
		draw_line_floor(&pf1, &pf2, d);
		i++;
	}
}
