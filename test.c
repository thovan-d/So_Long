// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------
// gcc test.c MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/thovan-d/.brew/opt/glfw/lib/"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "MLX42/include/MLX42/MLX42.h"
#define WIDTH 512
#define HEIGHT 512


if (map[i] != NULL)
	map[i] = get_next_line(fd);

static mlx_image_t* img;
static mlx_image_t* img2;
static int x;

void hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		img->instances[0].y -= 5;
		img2->instances[0].y -= 5;
		x++;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		img->instances[0].y += 5;
		img2->instances[0].y += 5;
		x++;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		img->instances[0].x -= 5;
		x++;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		img->instances[0].x += 5;
		x++;
	}
}

int32_t	main(void)
{
	mlx_t* mlx;
	// mlx_texture_t* mario;

	x = 0;
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return(EXIT_FAILURE);
	img = mlx_new_image(mlx, 128, 128);
	img2 = mlx_new_image(mlx, 64, 64);
	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	memset(img2->pixels, 100, img2->width * img2->height * sizeof(int));
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_image_to_window(mlx, img2, 30, 30);

	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	printf("Moves: %d", x);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}