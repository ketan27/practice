#include <stdio.h>
#include <stdlib.h>

int TIME_min = 15*60;

void bogus()
{
    sleep(TIME_min);

}
int main()
{
    bogus();

    return 0;
}

