#include <unistd.h>

int	ft_printable(unsigned	char	c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	unsigned char ppr;

	i = 0;
	while (str[i])
	{
		ppr = (unsigned char)str[i];
		if (ft_printable(ppr))
			ft_putchar(ppr);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[ppr / 16]);
			ft_putchar("0123456789abcdef"[ppr % 16]);
		}
		i++;
	}
}
