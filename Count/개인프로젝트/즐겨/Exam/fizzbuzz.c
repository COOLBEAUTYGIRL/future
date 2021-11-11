#include<unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_strnbr(int number)
{
    if (number < 10 && number >= 0)
    {
        ft_putchar(number + '0');
        return ;
    }
    if (number > 9)
    {
        ft_strnbr(number / 10);
        ft_putchar(number % 10 + '0');
        return ;
    }
}

int main()
{
    int number;
    
    number = 1;

    while (number <= 100)
    {
        if (number % 3 == 0 && number % 5 == 0)
        {
            write(1, "FizzBuzz", 8);
        }
        else if (number % 3 == 0)
        {
            write(1, "Fizz", 4);
        }
        else if (number % 5 == 0)
        {
            write(1, "Buzz", 4);
        }
        else
        ft_strnbr(number);
        write(1, "\n", 1);
        number++;
    }
}