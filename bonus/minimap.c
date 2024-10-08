// //bonus minimap 

// #include "../includes/cub3D_bonus.h"


// void    fill_tiles_color(t_mlx *mlx, int x, int y, color)
// {
    
// }

// void    render_minimap_tiles(t_mlx* mlx)
// {
//     int x;
//     int y;
//     int ply_x;
//     int ply_y;

//     y = 0;
//     ply_y = 0;
//     while (y < mlx->data->map_h)
//     {
//         x = 0;
//         ply_x = 0;
//         while (x < mlx->data->map_w)
//         {
//             if (mlx->data->square_map[y][x] == '1')
//                 fill_tiles_color(mlx, ply_x, ply_y, GREY);
//             else
//                 fill_tiles_color(mlx, ply_x, ply_y, WHITE);
//             x++;
//             ply_x += TILE_SIZE;
//         }
//         y++;
//         ply_y += TILE_SIZE;
//     }

// }

// void render_minimap_player(t_mlx *mlx, int p_x, int p_y)
// {

// }

// void    render_minimap(t_mlx* mlx)
// {
//     render_minimap_tiles(mlx);
//     render_minimap_player(mlx, mlx->ply->p_x, mlx->ply->p_y);
// }