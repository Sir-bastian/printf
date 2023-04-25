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
    va_list args;
    va_start(args, format);

    int i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'd':
                {
                    int x = va_arg(args, int);
                    char ans = '0' + x;
                    putchar(ans);
                    //write(1,ans,sizeof(int));
                    //close(x);
                    break;
                }
                case 'f':
                {
                    double x = va_arg(args, double);
                    putDouble(x,5);
                    break;
                }
                case 'c':
                {
                    int x = va_arg(args, int);
                    write(1, &x, 1);
                    fflush(stdout);
                    break;
                }
                case 's':
                {
                    char *x = va_arg(args, char*);
                    //printf("%s", x);
                    write(1, x, strlen(x));
                    break;
                }
                case 'x':
                case 'X':
                {
                    int x = va_arg(args, int);
                    putchar(x);
                    //write(1,&x,sizeof(int));
                    //close(x);
                    break;
                }
                case 'p':
                {
                    void *x = va_arg(args, void*);
                    //printf("%p", x);
                    write(1,x,strlen(x));
                    break;
                }
                case '%':
                    putchar('%');
                    //int r = write(1,"&%",sizeof(char));
                    //close(r);
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

