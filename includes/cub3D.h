/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:10:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/08/14 16:44:06 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>

# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define NO 1
# define SO 2
# define EA 3
# define WE 4

typedef struct s_file // ! used for parsing
{
	char	*s;
	t_file	*next;
}			t_file;

typedef struct s_info // ! used for parsing for now
{
	// * raw file
	char	*file;
	t_file	*linked_file;
	// * map info (1s and 0s)
	char	**map;
	// * direction texture paths
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	// * colours rgb format:(255, 255, 255)
	char	*floor;
	char *ceiling
}			t_info;
// ? need to merge s_info and s_data moving forward, tbd
typedef struct s_data // the data structure
{
	char **map2d; // the map
	int p_x;      // player x position in the map
	int p_y;      // player y position in the map
	int map_w;    // map width
	int map_h;    // map height
}			t_data;

typedef struct s_player // the player structure
{
	int ply_x; // player x position in pixels
	int ply_y; // player y position in pixels
}			t_player;

typedef struct s_ray // the ray structure
{
}			t_ray;

typedef struct s_mlx // the mlx structure
{
	mlx_image_t *img; // the image
	mlx_t *mlx_p;     // the mlx pointer
	t_ray *ray;       // the ray structure
	t_data *data;     // the data structure
	t_player *ply;    // the player structure
}			t_mlx;

#endif
