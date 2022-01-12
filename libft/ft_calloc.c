/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hphanixa <hphanixa@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:04:33 by hphanixa          #+#    #+#             */
/*   Updated: 2022/01/12 20:11:22 by hphanixa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;

	result = malloc(size * count);
	if (!result)
		return (NULL);
	ft_memset(result, 0, count * size);
	return (result);
}
