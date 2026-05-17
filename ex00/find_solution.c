
void split_input_i(int input_i[16], int *ctop, int *cbottom, int *rleft, int *rright);

int check_top_input(int matrix[4][4], int ctop[4])
{
    int i;
    int j;
    int cnt;

    j = 0;
    while (j < 4)
    {
        cnt = 0;
        i = 0;
        while (i < 3)
        {
            if (matrix[i][j] < matrix[i+1][j])
            {
                cnt++;
            }
            i++;
        }

        if (cnt != ctop[j])
            return (0);
        j++;
    }
    return (1);   
}

int check_bottom_input(int matrix[4][4], int cbottom[4])
{
    int i;
    int j;
    int cnt;

    j = 0;
    while (j < 4)
    {
        cnt = 0;
        i = 3;
        while (i > 0)
        {
            if (matrix[i][j] < matrix[i-1][j])
            {
                cnt++;
            }
            i--;
        }

        if (cnt != cbottom[j])
            return (0);
        j++;
    }
    return (1);   
}

int check_left_input(int matrix[4][4], int rleft[4])
{
    int i;
    int j;
    int cnt;

    i = 0;
    while (i < 4)
    {
        cnt = 0;
        j = 0;
        while (j < 3)
        {
            if (matrix[i][j] < matrix[i][j+1])
            {
                cnt++;
            }
            j++;
        }

        if (cnt != rleft[j])
            return (0);
        i++;
    }
    return (1);   
}

int check_right_input(int matrix[4][4], int rright[4])
{
    int i;
    int j;
    int cnt;

    i = 0;
    while (i < 4)
    {
        cnt = 0;
        j = 3;
        while (j >= 1)
        {
            if (matrix[i][j] < matrix[i][j-1])
            {
                cnt++;
            }
            j--;
        }

        if (cnt != rright[j])
            return (0);
        i++;
    }
    return (1);   
}

int is_ok(int matrix[4][4], int input_i[16])
{
    int ctop[4];
    int cbottom[4];
    int rleft[4];
    int rright[4];


    split_input_i(input_i, ctop, cbottom, rleft, rright);
    /* top column constraints*/
    if (check_top_input(matrix, ctop) == 0)
    {
        return 0;
    }
    
    if (check_bottom_input(matrix, cbottom) == 0)
    {
        return 0;
    }
    
    if (check_left_input(matrix, rleft) == 0)
    {
        return 0;
    }

    if (check_right_input(matrix, rright) == 0)
    {
        return 0;
    }

    return (1);

}

int cell_avail_for_num(int matrix[4][4], int row_index, int col_index, int num)
{
    int i;
    
    i = 0;
    while (i < 4)
    {
        if (matrix[row_index][i] == num)
        {
            return (0);
        }
        i++;
    }

    i = 0;
    while (i < 4)
    {
        if (matrix[i][col_index] == num)
        {
            return (0);
        }
        i++;
    }

    return (1);

}
    

int find_solution(int matrix[4][4], int input_i[16])
{
    int	counts[5];
	int	pos;
	int	row;
	int	col;
	int	num;
    
    /*numbers at disposal*/
	counts[1] = 4;
	counts[2] = 4;
	counts[3] = 4;
	counts[4] = 4;
	pos = 0;
	while (pos >= 0)
	{
		if (pos < 16)
		{
			row = pos / 4;
			col = pos % 4;
			num = matrix[row][col] + 1;
			if (matrix[row][col] >= 1 && matrix[row][col] <= 4)
				counts[matrix[row][col]]++;
			matrix[row][col] = 0;
			while (num <= 4 && counts[num] == 0)
				num++;
			if (num <= 4 && cell_avail_for_num(matrix, row, col, num))
			{
				matrix[row][col] = num;
				counts[num]--;
				pos++;
			}
			else
				pos--;
		}
		else
		{
        if (is_ok(matrix, input_i))
            return 1;
		pos--;
		}
	}

    return 0;
}