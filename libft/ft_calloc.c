#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*s;

	s = malloc(num * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, num * size);
	return (s);
}
