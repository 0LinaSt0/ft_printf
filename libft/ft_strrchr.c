#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) s + i);
		i--;
	}
	if ((char)c == 0)
		return ((char *)s + ft_strlen((char *)s));
	return (NULL);
}
