/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:10:53 by ibalbako          #+#    #+#             */
/*   Updated: 2022/02/26 11:32:45 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*d;
    int             i;

    i = 0;
	d = (unsigned char *)s;
	while (n > 0)
	{
		d[i] = '\0';
        i++;
		n--;
	}
}
