/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:08:32 by mamazian          #+#    #+#             */
/*   Updated: 2024/11/09 21:15:54 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include "defines.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef enum boolean
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_flag
{
	t_bool				is_flag;
	t_bool				is_zero;
	t_bool				is_hash;
	t_bool				is_plus;
	t_bool				is_minus;
	t_bool				is_space;
}	t_flag;

typedef struct s_width
{
	t_bool				is_asterisk;
	int32_t				width;
}	t_width;

typedef struct s_precision
{
	t_bool				is_precision;
	int32_t				precision;
}	t_precision;

typedef struct s_return
{
	int32_t			ft_return;
	t_bool			ft_error;
}	t_return;

typedef struct _FORMAT_SPECIFIER
{
	t_flag			flag;
	t_width			width;
	t_precision		precision;
	int32_t			specifier;
	t_bool			no_specifier;
	t_bool			is_value_neg;
	t_bool			is_uper_x;
	t_return		ft_ret;
}	t_format_specifier;

// CORE
int				ft_printf(const char *format, ...);
void			print_arg(va_list args, t_format_specifier *pfs);

// SPECIFIERS HANDLE
void			init_specifier(t_format_specifier *pfs, char **pFormat);
void			di_specifier(va_list args, t_format_specifier *pfs);
void			x_specifier(va_list args, t_format_specifier *pfs);
void			u_specifier(va_list args, t_format_specifier *pfs);
void			c_specifier(va_list args, t_format_specifier *pfs,
					int32_t c_handle);
void			s_specifier(va_list args, t_format_specifier *pfs);
void			p_specifier(va_list args, t_format_specifier *pfs);
void			no_specifier(va_list args, t_format_specifier *pfs);
void			percent_specifier(va_list args, t_format_specifier *pfs);

// UTILS
void			get_xp_origin_len(void *nbr,
					int32_t *len, int32_t type);
void			xp_no_pad(t_format_specifier *pfs, void *value, int32_t type);
uint32_t		get_max(uint32_t one, uint32_t two);
void			sign_handle(t_format_specifier *pfs);
void			zero_val_x_prec(t_format_specifier *pfs);
void			di_space_flag(t_format_specifier *pfs, int32_t *pad_len,
					int32_t origin_len);
void			check_asterisk(t_format_specifier *pfs, va_list args);
void			put_u_nbr(uint32_t n, int fd);

// PADDING THINGS
int32_t			get_pad_len(t_format_specifier *pfs, int32_t origin_len);
void			out_padding(t_format_specifier *pfs,
					int32_t pad_len, int32_t origin_len);
void			pad(char pad, uint32_t pad_len);
void			cs_pad_handle(t_format_specifier *pfs, int32_t pad_len);
void			xp_minus_pad(t_format_specifier *pfs, int32_t origin_len,
					int32_t *pad_len);
void			xp_out_padded_hex(t_format_specifier *pfs, void *value,
					int32_t type);

#endif
