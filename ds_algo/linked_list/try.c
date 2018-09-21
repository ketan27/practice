#include <stdio.h>

#ifdef DBG
#define ENTER_MSG printf("%s() called\n", __func__)
#else
#define ENTER_MSG
#endif

void hello()
{
    ENTER_MSG;

    printf("hello world\n");

}

int main()
{
    hello();

    return 0;
}
