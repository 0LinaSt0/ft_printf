#include "ft_printf.h"

// WORK THEN WIDTH DOESN'T HAVE FLAGS AT ALL
char	*diu_wd_wtht_fl (t_print *req, long int elem, char *integ, char minus)
{
	char	*width;
	char	*return_;

	width = (char *)malloc(req->width + 1);
	if (!width)
		return (NULL);
	if (minus == '-')
	{
		integ = join_str(minus_str(minus), integ, 0, 0);
		if (req->width < (int)ft_strlen(integ))
			width = ft_memset(width, ' ', req->width + 1 - ((int)ft_strlen(integ)));
		else
			width = ft_memset(width, ' ', req->width - ((int)ft_strlen(integ)));
	}
	else if (req->fl_precis && !req->precis && !elem)
	{
		integ = ft_memset(integ, '\0', (int)ft_strlen(integ));
		integ[0] = ' ';
		width = ft_memset(width, ' ', req->width - (int)ft_strlen(integ));
	}
	else
		width = ft_memset(width, ' ', req->width - (int)ft_strlen(integ));
	return_ = join_str (width, integ, 0, 0);
	return (return_);
}

// WORK THEN WIDTH HAS JUST FLAG ZERO
char	*diu_wd_with_zero_flag (t_print *req_struct, char *integ, char minus)
{
	char	*width;
	char	*return_;

	width = (char *)malloc(req_struct->width);
	if (!width)
		return (NULL);
	if (req_struct->fl_precis == 1 && req_struct->precis >= 0)
	{
		width = ft_memset(width, ' ', req_struct->width - (int)ft_strlen(integ));
		if (minus == '-')
			width = join_str(width, minus_str(minus), 1, 0);
	}
	else
	{
		width = ft_memset(width, '0', req_struct->width - (int)ft_strlen(integ));
		if (minus == '-')
			width = join_str(minus_str(minus), width, 0, 1);
	}
	return_ = join_str(width, integ, 0, 0);
	return (return_);
}

//	WORK THEN PRINTF RECEIVES WIDTH WHICH > LEN OF INTEG AND INTEG'RE NOT THE 0
//	then width has just minus flag or minus flag + zero flag
int	diu_wd_without_prec (t_print *req, long int elem, char *integ, char minus)
{
	char	*width;
	char	*return_;

	return_ = NULL;
	width = (char *)malloc(req->width);
	if (!width)
		return (-1);
	if (req->mi_fl || (req->mi_fl && req->zero_fl))
		return_ = diu_wd_with_mi_fl (req, integ, minus, width);
	else if (!req->mi_fl && req->zero_fl)
		return_ = diu_wd_with_zero_flag (req, integ, minus);
	else if (!req->mi_fl && !req->zero_fl)
		return_ = diu_wd_wtht_fl (req, elem, integ, minus);
	free (width);
	ft_putstr_fd(return_, 1);
	return (len_str(return_));
}

char	*diu_wd_with_mi_fl (t_print *req, char *integ, char minus, char *width)
{
	char	*return_;

	return_ = NULL;
	if (minus == '-')
	{
		integ = join_str(minus_str(minus), integ, 0, 0);
		if (req->width < (int)ft_strlen(integ))
			width = ft_memset(width, ' ', req->width + 1
					- ((int)ft_strlen(integ)));
		else
			width = ft_memset(width, ' ', req->width - ((int)ft_strlen(integ)));
	}
	else
		width = ft_memset(width, ' ', req->width - (int)ft_strlen(integ));
	return_ = ft_strjoin(integ, width);
	free (integ);
	return (return_);
}

int	diu_prec_wtht_elem (t_print *req, long int elem, char *integ, char min)
{
	if (min == '-')
		return ((int)ft_strlen(join_str(minus_str(min), integ, 0, 0)));
	else if (req->fl_precis && !req->precis && !elem)
	{
		ft_putstr_fd("", 1);
		free (integ);
		return (0);
	}
	else if (req->fl_precis && !elem)
	{
		ft_putstr_fd("0", 1);
		free (integ);
		return (1);
	}
	return (elem);
}
