/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:59:46 by ibalbako          #+#    #+#             */
/*   Updated: 2022/02/26 11:09:32 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)b;
	while (i < len)
		d[i++] = (unsigned char)c;
	b = (void *)d;
	return (b);
}


int	main(void)
{
	char	mot[10];

	printf("%s",ft_memset(mot,'a',3));
}

