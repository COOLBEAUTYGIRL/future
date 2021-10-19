#include <unistd.h>

unsigned	int	ft_strlen(char	*str)
{
	unsigned	int	i;
	
	i	=	0;
	while (str[i])
		i++;
	return (i);
}

unsigned	int	ft_strlcpy(char *dest,	char *sre,	unsigned	int	size)
{
	unsigned	int	i;

	i = 0;
	if	(size == 0)
		return (ft_strlen(sre));
	while	(sre[i] && i < size -1)
	{
		dest[i] = sre[i];
		i++;
	}
	dest[i] = '\0';
	return	(ft_strlen(sre));
}
