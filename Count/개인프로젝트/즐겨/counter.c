#include <unistd.h>
#include <stdlib.h>

void    brainfuck(char *str)
{
    int tab[2048] = {0};
    int *ptr;
    int loop_count;

    ptr = tab;
    loop_count = 0;
    while (*str)
    {
        if (*str == '>')
            ptr++;
            else if (*str == '<')
                ptr--;
                else if (*str == '+')
                    ++(*ptr);
                    else if (*str == '-')
                    --(*ptr);
                    else if (*str == '.')
                    write(1, ptr, 1);
                        else if (*str == '[' && *ptr == 0)
                        {
                            loop_count = 1;
                            while (loop_count != 0)
                            {
                                str++;
                                if (*str == ']')
                                    --loop_count;
                                    if(*str == '[')
                                    ++loop_count;

                            }
                        }
                        else if (*str == ']' && *ptr != 0)
                        {
                            loop_count = 1;
                            while (loop_count != 0)
                            {
                                str--;
                                if(*str == '[')
                                    --loop_count;
                                if(*str == ']')
                                    ++loop_count;
                            }
                        }
                        str++;
    }
}
int main(int ac, char *av[])
{
    if (ac == 2)
        brainfuck(av[1]);
        else
            write(1, "\n", 1);
            return (0);
}