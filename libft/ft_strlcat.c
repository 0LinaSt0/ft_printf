#include "libft.h"

size_t 	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	z;
	size_t	i;
	size_t	ld;
	size_t	ls;

	ld = ft_strlen(dst);
	ls = ft_strlen((char *)src);
	z = ld;
	i = 0;
	if (ld < size - 1 && size > 0)
	{
		while (src[i] && ld + i < size - 1)
		{
			dst[z] = src[i];
			i++;
			z++;
		}
		dst[z] = '\0';
	}
	if (ld >= size)
		ld = size;
	return (ld + ls);
}
