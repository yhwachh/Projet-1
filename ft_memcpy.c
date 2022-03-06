/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:33:26 by ibalbako          #+#    #+#             */
/*   Updated: 2022/02/26 11:37:45 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;
	int				j;

	i = 0;
	j = 0;
	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	while (n > 0)
	{
		b[j] = a[i];
		n--;
		i++;
		j++;
	}
	return (dst);
}
