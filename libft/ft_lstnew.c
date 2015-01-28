/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 10:56:27 by dlevy             #+#    #+#             */
/*   Updated: 2015/01/19 17:42:03 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char const *content, int content_size)
{
	t_list	*new;

	if (content != NULL)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		if (!(new->content = ft_strnew(content_size)))
			return (NULL);
		ft_strcpy(new->content, content);
		new->next = NULL;
		new->content_size = content_size;
		return (new);
	}
	else
		return (NULL);
}
