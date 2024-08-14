/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:10:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/08/14 14:48:23 by yu-chen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>

# define S_W 1900 // screen width
# define S_H 1000 // screen height

typedef struct s_data //the data structure
{
 char **map2d; // the map
 int  p_x;  // player x position in the map
 int  p_y;  // player y position in the map
 int  map_w;  // map width
 int  map_h;  // map height
} t_data;

typedef struct s_player //the player structure
{
 int  ply_x; // player x position in pixels
 int  ply_y; // player y position in pixels
} t_player;

typedef struct s_ray //the ray structure
{

} t_ray;

typedef struct s_mlx //the mlx structure
{
 mlx_image_t  *img; // the image
 mlx_t   *mlx_p; // the mlx pointer
 t_ray   *ray; // the ray structure
 t_data   *data; // the data structure
 t_player  *ply; // the player structure
} t_mlx;

#endif
