/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:41:59 by ibalbako          #+#    #+#             */
/*   Updated: 2022/02/26 12:42:46 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_w(char const *s, char c)
{
	int i;
	int nb;
	int words;

	i = 0;
	nb = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		words = 0;
		while ((s[i] == c) && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			words = 1;
		}
		if (words == 1)
			nb++;
	}
	return (nb);
}

static int		count_l(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && !(s[i] == c))
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		count;
	int		word_len;
	int		nb_of_words;

	count = -1;
	if ((nb_of_words = count_w(s, c)) == -1)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(*tab) * count_w(s, c) + 1)))
		return (NULL);
	while (++count < nb_of_words)
	{
		while ((*s == c) && *s)
			s++;
		word_len = count_l(s, c);
		if (!(tab[count] = (char *)malloc(word_len + 1)))
			return (NULL);
		tab[count][word_len] = '\0';
		i = 0;
		while (i < word_len)
			tab[count][i++] = *s++;
	}
	tab[count] = 0;
	return (tab);
}
