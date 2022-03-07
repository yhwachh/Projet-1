/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:19:09 by ibalbako          #+#    #+#             */
/*   Updated: 2022/03/07 14:40:55 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (s1[++i] && i < len)
	{
		j = 0;
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j] && i + j < len)
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
	}
	return (NULL);
}
