/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:39:45 by ibalbako          #+#    #+#             */
/*   Updated: 2022/02/26 12:40:31 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include "string.h"
# include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	unsigned int	size;

	size = 0;
	if (s[size] == '\0')
		return (0);
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *f;
    size_t     i;
    size_t     j;

    i = 0;
    f = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if(!f)
        return(NULL);
    while(s1[i])
    {
        f[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        f[i] = s2[j];
        i++;
        j++;
    }
    f[i] = '\0';
    return (f);
}

int     main(void)
{
    const char s1[] = "hello";
    const char s2[] = "boy";

    printf("%s", ft_strjoin(s1,s2));

    return (0);
}






