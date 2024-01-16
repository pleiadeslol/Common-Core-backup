#include "minilibx/mlx.h" 

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int main(void)
{
    void *mlx;
    void *mlx_win;
    t_data img;
    int x = 0, y = 0;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                    &img.endian);
    while (x <= 1920)
    {
        y = 0;
        while (y <= 1080)
        {
            if (y <= 540)
                mlx_pixel_put(&img, mlx_win, x, y, 0x00eab676);
            else
                mlx_pixel_put(&img, mlx_win, x, y, 0x00abdbe3);
            y++;
        }
        x++;
    }
    // mlx_pixel_put(&img, mlx_win, 40, 40, 0x009933FF);
    // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}