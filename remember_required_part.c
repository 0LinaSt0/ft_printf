#include "ft_printf.h"

int	counter_of_number(char *substr)
{
	int	i;

	i = 0;
	while (*substr >= '0' && *substr <= '9')
	{
		i++;
		substr++;
	}
	return (i);
}

int	initialization_of_t(char *substr, t_print *required, int i, va_list argptr)
{
	while (substr[i])
	{
		if (substr[i] == 'c' || substr[i] == '%' || substr[i] == 's'
			|| substr[i] == 'p' || substr[i] == 'd' || substr[i] == 'i'
			|| substr[i] == 'u' || substr[i] == 'x' || substr[i] == 'X')
			required->type = substr[i];
		i++;
	}
	return (define_flag(required, argptr));
}

int	check_of_num (char *substr, va_list argptr, t_print *req, int *i)
{
	int	flag;

	flag = 0;
	req->fl_width = 1;
	if (substr[*i] >= '0' && substr[*i] <= '9')
	{
		req->width = ft_atoi(substr + *i);
		*i += counter_of_number(substr + *i);
		flag = 1;
	}
	else
	{
		req->width = va_arg(argptr, int);
		if (req->width < 0)
		{
			req->mi_fl = '-';
			req->width *= -1;
		}
	}
	return (flag);
}

int	check_of_precis (char *substr, va_list argptr, t_print *req, int *i)
{
	int	flag;

	flag = 0;
	req->fl_precis = 1;
	if ((substr[++(*i)] >= '0' && substr[*i] <= '9') || substr[*i] == '-')
	{
		req->precis = ft_atoi(substr + *i);
		*i += counter_of_number(substr + *i);
		flag = 1;
	}
	else if (substr[*i] == '*')
		req->precis = va_arg(argptr, int);
	return (flag);
}

int	define_flag(t_print *req_struct, va_list argptr)
{
	if (req_struct->type == 'c' || req_struct->type == '%')
		return (do_sign_c(req_struct, argptr));
	else if (req_struct->type == 's')
		return (do_str_s(req_struct, argptr));
	else if (req_struct->type == 'p')
		return (type_of_ptr(req_struct, argptr));
	else if (req_struct->type == 'd' || req_struct->type == 'i'
		|| req_struct->type == 'u' || req_struct->type == 'x'
		||req_struct->type == 'X')
		return (take_elem_for_diu(req_struct, argptr));
	return (0);
}
