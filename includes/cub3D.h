/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:10:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/09/17 14:25:51 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>

# define S_W 960 // screen width
# define S_H 720 // screen height
# define NO 1
# define SO 2
# define EA 3
# define WE 4
# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAIL 0

typedef struct s_file // ! used for parsing
{
	char *s;
	struct s_file *next;
}			t_file;

typedef struct s_info
{
	int exit;
	int map_w; // map width
	int map_h; // map height
	char	*file;
	t_file	*linked_file;
	char	**map2d;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		*floor;
	int		*ceiling;
}			t_info;

typedef struct s_player // the player structure
{
	int ply_x; // player x position in pixels
	int ply_y; // player y position in pixels
	int p_x;   // player x position in the map
	int p_y;   // player y position in the map
}			t_player;

typedef struct s_ray
{
}			t_ray;

typedef struct s_data // the mlx structure
{
	int exit;
	void *mlx;
	void *win;
	t_ray *ray;    // the ray structure
	t_info *info;  // the file info and map
	t_player *ply; // the player structure
}			t_data;

// * inits
t_data		*init_mlx(void);
t_info		*init_data(char **av);
t_ray		*init_ray(void);
t_player	*init_player(t_info *info);

// * parse_map
int check_map(char **map);

// * parse_file
int			check_file(t_info *data);

// * parse_textures
char		*return_texture_paths(t_file *file, char *dir);
int			recursive_check(t_info *data, t_file *file, char *s, int i);
int			check_textures(t_info *data, t_file *file);
int			check_texture_paths(t_info *data);

// * extension_utils
int			is_xpm(char *s);
int			is_cub(char *s);
int			is_png(char *s);

// * frees
void		free_file_list(t_file *file);
void		*free_during_init(t_info *data);
void		free_mlx(t_data *game, int exit_code);
// * list_utils
void		add_to_list(t_file **lst, t_file *new);
void		string_to_list(t_info *data);

// * parse_utils
void	print_data(t_info *data);
void	print_textures(t_info *data, int i);

// * init_utils
char		**return_map(t_info *data);

#endif
