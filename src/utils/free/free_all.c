#include "cub3d.h"

void    free_all(t_main *main)
{
    free_ray_array(main->ray_array);
    mlx_terminate(main->mlx_data.mlx);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}