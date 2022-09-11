#include "libft.h"

static int	ft_copsig_begin(char const *s, char const *cs)
{
	int	i;
	int	g;

	i = 0;
	g = 0;
	while (cs[g] && s[i])
	{
		if (s[i] != cs[g])
			g++;
		else
		{
			i++;
			g = 0;
		}
	}
	return (i);
}

static int	ft_copsig_end(char const *s, char const *cs, int begin)
{
	int	i;
	int	g;

	i = ft_strlen((char *) s) - 1;
	g = 0;
	while (i >= begin && cs[g] && s[i])
	{
		if (s[i] != cs[g])
			g++;
		else
		{
			i--;
			g = 0;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*d;
	int		i;
	int		begin;
	int		end;

	i = 0;
	if (!s1 || !set)
		return (0);
	begin = ft_copsig_begin(s1, set);
	end = ft_copsig_end(s1, set, begin);
	d = (char *)malloc(end - begin + 2);
	if (d == NULL)
		return (NULL);
	while (s1[begin] && begin <= end)
	{
		d[i] = s1[begin];
		i++;
		begin++;
	}
	d[i] = '\0';
	return (d);
}
