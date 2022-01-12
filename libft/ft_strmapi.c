/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hphanixa <hphanixa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:18:40 by hphanixa          #+#    #+#             */
/*   Updated: 2021/01/13 11:18:15 by hphanixa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	i = 0;
	if (!(result = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	if (!s || !f)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, (char)s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
