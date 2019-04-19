#include <../minilibx/mlx.h>

int	main()
{
    void    *ptr;
    void    *win;

	ptr = mlx_init();
    win = mlx_new_window(ptr, 500, 500, "21");
    if (argc == 2)
	{
		if (!((fd = open(argv[1], O_RDONLY)) >= 0))
            ft_print_error(ERR_MAP);
        mlx_string_put(ptr, win, 250, 250, 0xFFFFFF, "HELLO");
        mlx_loop(ptr);
    }
    ft_print_error(ERR_USAGE);
    return (0);
    
}
