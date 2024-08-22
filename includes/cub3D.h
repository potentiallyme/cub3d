/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu-chen <yu-chen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:10:48 by lmoran            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/08/14 14:48:23 by yu-chen          ###   ########.fr       */
=======
/*   Updated: 2024/08/19 15:45:16 by yu-chen          ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

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

# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define NO 1
# define SO 2
# define EA 3
# define WE 4

# define TILE_SIZE 30
# define FOV (60 * M_PI / 180) // field of view = 60
#define NUM_RAYS 320  // Number of rays to cast

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
	int p_x; // player x position in pixels
	int p_y; // player y position in pixels
	double	angle;
	float	fov_radian;
	
}			t_player;

typedef struct s_ray // the ray structure
{
	double	ray_angle;
	double	distance; //distance to wall
	int		wall_flag;
	int		index; //for rendering
}			t_ray;

// typedef struct s_texture
// {
// 	uint32_t	width;
// 	uint32_t	height;
// 	uint8_t		bytes_per_pixel;
// 	uint8_t*	pixels;
// }	t_texture;

typedef struct s_texure
{
	t_image	*no_img;
	t_image	*so_img;
	t_image	*we_img;
	t_image	*ea_img;
}	t_texure;

typedef struct s_instance
{
	int32_t	x;
	int32_t	y;
	int32_t	z;
}	t_instance;

typedef struct s_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	t_instance*	instances;
}	t_image;

typedef struct s_mlx // the mlx structure
{
	t_mlx *mlx_p;     // the mlx pointer
	t_ray *ray;       // the ray structure
	t_data *data;     // the data structure
	t_player *ply;    // the player structure
	t_image *img; // the image
	t_texure *tex; 
}			t_mlx;

double	normalize_angle(double angle);

#endif
