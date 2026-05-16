int	visible(int *line, int reverse)
{
	int	i;
	int	max;
	int	count;

	if (reverse)
		i = 3;
	else
		i = 0;
	max = 0;
	count = 0;
	while ((!reverse && i < 4) || (reverse && i >= 0))
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		if (reverse)
			i--;
		else
			i++;
	}
	return (count);
}

int	check_constraints(int mtrx[4][4], int *top, int *bottom, int *left, int *right)
{
	int	i;
	int	col[4];

	i = 0;
	while (i < 4)
	{
		if (visible(mtrx[i], 0) != left[i])
			return (0);
		if (visible(mtrx[i], 1) != right[i])
			return (0);
		col[0] = mtrx[0][i];
		col[1] = mtrx[1][i];
		col[2] = mtrx[2][i];
		col[3] = mtrx[3][i];
		if (visible(col, 0) != top[i])
			return (0);
		if (visible(col, 1) != bottom[i])
			return (0);
		i++;
	}
	return (1);
}

int	can_place(int mtrx[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mtrx[row][i] == num)
			return (0);
		if (mtrx[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	brute_force(int mtrx[4][4], int *top, int *bottom, int *left, int *right)
{
	int	pos;
	int	row;
	int	col;
	int	num;

	pos = 0;
	while (pos >= 0)
	{
		if (pos == 16)
		{
			if (check_constraints(mtrx, top, bottom, left, right))
				return (1);
			pos--;
		}
		else
		{
			row = pos / 4;
			col = pos % 4;
			num = mtrx[row][col] + 1;
			mtrx[row][col] = 0;
			while (num <= 4 && !can_place(mtrx, row, col, num))
				num++;
			if (num <= 4)
			{
				mtrx[row][col] = num;
				pos++;
			}
			else
				pos--;
		}
	}
	return (0);
}
