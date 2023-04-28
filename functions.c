#include "main.h"
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <stdarg.h>

/**
*putLong - function to print a single digits of a float
*@x: parameter to be printed
*Return: void
*/


void putLong(long x)
{
    if(x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x >= 10)
    {
        putLong(x / 10);
    }
    putchar(x % 10+'0');
}




/**
*putLong - function to print a single digits of a float
*@x: parameter to be printed
*Return: void
*/

void putDouble(double x, int p)
{
    long d;
    if (x<0) {
        putchar('-');
        x=-x;
    }
    d = x;
    putLong(d);
    putchar('.');
    while (p--) {
        x = (x - d) * 10;
        d = x;
        putchar('0'+d);
    }
}
