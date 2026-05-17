#include <unistd.h>

void init_matrix_with_zeros(int matrix[4][4])
{
    int i;
    int j;
    

    i = 0;

    while (i < 4){
        j = 0;
        while (j < 4)
        {
            matrix[i][j] = 0;
            j++;
        }
        i++;
    }
}

void print_matrix(int matrix[4][4])
{
    int i;
    int j;
    char c;

    i = 0;

    while (i < 4){
        j = 0;
        while (j < 4)
        {
            c = matrix[i][j] + '0';
            write(1, &c, 1);
            if (j < 3)
                write(1, " ", 1);
            j++;
        }
        if (i < 3)
            write(1, "\n", 1);
        i++;
    }
}