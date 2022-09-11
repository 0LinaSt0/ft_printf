#include "ft_printf.h"

int	take_elem_for_diu (t_print *req, va_list argptr)
{
	char		minus;
	long int	elem;
	char		*integ;

	minus = 0;
	elem = 0;
	if (req->type == 'd' || req->type == 'i' || req->type == 'u')
	{
		if (req->type == 'd' || req->type == 'i')
			elem = (long int)va_arg(argptr, int);
		else if (req->type == 'u')
			elem = va_arg(argptr, unsigned int);
		minus = check_minus(&elem);
		integ = ft_itoa(elem);
	}
	else
	{
		elem = va_arg(argptr, unsigned int);
		integ = take_elem_for_xX(req, elem);
	}
	what_if_nullprecis_N_nullelem (req, elem);
	if ((!req->fl_precis) || (req->width == 0 && req->fl_width == 1))
		return (do_int_diu1(req, elem, integ, minus));
	return (do_int_diu2(req, elem, integ, minus));
}

void	what_if_nullprecis_N_nullelem (t_print *req, long int elem)
{
	if (req->fl_precis && req->precis == 0 && !elem)
	{
		req->mi_fl = '\0';
		req->zero_fl = '\0';
	}
}

char	*take_elem_for_xX (t_print *req_struct, long int elem)
{
	char	*integ;

	if (req_struct->type == 'x')
		integ = convert_to_hexadecimal((uintptr_t)elem, 0);
	else
		integ = convert_to_hexadecimal((uintptr_t)elem, 1);
	return (integ);
}

//	WORK THEN PRINTF DOESN'T RECEIVE THE PRECIS AT ALL
int	do_int_diu1(t_print *req, long int elem, char *integ, char minus)
{
	char	*ret;
	char	*temp;

	if (req->fl_width && req->width != 0 && req->width >= (int)ft_strlen(integ))
		return (diu_wd_without_prec (req, elem, integ, minus));
	else if (req->fl_precis && !elem && req->precis <= (int)ft_strlen(integ))
		return (diu_prec_wtht_elem (req, elem, integ, minus));
	else if (req->fl_precis && req->precis > (int)ft_strlen(integ))
	{
		temp = (char *)malloc (req->precis);
		ret = join_str(ft_memset(temp, '0', req->precis
					- (int)ft_strlen(integ)), integ, 0, 0);
		if (minus == '-')
			ret = join_str(minus_str(minus), ret, 0, 0);
	}
	else
	{
		if (minus == '-')
			ret = join_str(minus_str(minus), integ, 0, 0);
		else
			ret = integ;
	}
	ft_putstr_fd(ret, 1);
	return (len_str(ret));
}

//	WORK THEN PRINTF RECEIVES THE PRECIS
int	do_int_diu2(t_print *req_stract, long int elem, char *integ, char minus)
{
	char	*return_;

	return_ = NULL;
	if ((req_stract->fl_width == 1 && req_stract->precis > (int)ft_strlen(integ)
			&& req_stract->width >= req_stract->precis))
	{
		return_ = initializ_of_precis(req_stract, integ, minus, return_);
	}
	else if (req_stract->width < req_stract->precis)
		return_ = width_less_prec (req_stract, integ, minus);
	else
		return (do_int_diu1 (req_stract, elem, integ, minus));
	ft_putstr_fd(return_, 1);
	return (len_str(return_));
}
