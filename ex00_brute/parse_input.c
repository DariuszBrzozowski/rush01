int	parse_input(char *input, int *top, int *bottom, int *left, int *right)
{
	int	i;
	int	values[16];

	i = 0;
	while (i < 16)
	{
		if (input[i * 2] < '1' || input[i * 2] > '4')
			return (0);
		values[i] = input[i * 2] - '0';
		if (i < 15 && input[i * 2 + 1] != ' ')
			return (0);
		i++;
	}
	if (input[31] != '\0')
		return (0);
	i = 0;
	while (i < 4)
	{
		top[i] = values[i];
		bottom[i] = values[i + 4];
		left[i] = values[i + 8];
		right[i] = values[i + 12];
		i++;
	}
	return (1);
}
