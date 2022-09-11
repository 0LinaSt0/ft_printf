#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*d;

	i = 0;
	if (!s || !f)
		return (0);
	d = (char *)malloc(ft_strlen((char *)s) + 1);
	if (d == NULL)
		return (0);
	while (s[i])
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[i] = 0;
	return (d);
}
