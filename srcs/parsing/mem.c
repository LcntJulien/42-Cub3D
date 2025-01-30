/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:24:59 by jlecorne          #+#    #+#             */
/*   Updated: 2023/12/22 15:26:51 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	del_cub(t_data *cub)
{
	if (cub->map)
		free(cub->map);
	if (cub->fcolor)
		free(cub->fcolor);
	if (cub->ccolor)
		free(cub->ccolor);
	if (cub->t->NO_path)
		free(cub->t->NO_path);
	if (cub->t->EA_path)
		free(cub->t->EA_path);
	if (cub->t->WE_path)
		free(cub->t->WE_path);
	if (cub->t->SO_path)
		free(cub->t->SO_path);
}

void	del_img(t_data *cub, int i)
{
	if (i > 2)
		mlx_delete_image(cub->mlx, cub->world);
	if (i > 3)
		mlx_delete_image(cub->mlx, cub->t->DO_img);
	if (i > 4)
		mlx_delete_image(cub->mlx, cub->t->NO_img);
	if (i > 5)
		mlx_delete_image(cub->mlx, cub->t->SO_img);
	if (i > 6)
		mlx_delete_image(cub->mlx, cub->t->torch);
	if (i > 7)
		mlx_delete_image(cub->mlx, cub->t->torch1);
	if (i > 8)
		mlx_delete_image(cub->mlx, cub->t->WE_img);
	if (i > 9)
		mlx_delete_image(cub->mlx, cub->t->torch2);
	if (i > 10)
		mlx_delete_image(cub->mlx, cub->t->torch3);
	if (i > 11)
		mlx_delete_image(cub->mlx, cub->t->EA_img);
	if (i > 12)
		mlx_delete_image(cub->mlx, cub->t->torch4);
}

void	free_data(t_data *cub, int i)
{
	if (i > 0)
		del_cub(cub);
	del_img(cub, i);
	if (i > 1)
		mlx_terminate(cub->mlx);
	free(cub->t);
}
