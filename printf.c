#include "main.h"
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include <stdarg.h>
/**
*_printf - function to print just like printf
*@format: fixed string parameter for the function
*Return: Always (0)
*/
int _printf(const char *format, ...)
{

	char *t;
	void *y;
	int x, i = 0;
	char ans;
    	va_list args;
    	va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'd':
                {
                    x = va_arg(args, int);
                    ans = '0' + x;
                    putchar(ans);
                    break;
                }
                case 'f':
                {
                    x = va_arg(args, double);
                    putDouble(x,5);
                    break;
                }
                case 'c':
                {
                    x = va_arg(args, int);
                    write(1, &x, 1);
                    break;
                }
                case 's':
                {
                    t = va_arg(args, char*);
                    write(1, t, strlen(t));
                    break;
                }
                case 'x':
                case 'X':
                {
                    x = va_arg(args, int);
                    putchar(x);
                    break;
                }
                case 'p':
                {
                    y = va_arg(args, void*);
                    write(1,y,strlen(y));
                    break;
                }
                case '%':
                    putchar('%');
                    write(1,"&%",sizeof(char));
                    break;
                default:
                    putchar(format[i]);
                    break;
            }
        }
        else
        {
            putchar(format[i]);
        }
        i++;
    }
    putchar('\n');

    va_end(args);
    return 0;
}

