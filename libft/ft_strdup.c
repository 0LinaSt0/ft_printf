#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	int		z;

	z = 0;
	d = (char *)malloc(ft_strlen((char *)s) + 1);
	if (d == NULL)
		return (NULL);
	while (s[z] != '\0')
	{
		d[z] = s[z];
		z++;
	}
	d[z] = '\0';
	return ((char *)d);
}
