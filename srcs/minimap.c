/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:42:49 by nlence-l          #+#    #+#             */
/*   Updated: 2023/12/31 14:44:03 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_minimap(t_data *d)
{
	int	i;

	init_minimap(d);
	i = d->pos_start;
	while (i < d->pos_end)
	{
		while (i < (d->pos_start + 5))
		{
			if (i < 0 || i >= (int)ft_strlen(d->map))
				draw_wall(d);
			else
			{
				if (d->map[i] && (d->map[i] == '0'
						|| d->map[i] == 'N' || d->map[i] == 'S'
						|| d->map[i] == 'E' || d->map[i] == 'W'))
					draw_empty(d);
				else
					draw_wall(d);
			}
			check_minimap(d);
			i++;
		}
		d->pos_start += d->mapWidth;
		i = d->pos_start;
	}
}
