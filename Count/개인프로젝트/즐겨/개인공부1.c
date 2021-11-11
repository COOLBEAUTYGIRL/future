#include <unistd.h>

void    print_memory(const void *addr, __SIZE_TYPE__ size)
{
    __SIZE_TYPE__   i;
    __SIZE_TYPE__   j;        
    unsigned char   *p;
    char    *str;

    str = "0123456789abcdef";
    p   =   (unsigned char *)addr;
    i = 0;
    
    while (i < size)
    {
        j = 0;
        while (j < 16 && i + j < size)
        {
            write(1, &str[(*(p + i + j)/16) % 16], 1);
            write(1, &str[*(p + i + j) % 16], 1);
            if (j % 2)
                write (1, " ", 1);
                j += 1;
        }
        while (j < 16)
        {
            write(1, " ", 1);
            if (j % 2)
                write (1, " ", 1);
                j++;
        }
        j = 0;
        while (j < 16 && i + j < size)
        {
            if (*(p + 1 + j)>= 32 && *(p + i + j) < 127)
                write (1, p + i + j, 1);
                else
                    write (1, ".", 1);
                    j += 1;
        }
        write(1, "\n", 1);
        i += 16;
    }
}