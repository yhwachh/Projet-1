/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:36:36 by ibalbako          #+#    #+#             */
/*   Updated: 2022/02/26 12:38:39 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mot;
	int		i;

    i = 0;
	if (!s)
		return (NULL);
	mot = malloc((len + 1) * sizeof(char));
	if (!mot)
		return (NULL);
	mot[len] = '\0';
	while (len--)
	{
		mot[i] = s[start];
		i++;
		start++;
	}
	return (mot);
}