#include <stdio.h>

void swap(int* ptr1, int* ptr2, int* ptr3);

int main()
{
    int x = 7, y = 4, z = 9;
    int* p = &x;
    int* q = &y;
    int* r = &z;
    printf("x = %d\ty = %d\tz = %d\tp = 0x%p\tq = 0x%p\tr = 0x%p\t*p = %d\t*q = %d\t*r = %d\n", x, y, z, p, q, r, *p, *q, *r);
    printf("Swapping pointers\n");
    swap(p, q, r);
    printf("x = %d\ty = %d\tz = %d\tp = 0x%p\tq = 0x%p\tr = 0x%p\t*p = %d\t*q = %d\t*r = %d\n", x, y, z, p, q, r, *p, *q, *r);
    return 0;
}

void swap(int* ptr1, int* ptr2, int* ptr3)
{
    int temp = *ptr3;
    *ptr3 = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    return;
}