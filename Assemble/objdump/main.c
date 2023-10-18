#include <stdio.h>
#include <stdlib.h>
#include "add.h"

int out_sum;

int main(int args, char *argv[])
{
    int id = module_id;
    char* name = module_name;
    int sum;

    printf("module: %d %s\n", id, name);

    sum = add(2, 3);
    printf("sum: %d\n", sum);

    out_sum = sum;
    return 0;
}

