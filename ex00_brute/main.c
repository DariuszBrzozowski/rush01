#include <unistd.h>

int		parse_input(char *input, int *top, int *bottom, int *left, int *right);
int		brute_force(int mtrx[4][4], int *top, int *bottom, int *left, int *right);
void	set_mtrx_to_zero(int mtrx[4][4]);
void	print_mtrx(int mtrx[4][4]);

int	main(int argc, char **argv)
{
	int	mtrx[4][4];
	int	top_input[4];
	int	bottom_input[4];
	int	left_input[4];
	int	right_input[4];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!parse_input(argv[1], top_input, bottom_input, left_input, right_input))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	set_mtrx_to_zero(mtrx);
	if (brute_force(mtrx, top_input, bottom_input, left_input, right_input))
		print_mtrx(mtrx);
	else
		write(1, "Error\n", 6);
	return (0);
}
