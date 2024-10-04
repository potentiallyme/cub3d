/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:10:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/04 15:05:27 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define _USE_MATH_DEFINES
# define M_PI 3.14159265358979323846
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <float.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

# define S_W 1900
# define S_H 1000
# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAIL 0

// colors for map
# define BLACK 0x000000FF
# define GREY 0x808080FF
# define BLUE 0x87CEEBFF
# define GREEN 0x008000FF
# define ORANGE 0xFF9300FF
# define RED 0xFF0000FF
# define WHITE 0xFFFFFFFF

// colors for printf
# define rst "\033[0m"
# define black "\033[0;30m"
# define red "\033[0;31m"
# define green "\033[0;32m"
# define yellow "\033[0;33m"
# define blue "\033[0;34m"
# define purple "\033[0;35m"
# define white "\033[0;37m"

// movement
# define S_W 1900
# define S_H 1000
# define NO 1
# define SO 2
# define EA 3
# define WE 4

# define TILE_SIZE 512
# define FOV (60 * M_PI / 180)
# define NUM_RAYS 320
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

typedef struct s_image
{
	void			*img;
	int				pixel_bits;
	int				size_line;
	int				endian;
	int				*pixels;
}					t_image;

typedef struct s_tex
{
	int				*no;
	int				*so;
	int				*ea;
	int				*we;
}					t_tex;

typedef struct s_mlx
{
	int				img_size;
	int				**tex_pix;
	void			*mlx_p;
	void			*win;
	t_ray			ray;
	t_data			data;
	t_player		ply;
	t_image			img;
	t_file			file;
	t_tex			tex;
}					t_mlx;

typedef struct s_data
{
	int				player_dir;
	int				exit;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				p_x;
	int				p_y;
	int				map_w;
	int				map_h;
	char			*file;
	char			**map2d;
	char			**square_map;
	long			floor;
	long			ceiling;
	char			**c_floor;
	char			**c_ceiling;
	t_file			*linked_file;
}					t_data;

typedef struct s_player
{
	int				nswe;
	double			ply_x;
	double			ply_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rot;
}					t_player;

typedef struct s_file
{
	char			*s;
	struct s_file	*next;
}					t_file;

typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			wall_dist;
	double			wall_x;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_instance // player y position in pixels
{
	int32_t x;
	int32_t y;
	int32_t z;
}					t_instance;

int					get_color(int r, int g, int b);
void				draw_pix(t_image *img, int x, int y, int color);
void				img_set(t_mlx *mlx, t_image *img, int height, int width);
int		get_player_pos(t_data *mlx);
// ! INITS
void				init_mlx(t_mlx *game);
void				init_data(t_mlx *mlx, t_data *data, char **av);
void				init_ray(t_ray *ray);
void				init_player(t_mlx *mlx, t_player *ply);
void				init_images(t_mlx *game);

// ! MOVEMENT
void				rotate_view(t_mlx *mlx, int i);
int					key_release(int keycode, t_mlx *ml);
int					key_press(int keydata, t_mlx *ml);
void				move_player(t_mlx *mlx, double move_x, double move_y);
void				handle_ply_movement(t_mlx *mlx, double move_x,
						double move_y);
int					wall_hit(t_mlx *mlx, double x, double y);
int					check_direction(double angle, char c);

// ! PARSING
int					check_file(t_data *data);
int					check_map(char **map);
char				**make_square_map(t_data *m);
int					check_rgb(t_data *data, t_file *tmp, char c);
int					check_textures(t_data *data, t_file *file);
int					is_player(char c);

// ! RAYCASTING
void				cast_rays(t_mlx *mlx);
double				normalize_angle(double angle);
double				get_v_inter(t_mlx *mlx, double angle);
double				get_h_inter(t_mlx *mlx, double angle);
double				adjust_inter(double angle, double *inter, double *step,
						int h);

// ! RENDERING
void				rendering(t_mlx *mlx, int ray);
// void    render_walls(t_mlx *mlx, double t_pixel, double b_pixel,
//	double wall_h);
void				render_wall(t_mlx *mlx, double t_pix, double b_pix,
						double wall_h);
int					*get_texture(t_mlx *mlx, int wall_flag);
void				render_floor_ceiling(t_mlx *mlx, int ray, double t_pixel,
						double b_pixel);
void				new_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

// ! UTILS
// * extension_utils
int					is_xpm(char *s);
int					is_cub(char *s);
int					is_png(char *s);

// * frees
void				free_file_list(t_file *file);
void				free_during_init(t_mlx *mlx, t_data *data);
void				free_mlx(t_mlx *game, int exit_code);
void				ft_exit(t_mlx *mlx);

// * init_utils
char				**return_map(t_data *data);
int					count_lines(t_file *file);
t_file				*return_map_start(t_file *file);
int					check_if_map(char *s);

// * list_utils
void				add_to_list(t_file **lst, t_file *new);
void				string_to_list(t_data *data);

// * parse_utils
void				pr_str(t_file *f);
void				print_data(t_data *data);
void				print_textures(t_data *data, int i);

// * map_utils
int					get_maxlen(char **map);
int					get_h_map(char **map);
char				*fill_map(char *map_line, int maxlen);
int					check_w_map(char **map);
int					check_h_map(char **map);

#endif
