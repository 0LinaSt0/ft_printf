#include "libft.h"

static int	ft_quan_substr(char const *s, char c)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
			q++;
		while (s[i] != c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (q);
}

static char	**ft_free_array(char **gen_array, int i)
{
	if (i == 1)
	{
		free(gen_array);
		return (0);
	}
	while (*gen_array && i == 2)
		free (*gen_array++);
	free(gen_array);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char				**gen_array;
	int					cs;
	unsigned int		i;
	int					start;

	cs = 0;
	i = 0;
	gen_array = (char **)malloc((ft_quan_substr(s, c) + 1) * sizeof(char *));
	if (gen_array == NULL || !s)
		return (ft_free_array(gen_array, 1));
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i])
			i++;
		gen_array[cs++] = ft_substr(s, start, i - start);
		if (gen_array[cs - 1] == NULL)
			return (ft_free_array(gen_array, 2));
	}
	gen_array[cs] = NULL;
	return (gen_array);
}
