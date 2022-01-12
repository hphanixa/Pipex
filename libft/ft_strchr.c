/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hphanixa <hphanixa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 08:15:39 by hphanixa          #+#    #+#             */
/*   Updated: 2021/01/11 11:29:27 by hphanixa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*letter;

	letter = (char *)s;
	while (*letter)
	{
		if (*letter == c)
			return (letter);
		letter++;
	}
	if (*letter == '\0' && c == '\0')
		return (letter);
	return (NULL);
}
