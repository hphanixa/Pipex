/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hphanixa <hphanixa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:41:21 by hphanixa          #+#    #+#             */
/*   Updated: 2021/01/13 10:39:32 by hphanixa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int i;
	unsigned int destlg;
	unsigned int srclg;

	i = 0;
	destlg = 0;
	srclg = 0;
	while (dest[destlg] != '\0')
		destlg++;
	while (src[srclg] != '\0')
		srclg++;
	if (size == 0)
		return (srclg);
	while (src[i] != '\0' && (destlg + i < size - 1))
	{
		dest[destlg + i] = src[i];
		i++;
	}
	if (i < size)
		dest[destlg + i] = '\0';
	if (destlg > size)
		return (srclg + size);
	return (destlg + srclg);
}
