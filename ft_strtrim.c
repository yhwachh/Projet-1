/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:41:02 by ibalbako          #+#    #+#             */
/*   Updated: 2022/03/02 11:29:29 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

char *ft_strtrim(char const *s1, char const *set)
{
    char *f;
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    while(set[j])
    {
        if(s1[0] == set[j])
        {
            i++;
        }
        j++;
    }
    j--;
    len = ft_strlen(s1) - 1;
    while(set[j])
    {
        if(s1[len] == set[j])
        {
            len--;
        }
        j--;
    }
    while(s1[i] != s1[len])
    {
        i++;
    }
    f = malloc(sizeof(char) * (ft_strlen(s1) + 1));
    if(!f)
        return (NULL);
    return(f); 
}

int main()
{
    const char s1[] = "hello";
    const char set[] = "helloo";

    printf("%s", ft_strtrim(s1,set));
}
