#include<unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

int     prime_num(int nb)
{
        long    i;

        i = 2;
        while (i * i <= nb)
        {
                if (nb % i == 0)
                        return (0);
                i++;
        }
        return (1);
}

long long       prime_sum(int nb)
{
        long long       i;
        long long       sum;

        i = 2;
        sum = 0;
        while (i <= nb)
        {
                if (prime_num(i))
                        sum += i;
                i++;
        }
        return (sum);
}

long long       atoi(char *str)
{
        int     i;
        int     op;
        long long       res;

        i = 0;
        op = 1;
        res = 0;
        while (str[i] >= 9 && str[i] <= 13)
                i++;
        while (str[i] == '+' || str[i] == '-')
        {
                if (str[i] == '-')
                        op *= -1;
                i++;
        }
        while (str[i] >= '0' && str[i] <= '9')
        {
                res = res * 10 + str[i] - '0';
                i++;
        }
        return (res * op);
}

void    ft_putnbr(long long nb)
{
        if (nb <= 0)
                return ;
        ft_putnbr(nb / 10);
        ft_putchar(nb % 10 + '0');
}

int     main(int ac, char *av[])
{
        long long       nb;

        if (ac == 2)
        {
                nb = prime_sum(atoi(av[1]));
                if (nb > 1)
                {
                        ft_putnbr(nb);
                }
                else
                        write(1, "0", 1);
        }
        else
                write(1, "0", 1);
        write(1, "\n", 1);
        return (0);
}
#include<unistd.h>

int     main(int ac, char *av[])
{
        int     i;
        i = 0;
        if (ac == 2)
        {
                while ((av[1][i] >= 9 && av[1][i] <= 13) || av[1][i] == ' ')
                        i++;
                while (av[1][i])
                {
                        if ((av[1][i] >= 9 && av[1][i] <= 13) || av[1][i] == ' ')
                        {
                                if (av[1][i + 1] >= 33 && av[1][i + 1] <= 126)
                                        write(1, " ", 1);
                        }
                        else if (av[1][i] >= 33 && av[1][i + 1] <= 126)
                                write(1, &av[1][i], 1);
                        i++;
                }
        }
        write(1, "\n", 1);
}
#include<unistd.h>

int     check(char *str, char c, int pos)
{
        int     i;

        i = 0;
        while (i < pos)
        {
                if (c == str[i])
                        return (0);
                i++;
        }
        return (1);
}

int     main(int ac, char *av[])
{
        int     i;
        int     j;

        i = 0;
        if (ac == 3)
        {
                while (av[1][i])
                {
                        j = 0;
                        while (av[2][j])
                        {
                                if (av[1][i] == av[2][j])
                                {
                                        if (check(av[1], av[1][i], i))
                                        {
                                                write(1, &av[1][i], 1);
                                                break ;
                                        }
                                }
                                j++;
                        }
                        i++;
                }
        }
        write(1, "\n", 1);
        return (0);
}
#include<unistd.h>

int     main(int ac, char *av[])
{
        int     i;
        int     j;

        i = 0;
        if (ac == 2)
        {
                while (av[1][i])
                {
                        if (av[1][i] == ' ' && av[1][i + 1] >= 33
                                        && av[1][i + 1] <= 126)
                                j = i + 1;
                        i++;
                }
                while (av[1][j] >= 33 && av[1][j] <= 126)
                {
                        write (1, &av[1][j], 1);
                        j++;
                }

        }
        write(1, "\n", 1);
        return (0);
}
#include<unistd.h>

int     max(int *tab, unsigned int len)
{
        int     max_num;
        int     i;
        int     tmp;

        max_num = 0;
        if (tab == 0)
                return (0);
        while (tab[i])
        {
                if (tab[i] > max_num)
                        max_num = tab[i];
        }
        return (max_num);
}
#include<unistd.h>

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
        if (nb > 9)
        {
                ft_putnbr(nb/10);
                ft_putnbr(nb%10);
        }
        else
                ft_putchar(nb + '0');
}

int     main(int ac, char *av[])
{
        (void)av;
        ac--;
        ft_putnbr(ac);
        ft_putchar('\n');
        return (0);
}
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int     ft_isspace(char c)
{
        if ((c >= 9 && c <= 13) || c == ' ')
                return (1);
        return (0);
}

int     total_length(char *str)
{
        int     len;
        int     i;

        len = 0;
        i = 0;
        while (str[i])
        {
                if (ft_isspace(str[i]))
                        len++;
                i++;
        }
        return (len);
}

char    **ft_split(char *str)
{
        int     i;
        char    **arr;
        int     st;
        int     k;
        int     j;

        i = 0;
        st = 0;
        j = 0;
        arr =malloc(sizeof(char *) * total_length(str) + 1);
        while (str[i] && j <= total_length(str))
        {
                while (str[i] && ft_isspace(str[i]))
                        i++;
                while (str[i] && !ft_isspace(str[i]))
                {
                        st++;
                        i++;
                }
                arr[j] = malloc(sizeof(char) * st + 1);
                if (arr[j] == 0)
                        return (0);
                k = 0;
                while (st)
                {
                        arr[j][k] = str[i - st];
                        st--;
                        k++;
                }
                arr[j][k] = 0;
                j++;
        }
        arr[i] = 0;
        return (arr);
}

int     main(int ac, char *av[])
{
        int     i;
        char    **arr;

        i = 0;
        if (ac == 2)
        {
                arr = ft_split(av[1]);
                for(i=0;i<10;i++)
                {
                        printf("%s", arr[i]);
                        if (arr[i] == 0)
                                break ;
                        printf("\n");
                }
        }
        else
                write(1, "\n", 1);
        return (0);
}

#include<unistd.h>

int     check_word(char *s1, char c, int pos)
{
        int     i;

        i = 0;
        while (i < pos)
        {
                if (s1[i] == c)
                        return (0);
                i++;
        }
        return (1);
}

int     double_check_word(char *s2, char c)
{
        int     i;

        i = 0;
        while (s2[i])
        {
                if (s2[i] == c)
                        return (0);
                i++;
        }
        return (1);
}

int     main(int ac, char *av[])
{
        int     i;
        //char  c;

        i = 0;
        if (ac == 3)
        {
                while (av[1][i])
                {
                        if (check_word(av[1], av[1][i], i))
                                write(1, &av[1][i], 1);
                        i++;
                }
                i = 0;
                while (av[2][i])
                {
                        if (double_check_word(av[1], av[2][i]))
                        {
                                if (check_word(av[2], av[2][i], i))
                                {
                                        /*c = av[2][i];
                                        write(1, &c, 1);*/
                                        write(1, &av[2][i], 1);
                                }
                        }
                        i++;
                }
        }
        write(1, "\n", 1);
        return (0);
}