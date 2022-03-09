/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:41:59 by ibalbako          #+#    #+#             */
/*   Updated: 2022/03/07 12:56:15 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
/*static int	count_w(char const *s, char c)
{
	int	i;
	int	nb;
	int	words;

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

static int	count_l(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] == c))
		i++;
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		count;
	int		word_len;
	int		nb_of_words;

	count = -1;
	if ((nb_of_words = count_w(s, c)) == -1)
		return (NULL);
	tab = (char **)malloc(sizeof(*tab) * count_w(s, c) + 1);
	if (!tab)
		return (NULL);
	while (++count < nb_of_words)
	{
		while ((*s == c) && *s)
			s++;
		word_len = count_l(s, c);
		tab[count] = (char *)malloc(word_len + 1);
		if (!tab)
			return (NULL);
		tab[count][word_len] = '\0';
		i = 0;
		while (i < word_len)
			tab[count][i++] = *s++;
	}
	tab[count] = 0;
	return (tab);
}
*/

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

#include <stdio.h>

static size_t	ft_facul(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (ft_facul(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}
int main() {

	char s[] = "hell$g$$$gg&&222$jj";
	char c = '$';
	char **tab = ft_split(s,c);

	for(int i = 0; i < 3 ; i++ )
	{
		printf("%s", tab[i]);

	}
	
}