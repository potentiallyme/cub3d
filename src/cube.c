#include "../includes/cub3D.h"

int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !check_filetype())
		return (0);
	if (!parsing(&data))
		return (0);
	exec(&data);
}
