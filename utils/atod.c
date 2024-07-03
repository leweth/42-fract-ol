#include "utils.h"

static	int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static	size_t	convert_digits(unsigned long long *conv, const char *str, size_t *i)
{
	size_t	j;

	j = 0;
	*conv = 0;
	while (ft_isdigit(str[*i]))
	{
		conv2 = conv2 * 10 + str[(*i)++] - '0';
		j++;
	}
	return (j);
}

double	atod(const char *str, int *err) // the err param to indicate an error while parsing in the calling function
{
	unsigned long long	conv; // we will add the first part that is gonna be a ull possibly with the second part that is gonna be adouble
	size_t				i;
	int					sign;
	unsigned long long	conv2;
	size_t				j;

	sign = 1;
	i = 0;
	conv = 0;
	conv2 = 0;
	while (ft_isspace(str[i]))
		i++; // hanya li morah ykoun soit + wla - wla digit else fayar
	if (!ft_isdigit(str[i]) && !(str[i] == '+' || str[i] == '-'))
		*err = FAILURE;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++; // hanya li morah ykoun digit wla fayar
	} // you can destroy the input in case of a case check specified ofr chars by a comma for example and if you are gonna rely 
	//on conv stil being a 	0 then you might miss the actual case for 0
	if (!ft_isdigit(str[i]))
		*err = FAILURE;
	convert_digits(&conv, str, &i); // li morah 5aso ykoun no9ta wla fayar --> la machi darori, t9dar tkoun input chi int sf
	if (str[i] == '.')
		i++;
	j = convert_digits(&conv2, str, &i); // li kan morah hanya
	return (minus * ((double) conv + ((double) conv2) * pow(10, -j)));
}
