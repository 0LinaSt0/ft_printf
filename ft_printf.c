#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		length;

	length = 0;
	if (!format)
		return (-1);
	va_start (argptr, format);
	length = check_required_argument(format, argptr);
	va_end (argptr);
	return (length);
}

int	check_required_argument(const char *f, va_list argptr)
{
	int		length;
	int		end;

	length = 0;
	end = 0;
	while (f[end])
	{
		while (f[end] != '%' && f[end])
		{
			ft_putchar_fd(f[end++], 1);
			length++;
		}
		if (f[end] == '%')
		{
			end++;
			if (f[end] == ' ')
			{
				ft_putchar_fd(f[end], 1);
				length++;
			}
			length = length + handler_after_percent (f, argptr, &end);
			end++;
		}
	}
	return (length);
}

int	handler_after_percent (const char *f, va_list argptr, int *end)
{
	int		start;
	char	*substr;
	int		l;

	l = 0;
	start = *end;
	while (f[*end] != '%' && f[*end] != 'c' && f[*end] != 's' && f[*end] != 'p'
		&& f[*end] != 'd' && f[*end] != 'i' && f[*end] != 'u'
		&& f[*end] != 'x' && f[*end] != 'X' && f[*end])
		(*end)++;
	substr = ft_substr(f, start, (*end - start + 1));
	l = l + initialization_of_struct (substr, argptr);
	free (substr);
	return (l);
}

int	initialization_of_struct(char *substr, va_list argptr)
{
	t_print	required;

	required.mi_fl = 0;
	required.zero_fl = 0;
	required.width = 0;
	required.precis = 0;
	required.fl_width = 0;
	required.fl_precis = 0;
	required.type = 0;
	return (initialization_of_fwp(substr, argptr, &required));
}

int	initialization_of_fwp(char *substr, va_list argptr, t_print *req)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (substr[i])
	{
		if (substr[i] == '-')
			req->mi_fl = '-';
		else if (substr[i] == '0' && req->zero_fl != '0')
			req->zero_fl = '0';
		else if ((substr[i] >= '0' && substr[i] <= '9') || substr[i] == '*')
		{
			if (flag != check_of_num (substr, argptr, req, &i))
				continue ;
		}
		else if (substr[i] == '.')
		{
			if (flag != check_of_precis (substr, argptr, req, &i))
				continue ;
		}
		i++;
	}
	return (initialization_of_t(substr, req, --i, argptr));
}
