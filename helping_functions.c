#include "ft_printf.h"

int	len_str (char *str)
{
	int	i;

	i = (int)ft_strlen(str);
	free (str);
	return (i);
}

char	*convert(char *str)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)malloc((int)ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	while (i < (int)ft_strlen(str))
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*join_str(char *s1, char *s2, int iter1, int iter2)
{
	char	*s3;

	s3 = ft_strjoin((s1 + iter1), (s2 + iter2));
	free(s1);
	free(s2);
	return (s3);
}

char	*minus_str(char minus)
{
	char	*s;

	s = (char *) malloc(2);
	if (minus != '-')
		return (NULL);
	if (!s)
		return (NULL);
	s[0] = minus;
	s[1] = 0;
	return (s);
}

char	check_minus (long int *elem)
{
	char	minus;

	minus = 0;
	if (*elem < 0)
	{
		*elem = *elem * -1;
		minus = '-';
	}
	return (minus);
}
