#include "ft_printf.h"

int	do_sign_c(t_print *req_struct, va_list argptr)
{
	char	num;

	if (req_struct->type == '%')
		num = '%';
	else
		num = (char)va_arg (argptr, int);
	if (req_struct->fl_width == 1 && req_struct->width > 0)
		return (c_receive_width (req_struct, num));
	else
	{
		write (1, &num, 1);
		return (1);
	}
	return (0);
}

int	c_receive_width (t_print *req_struct, char num)
{
	char	*str_flag;
	int		len;

	len = 0;
	str_flag = (char *)malloc(req_struct->width + 1);
	if (req_struct->mi_fl || (req_struct->mi_fl && req_struct->zero_fl))
	{
		str_flag[len++] = num;
		write (1, &num, 1);
		ft_memset((str_flag + 1), ' ', (req_struct->width - 1));
		while (req_struct->width > len)
			write (1, &str_flag[len++], 1);
		len--;
	}
	else
		len = with_zero_or_without_fl (req_struct, num, str_flag);
	free (str_flag);
	return (len + 1);
}

int	with_zero_or_without_fl (t_print *req_struct, char num, char *str_flag)
{
	int	len;

	len = 0;
	if (!req_struct->mi_fl && req_struct->zero_fl)
		ft_memset(str_flag, '0', (req_struct->width - 1));
	else if (!req_struct->mi_fl && !req_struct->zero_fl)
		ft_memset(str_flag, ' ', (req_struct->width - 1));
	while (req_struct->width - 1 > len)
		write (1, &str_flag[len++], 1);
	str_flag[len] = num;
	write (1, &num, 1);
	return (len);
}
