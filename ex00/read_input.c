/*#include <unistd.h>*/


int read_input_i(char *input, int *input_i)
{
    int i;
    
    i = 0;
    while (i < 16)
    {
        input_i[i] = 0;
        i++;
    }

    i = 0;
    while (i < 16)
    {
        input_i[i] = input[2 * i] - '0';
        i++;
    }
    i = 0;
    while (i < 16)
    {
        if (input_i[i] == 0 )
        {
            return 0;
        }
        i++;
    }

    return (1);
}
void split_input_i(int input_i[16], int *ctop, int *cbottom, int *rleft, int *rright){
    int i;

    i = 0;
    while (i < 4)
    {
        ctop[i] = input_i[i];
        cbottom[i] = input_i[i+4];
        rleft[i] = input_i[i+8];
        rright[i] = input_i[i+12];
        i++;
    }
}