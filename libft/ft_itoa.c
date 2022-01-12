/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hphanixa <hphanixa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:14:36 by hphanixa          #+#    #+#             */
/*   Updated: 2021/01/13 15:02:48 by hphanixa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	unsigned int	nb;
	unsigned int	i;

	nb = (n < 0 ? -n : n);
	len = ft_len(nb);
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * len + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		len++;
	}
	i = len - 1;
	while (nb >= 10)
	{
		str[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	str[i] = nb % 10 + 48;
	str[len] = '\0';
	return (str);
}
