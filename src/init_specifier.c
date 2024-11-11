
#include "../inc/common.h"

static void	get_flag(char **f, t_format_specifier *pfs)
{
	while (ft_strchr(FLAGS, **f))
	{
		if (**f == ZERO)
			pfs->flag.is_zero = 1;
		else if (**f == HASH)
			pfs->flag.is_hash = 1;
		else if (**f == PLUS)
			pfs->flag.is_plus = 1;
		else if (**f == MINUS)
			pfs->flag.is_minus = 1;
		else if (**f == SPACE)
			pfs->flag.is_space = 1;
		else
			break ;
		(*f)++;
	}
	pfs->flag.is_flag = (pfs->flag.is_zero || pfs->flag.is_hash
			|| pfs->flag.is_minus || pfs->flag.is_plus);
}

/*
	# check asterisk after digits cs :
	## if * before digits : width is the the digits
	## else if * after digits : width is arg
*/
static void	get_width(char **f, t_format_specifier *pfs)
{
	int32_t		width;

	width = 0;
	while (ft_isdigit(**f))
	{
		width = (**f - 48) + (width * 10);
		(*f)++;
	}
	if (**f == ASTERISK)
	{
		pfs->width.is_asterisk = 1;
		(*f)++;
	}
	pfs->width.width = width;
}

static void	get_precision(char **f, t_format_specifier *pfs)
{
	uint32_t		prec;

	prec = 0;
	if (**f == DOT)
	{
		pfs->precision.is_precision = 1;
		(*f)++;
		while (ft_isdigit(**f))
		{
			prec = (**f - 48) + (prec * 10);
			(*f)++;
		}
		pfs->precision.precision = prec;
	}
}

static void	get_specifier(char **f, t_format_specifier *pfs)
{
	if (ft_strchr(SPECIFIERS, **f))
	{
		pfs->specifier = **f;
		(*f)++;
	}
	else
		pfs->no_specifier = 1;
	if (pfs->specifier == P_SPEC)
		pfs->flag.is_hash = 1;
}

void	init_specifier(t_format_specifier *pfs, char **spec)
{
	(*spec)++;
	get_flag(spec, pfs);
	get_width(spec, pfs);
	get_precision(spec, pfs);
	get_specifier(spec, pfs);
}
