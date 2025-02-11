/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:15:59 by gzovkic           #+#    #+#             */
/*   Updated: 2024/11/20 16:06:28 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void		free_node(t_list *node, void (*del)(void *));
static t_list	*create_node(t_list *new_list, void *(*f)(void *),
					void (*del)(void *), t_list *lst);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
	t_list	*last_node;

	last_node = NULL;
	new_list = NULL;
	while (lst != NULL)
	{
		new_node = create_node(new_list, f, del, lst);
		if (!new_node)
			return (NULL);
		if (last_node)
			last_node->next = new_node;
		else
			new_list = new_node;
		last_node = new_node;
		lst = lst->next;
	}
	return (new_list);
}

static void	free_node(t_list *node, void (*del)(void *))
{
	t_list	*store;

	while (node != NULL)
	{
		store = node->next;
		del(node->content);
		free(node);
		node = store;
	}
}

static t_list	*create_node(t_list *new_list, void *(*f)(void *),
		void (*del)(void *), t_list *lst)
{
	t_list	*new_node;

	new_node = ft_lstnew(NULL);
	if (!new_node)
	{
		free_node(new_list, del);
		return (NULL);
	}
	new_node->content = f(lst->content);
	if (!new_node->content)
	{
		free(new_node);
		free_node(new_list, del);
		return (NULL);
	}
	return (new_node);
}
