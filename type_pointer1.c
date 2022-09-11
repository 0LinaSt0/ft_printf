#include "ft_printf.h"

char	*nums_of_hex_for_xX(int flag)
{
	if (flag == 1)
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

char	*ft_rev(char *hex_str, int i)
{
	char	*rev_hex_str;
	int		q;

	q = 0;
	rev_hex_str = (char *)malloc(i + 2);
	while (i >= 0)
		rev_hex_str[q++] = hex_str[i--];
	free (hex_str);
	rev_hex_str[q] = 0;
	return (rev_hex_str);
}

char	*convert_to_hexadecimal(uintptr_t elem, int flag)
{
	char		*hex_str;
	char		*temp_char;
	uintptr_t	quotient;
	int			i;

	i = 0;
	temp_char = ft_itoa(elem);
	quotient = elem;
	hex_str = (char *)malloc(ft_strlen(temp_char) + 100);
	ft_memset(hex_str, '\0', len_str(temp_char));
	while (quotient / 16 >= 16)
	{
		quotient = elem / 16;
		hex_str[i++] = nums_of_hex_for_xX(flag)[elem - (quotient * 16)];
		elem = quotient;
	}
	if (quotient / 16 < 16)
	{
		quotient = elem / 16;
		hex_str[i] = nums_of_hex_for_xX(flag)[elem - (quotient * 16)];
		if (!(elem < 16))
			hex_str[++i] = nums_of_hex_for_xX(flag)[quotient];
	}
	hex_str = ft_rev(hex_str, i);
	return (hex_str);
}

char	*p_have_prec (t_print *req, char *width, char *full_ptr, char *ptr)
{
	int		len_of_ptr;
	char	*return_;

	len_of_ptr = ft_strlen(full_ptr);
	ptr = ft_strjoin(ft_memset(width, '0', req->precis - len_of_ptr + 2), ptr);
	if (req->width > (req->precis + 2))
	{
		width = ft_memset(width, ' ', (req->width - (req->precis + 2)));
		free (full_ptr);
		full_ptr = ft_strjoin("0x", ptr);
		if (req->mi_fl)
			return_ = ft_strjoin(full_ptr, width);
		else
			return_ = ft_strjoin(width, full_ptr);
	}
	else
	{
		return_ = ft_strjoin("0x", ptr);
	}
	free (full_ptr);
	return (return_);
}

// LINE THEN P <= LEN_OF_PTR || THEN W <= LEN_OF_PTR

char	*p_have_precNwidth (t_print *req, char *width, char *full_p, char *p)
{
	int		len_of_ptr;
	char	*return_;

	len_of_ptr = ft_strlen(full_p);
	return_ = NULL;
	if (req->precis <= (len_of_ptr - 2))
	{
		if (p[0] == '0' && req->fl_precis && req->precis == 0)
		{
			free(full_p);
			full_p = convert("0x");
		}
		return_ = p_less_strlen0 (req, width, full_p, p);
	}
	else if (req->width <= len_of_ptr)
	{
		width = ft_memset(width, '0', req->precis - len_of_ptr + 2);
		width = ft_strjoin("0x", width);
		return_ = ft_strjoin(width, p);
		free (full_p);
	}
	else if (req->precis > (len_of_ptr - 2))
		return_ = p_have_prec(req, width, full_p, p);
	return (return_);
}
