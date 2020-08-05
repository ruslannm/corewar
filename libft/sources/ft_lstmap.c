/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:52:25 by lnickole          #+#    #+#             */
/*   Updated: 2019/05/10 17:29:14 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *head;
	t_list *element;

	if (lst == NULL || f == NULL)
		return (NULL);
	element = f(lst);
	result = ft_lstnew(element->content, element->content_size);
	if (result == NULL)
		return (NULL);
	head = result;
	lst = lst->next;
	while (lst != NULL)
	{
		element = f(lst);
		result->next = ft_lstnew(element->content, element->content_size);
		if (result == NULL)
			return (NULL);
		result = result->next;
		lst = lst->next;
	}
	return (head);
}
