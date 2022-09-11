#include "ft_printf.h"

int	do_str_s(t_print *req, va_list argptr)
{
	char	*str;
	char	*width;
	char	*return_;
	int		len_of_str;

	return_ = NULL;
	str = va_arg(argptr, char *);
	if (str == NULL)
		str = "(null)";
	len_of_str = ft_strlen(str);
	width = (char *)malloc(req->width + 100);
	if (!req->fl_precis && !req->fl_width)
		ft_putstr_fd(str, 1);
	else
	{
		if (req->precis >= len_of_str || (req->fl_width && !req->fl_precis))
			len_of_str = str_have_prec(req, width, return_, str);
		else if (req->precis < len_of_str)
			len_of_str = str_not_prec(req, width, return_, str);
		else if (req->width <= req->precis || req->precis < 0)
			ft_putstr_fd(str, 1);
	}
	free (width);
	return (len_of_str);
}

// SIDETRACK WITH USING PRECISION
int	str_have_prec(t_print *req_struct, char *width, char *return_, char *str)
{
	int	len_of_str;

	len_of_str = ft_strlen(str);
	if (req_struct->width <= len_of_str)
	{
		ft_putstr_fd(str, 1);
		return (len_of_str);
	}
	else if (req_struct->width > len_of_str && req_struct->mi_fl)
	{
		width = ft_memset(width, ' ', req_struct->width - len_of_str);
		return_ = ft_strjoin(str, width);
	}
	else if (req_struct->width > len_of_str && !req_struct->mi_fl)
	{
		if (req_struct->zero_fl)
			width = ft_memset(width, '0', req_struct->width - len_of_str);
		else
			width = ft_memset(width, ' ', req_struct->width - len_of_str);
		return_ = ft_strjoin(width, str);
	}
	ft_putstr_fd (return_, 1);
	return (len_str (return_));
}

// SIDETRACK WITH MISS PRECISION
int	str_not_prec(t_print *req, char *width, char *return_, char *str)
{
	str = ft_substr(str, 0, req->precis);
	if (req->precis < 0)
		req->precis = 0;
	if (req->width >= req->precis && req->width > (int)ft_strlen(str))
	{
		if (req->mi_fl)
		{
			width = ft_memset(width, ' ', req->width - (int)ft_strlen(str));
			return_ = ft_strjoin(str, width);
		}
		else
		{
			if (req->zero_fl)
				width = ft_memset(width, '0', req->width - (int)ft_strlen(str));
			else
				width = ft_memset(width, ' ', req->width - (int)ft_strlen(str));
			return_ = ft_strjoin(width, str);
		}
		free (str);
	}
	else
		return_ = str;
	ft_putstr_fd (return_, 1);
	return (len_str (return_));
}
