/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:37:33 by ibalbako          #+#    #+#             */
/*   Updated: 2022/02/23 11:57:13 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	strlen(const char *s)
{
	unsigned int	size;

	size = 0;
	if (s != '\0')
		return (0);
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}
