#include "ft_printf.h"

int	type_of_ptr(t_print *req_struct, va_list argptr)
{
	char	*ptr;
	char	*full_ptr;

	ptr = convert_to_hexadecimal((uintptr_t)va_arg(argptr, char *), 0);
	full_ptr = ft_strjoin("0x", ptr);
	return (do_ptr(req_struct, ptr, full_ptr));
}

int	do_ptr (t_print *req, char *ptr, char *full_ptr)
{
	char	*width;
	int		len_of_ptr;

	len_of_ptr = ft_strlen(full_ptr);
	width = (char *)malloc(req->width + 100);
	if (!width)
		return (-1);
	if (!(ptr[0] == '0' && req->fl_precis) && ((!req->fl_precis
				&& !req->fl_width) || (req->precis <= (len_of_ptr - 2)
				&& req->width <= len_of_ptr)))
	{
		ft_putstr_fd(full_ptr, 1);
	}
	else
	{
		full_ptr = p_have_precNwidth (req, width, full_ptr, ptr);
		ft_putstr_fd(full_ptr, 1);
	}
	free (ptr);
	free (width);
	return (len_str(full_ptr));
}

char	*p_less_strlen0 (t_print *req, char *width, char *full_ptr, char *ptr)
{
	int		len_of_ptr;
	char	*return_;

	len_of_ptr = ft_strlen(full_ptr);
	if (req->mi_fl)
	{
		width = ft_memset(width, ' ', req->width - len_of_ptr);
		return_ = ft_strjoin(full_ptr, width);
		free (full_ptr);
	}
	else
	{
		if (req->zero_fl && !req->fl_precis)
		{
			width = ft_memset(width, '0', req->width - len_of_ptr);
			width = join_str(convert("0x"), width, 0, 0);
			return_ = ft_strjoin(width, ptr);
			free (full_ptr);
		}
		else
			return_ = p_less_strlen1 (req, width, full_ptr);
	}
	return (return_);
}

// WORK THEN P <= LEN_OF_PTR
char	*p_less_strlen1 (t_print *req, char *width, char *full_ptr)
{
	int		len_of_ptr;
	char	*return_;

	len_of_ptr = ft_strlen(full_ptr);
	if (full_ptr[0] == '0' && req->fl_precis && !req->fl_width)
	{
		return_ = full_ptr;
	}
	else
	{
		width = ft_memset(width, ' ', req->width - len_of_ptr);
		return_ = ft_strjoin(width, full_ptr);
		free (full_ptr);
	}
	return (return_);
}
