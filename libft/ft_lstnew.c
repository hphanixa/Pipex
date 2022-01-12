/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hphanixa <hphanixa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:10:49 by hphanixa          #+#    #+#             */
/*   Updated: 2021/01/18 17:21:27 by hphanixa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newel;

	if (!(newel = malloc(sizeof(t_list))))
		return (NULL);
	newel->content = content;
	newel->next = NULL;
	return (newel);
}
