/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:07:40 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/27 17:50:34 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ft_lstclear(t_node **lst)
{
	t_node	*temp;
	t_node	*next;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		next = temp->next;
		temp->value = 0;
		free(temp);
		temp = next;
	}
	*lst = NULL;
}

void	lst_add_to_back(t_node **lst, t_node *new)
{
	t_node	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

t_node	*ft_newlst(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1; // Initialize index to 0
	node->next = NULL;
	return (node);
}

int	lst_size(t_node **stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *stack;
	while (temp != NULL)
	{
		i++;
		temp = temp ->next;
	}
	return (i);
}
