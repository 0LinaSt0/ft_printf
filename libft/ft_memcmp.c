#include "libft.h"

int 	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sf;
	unsigned char	*ss;

	i = 0;
	sf = (unsigned char *)s1;
	ss = (unsigned char *)s2;
	while (i < n)
	{
		if (sf[i] != ss[i])
			return (sf[i] - ss[i]);
		i++;
	}
	return (0);
}
