/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:10:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/10/13 15:47:36 by marvin           ###   ########.fr       */
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
#include <stdbool.h>

# define S_W 640
# define S_H 480
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
# define RST "\033[0m"
# define BLACK_PR "\033[0;30m"
# define RED_PR "\033[0;31m"
# define GREEN_PR "\033[0;32m"
# define YELLOW_PR "\033[0;33m"
# define BLUE_PR "\033[0;34m"
# define PURPLE_PR "\033[0;35m"
# define WHITE_PR "\033[0;37m"

// macros for exit
# define NONE 0
# define MLX 1
# define PARSER 2
# define XPM 3
# define TEX_PIX 4
# define BONUS 5
# define ALL 6

// movement
# define NO 1
# define SO 2
# define EA 3
# define WE 4
# define RUN 5
# define WALK 6

# define TILE_SIZE 512
# define NUM_RAYS 320
# define ROTATION_SPEED 0.025

# ifndef BONUS
#  define BONUS 1
# endif

//minimap
# define PIXEL_SIZE 128
# define VIEW_DIST 4

typedef struct s_file
{
	char				*s;
	struct s_file		*next;
}						t_file;



typedef struct s_data
{
	int				player_dir;
	int				exit;
	char			*north; //wall path
	char			*south;
	char			*west;
	char			*east;
	char			*ply;
	char			*fire;
	char			*door; //path
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
	int				rot_r;
	int				rot_l;
	int				sprint;
	int				door; //status
	int				fire;
	double			gauge;
}					t_player;

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
	int				door;
}					t_ray;

typedef struct s_image
{
	void				*img;
	int					pixel_bits;
	int					size_line;
	int					endian;
	int					*pixels;
}						t_image;

typedef struct s_tex
{
	int				*ply;
	int				*fire;
	int				*door;
	int				*no;
	int				*so;
	int				*ea;
	int				*we;
	int				dir;
	int				x;
	int				y;
	double			step;
	double			pos;
}					t_tex;

typedef struct s_minimap
{
	int				**nswe;
	char			**map;
	t_image			*img;
	int				size;
	int				off_x;
	int				off_y;
	int				view_dist;
	int				tile_size;
	int				color_ply;
	int				color_floor;
	int				color_wall;
	int				color_space;
	int				color_door;
}					t_minimap;

typedef struct s_mlx
{
	double			ply_speed;
	double			rot_speed;
	int				img_size;
	int				**tex_pix;
	int				**ply_pix;
	// int				**door_pix;
	int				*gun;
	void			*mlx_p;
	void			*win;
	t_ray			ray;
	t_data			data;
	t_player		ply;
	t_image			img;
	t_file			file;
	t_tex			tex;
	t_image			minimap;
	t_minimap		mm;
	bool			door; //key_press
}					t_mlx;


void				set_walk_speed(t_mlx *mlx, int flag);
void				draw_pix(t_image *img, int x, int y, int color);
int					get_player_pos(t_data *data);
// ! INITS
void				init_mlx(t_mlx *game);
void				init_data(t_mlx *mlx, t_data *data, char **av);
void				init_ray(t_ray *ray);
void				init_player(t_mlx *mlx, t_player *ply);
void				init_images(t_mlx *game);
void				init_tex(t_tex *tex);
void				init_tex_pix(t_mlx *mlx);
void				init_ply_pix(t_mlx *mlx);
void				init_player(t_mlx *mlx, t_player *ply);
int					*my_xpm_to_file(t_mlx *game, char *path, int size);


// ! MOVEMENT
int						rotate_view(t_mlx *mlx, double rot_dir);
int						key_release(int keycode, t_mlx *ml);
int						key_press(int keydata, t_mlx *ml);
int						move_player(t_mlx *mlx);
void					handle_ply_movement(t_mlx *mlx, double move_x,
							double move_y);
int						wall_hit(t_mlx *mlx, double x, double y);
int						check_direction(double angle, char c);
int						validate_move(t_mlx *mlx, double new_x, double new_y);

// ! PARSING
int					check_file(t_data *data);
int					check_map(char **map);
long				get_color(int r, int g, int b);
char				**make_square_map(t_data *m);
int					check_rgb(t_data *data, t_file *tmp, char c);
int					check_textures(t_data *data, t_file *file);
int					is_player(char c);
int					is_invalid(char c);
int					get_w(t_data *d);
int					get_h(t_data *d);

// ! RAYCASTING
void					cast_rays(t_mlx *mlx);
double					normalize_angle(double angle);
double					get_v_inter(t_mlx *mlx, double angle);
double					get_h_inter(t_mlx *mlx, double angle);
double					adjust_inter(double angle, double *inter, double *step,
							int h);

void	render_player(t_mlx *mlx, t_image *img);
void				render_image(t_mlx *mlx);
int					is_valid_pos(t_data *data, double x, double y);
int					is_not_wall(char **map, double x, double y);
int					loop_render(t_mlx *mlx);
void				img_do(t_mlx *mlx, t_image *img, int h, int w);
void				set_textures(t_mlx **mlx, t_tex *tex, t_ray *ray, int x);
// ! UTILS
// * extension_utils
int						is_xpm(char *s);
int						is_cub(char *s);
int						is_png(char *s);

// * frees
void					free_file_list(t_file *file);
void free_data(t_data *data);
void					free_mlx(t_mlx *game);
void free_tex(t_tex *tex);
void	ft_exit(t_mlx *mlx, char *msg, int flag, int exit_code);
void	*cub_malloc(t_mlx *mlx, int flag, size_t nmemb, size_t size);
void pre_exit(char *msg, int exit_code);

// * init_utils
char					**return_map(t_data *data);
int						count_lines(t_file *file);
t_file					*return_map_start(t_file *file);
int						check_if_map(char *s);

// * list_utils
void					add_to_list(t_file **lst, t_file *new);
void					string_to_list(t_data *data);

// * parse_utils
void					pr_str(t_file *f);
void					print_data(t_data *data);
void					print_textures(t_data *data, int i);


// * map_utils
int						get_maxlen(char **map);
int						get_h_map(char **map);
char					*fill_map(char *map_line, int maxlen);
int						check_w_map(char **map);
int						check_h_map(char **map);

// ! BONUS
// *minimap
void				render_mmap_img(t_mlx *mlx, t_image *img);
char				**create_map(t_mlx *mlx, t_minimap *minimap);
char				*add_mmap_line(t_mlx *mlx, t_minimap *mm, int y);
void				ft_free_tab(void **tab);
int					get_mmap_off(t_minimap *mm, int map_size, int pos);
void				handle_door(t_mlx *mlx);
void				handle_door(t_mlx *mlx);
void				init_door_pix(t_mlx *mlx);
void				render_door(t_mlx *mlx, t_image *img);
#endif
