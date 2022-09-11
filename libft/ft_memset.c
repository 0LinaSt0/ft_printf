#include "libft.h"

void	*ft_memset(void *des, int c, size_t n)
{
	size_t			i;
	unsigned char	*z;

	i = 0;
	z = (unsigned char *) des;
	while (i < n)
	{
		z[i] = (unsigned char) c;
		i++;
	}
	return (z);
}
