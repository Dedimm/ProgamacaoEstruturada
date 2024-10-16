#include <stdio.h>
int main()
{
    int mat[] = {27, 19, 5}, j, *ptr1, *ptr2;

    ptr1 = ptr2 = mat;

    for (j = 0; j < 3; j++, ptr2++)
    {
        printf("%i", ptr2-ptr1);
    }
}