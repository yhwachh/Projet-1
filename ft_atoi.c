
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	egal;

	sign = 1;
	egal = 0;
	i = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
	{
		i++;
	}
	if (str[i] == '-')
    {
        sign *= -1;
		i++;
    }
	else if(str[i] == '+')
            i++;
    while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		egal = egal * 10 + (str[i] - '0');
		i++;
	}
	return (egal * sign);
}ß
