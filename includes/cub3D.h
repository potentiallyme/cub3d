/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:10:48 by lmoran            #+#    #+#             */
/*   Updated: 2024/08/14 15:31:56 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"

# define NO 1
# define SO 2
# define EA 3
# define WE 4

typedef struct s_file
{
	char	*s;
	t_file	*next;
}			t_file;
 
typedef struct s_info
{
	// * raw file
	char	*file;
	t_file  *linked_file;
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

#endif
