#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	long int	n;
	int			z;

	i = 0;
	n = 0;
	z = 1;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v' || nptr[i] == '\f'
		|| nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			z = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	n *= z;
	return (n);
}
