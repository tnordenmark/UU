#include <cstdio>
using namespace std;

int main()
{
    int a[5] = {1,2,3,4,5};
    int *p1;
    p1 = &a[1];
    int dave;
    dave = *(p1+2);
    printf("*p1 = %d\n", *p1);
    printf("dave = %d\n", dave);
}
