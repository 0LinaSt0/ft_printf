#include "ft_printf.h"

// WORK THEN PRECIS < WIDTH AND PRECIS > LEN OF INTEG
char	*diu_prec_have_flags (t_print *req, char *integ, char minus, char *ret)
{
	char	*width;

	width = (char *)malloc(req->width);
	if (minus == '-')
	{
		integ = join_str(minus_str(minus), integ, 0, 0);
		if (req->width < (int)ft_strlen(integ))
			width = ft_memset(width, ' ', req->width + 1 - (ft_strlen(integ)));
		else
			width = ft_memset(width, ' ', req->width - (ft_strlen(integ)));
	}
	if (req->mi_fl || (req->mi_fl && req->zero_fl))
	{
		if (minus != '-')
			width = ft_memset(width, ' ', (req->width) - ft_strlen(integ));
		ret = join_str(integ, width, 0, 0);
	}
	else if ((!req->mi_fl && req->zero_fl) || (!req->mi_fl && !req->zero_fl))
	{
		if (minus != '-')
			width = ft_memset(width, ' ', req->width - ft_strlen(integ));
		ret = join_str(width, integ, 0, 0);
	}
	return (ret);
}

char	*initializ_of_precis (t_print *req, char *integ, char minus, char *ret)
{
	char	*prec_zeros;
	char	*precNint;

	prec_zeros = (char *)malloc(req->precis - ft_strlen(integ) + 1);
	prec_zeros = ft_memset(prec_zeros, '0', req->precis - ft_strlen(integ));
	precNint = join_str(prec_zeros, integ, 0, 0);
	ret = diu_prec_have_flags (req, precNint, minus, ret);
	return (ret);
}

char	*width_less_prec (t_print *req, char *integ, char minus)
{
	char	*prec_zeros;
	char	*return_;

	return_ = NULL;
	if (req->precis >= (int)ft_strlen(integ))
	{
		prec_zeros = (char *)malloc(req->precis - ft_strlen(integ) + 1);
		prec_zeros = ft_memset(prec_zeros, '0', req->precis - ft_strlen(integ));
		if (minus == '-')
		{
			integ = join_str(prec_zeros, integ, 0, 0);
			integ = join_str(minus_str(minus), integ, 0, 0);
			return_ = integ;
		}
		else
			return_ = join_str(prec_zeros, integ, 0, 0);
	}
	else
	{
		if (minus == '-')
			return_ = join_str(minus_str(minus), integ, 0, 0);
		else
			return_ = integ;
	}
	return (return_);
}
