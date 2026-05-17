#include <unistd.h>

int read_input_i(char *input, int *input_i);
void init_matrix_with_zeros(int matrix[4][4]);
void print_matrix(int matrix[4][4]);
int find_solution(int matrix[4][4], int input_i[16]);

int main(int argc, char *argv[])
{
    int status_ok;
    int input_i[16];
    int matrix[4][4];
    
    status_ok = 0;
    if (argc == 2)
    {
        status_ok = read_input_i(argv[1], input_i);
        if (status_ok)
        {
            init_matrix_with_zeros(matrix);
            status_ok = find_solution(matrix, input_i);
        }
    }

    if (status_ok)
        print_matrix(matrix);
    else
        write(1, "Error\n", 6);
    
}