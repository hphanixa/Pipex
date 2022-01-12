/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hphanixa <hphanixa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:19:01 by hphanixa          #+#    #+#             */
/*   Updated: 2021/01/07 12:20:18 by hphanixa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		is_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

int		count_words(char const *str, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (!(is_charset(str[i], c)) &&
		(((is_charset(str[i + 1], c) == 1)) || !(str[i + 1])))
			word++;
		i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(tab_str = malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (0);
	while (k < count_words(s, c))
	{
		while (s[i] && (is_charset(s[i], c) == 1))
			i++;
		j = i;
		while (s[j] && (is_charset(s[j], c) == 0))
			j++;
		if (!(tab_str[k] = malloc(sizeof(char) * (j + 1))))
			return (0);
		j = 0;
		while (s[i] && (is_charset(s[i], c) == 0))
			tab_str[k][j++] = s[i++];
		tab_str[k++][j] = '\0';
	}
	tab_str[k] = 0;
	return (tab_str);
}
