#include <stdio.h>
#include <stdlib.h>

struct tmp {
    char data;
};

int main()
{

#if DBG < 4
    printf("less than 4\n");
#else
    printf("greater than 4\n");
#endif

    char ch = 'c';
    struct tmp *tmp = (struct tmp*)malloc(sizeof(struct tmp));

    tmp->data = 'c';

    if (tmp->data == ch)
        printf("matched\n");

    return 0;
}
