#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_print
{
	char	mi_fl;
	char	zero_fl;
	int		width;
	int		precis;
	int		fl_width;
	int		fl_precis;
	char	type;
}				t_print;

int		ft_printf(const char *format, ...);
int		check_required_argument(const char *format, va_list argptr);
int		handler_after_percent (const char *f, va_list argptr, int *end);
int		initialization_of_struct(char *substr, va_list argptr);
int		initialization_of_fwp(char *substr, va_list argptr, t_print *req);
int		check_of_num (char *substr, va_list argptr, t_print *req, int *i);
int		initialization_of_t(char *substr, t_print *req, int i, va_list argptr);
int		check_of_precis (char *substr, va_list argptr, t_print *req, int *i);
int		define_flag(t_print *req_stackt, va_list argptr);
int		do_sign_c(t_print *req_stackt, va_list argptr);
int		c_receive_width (t_print *req_struct, char num);
int		with_zero_or_without_fl (t_print *req_struct, char num, char *str_flag);
int		do_str_s(t_print *req_struct, va_list argptr);
int		str_have_prec(t_print *req, char *width, char *return_, char *str);
int		str_not_prec(t_print *req, char *width, char *return_, char *str);
int		type_of_ptr(t_print *req_struct, va_list argptr);
int		do_ptr (t_print *req, char *ptr, char *full_ptr);
char	*p_less_strlen0 (t_print *req, char *width, char *full_ptr, char *ptr);
char	*p_less_strlen1 (t_print *req, char *width, char *full_ptr);
char	*nums_of_hex_for_xX(int flag);
char	*ft_rev(char *hex_str, int i);
char	*convert_to_hexadecimal(uintptr_t elem, int flag);
char	*p_have_prec (t_print *req, char *width, char *full_ptr, char *ptr);
char	*p_have_precNwidth (t_print *req, char *width, char *full_p, char *p);
int		take_elem_for_diu (t_print *req_stract, va_list argptr);
void	what_if_nullprecis_N_nullelem (t_print *req, long int elem);
char	*take_elem_for_xX (t_print *req_struct, long int elem);
int		do_int_diu1(t_print *req, long int elem, char *integ, char minus);
int		diu_prec_wtht_elem (t_print *req, long int elem, char *in, char min);
char	*diu_wd_with_mi_fl (t_print *req, char *integ, char min, char *width);
int		do_int_diu2(t_print *req, long int elem, char *integ, char minus);
char	*diu_wd_wtht_fl (t_print *req, long int elem, char *integ, char minus);
char	*diu_wd_with_zero_flag (t_print *req_stract, char *integ, char minus);
int		diu_wd_without_prec (t_print *req, long int elem, char *in, char min);
char	*diu_prec_have_flags (t_print *req, char *integ, char minus, char *ret);
char	*initializ_of_precis (t_print *req, char *integ, char minus, char *ret);
char	*width_less_prec (t_print *req_stract, char *integ, char minus);
char	*join_str(char *s1, char *s2, int iter1, int iter2);
char	*convert(char *str);
int		len_str (char *str);
char	*minus_str(char minus);
char	check_minus (long int *elem);
#endif
