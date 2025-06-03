/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:24:37 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/29 18:31:39 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_node *split_args(int *argc, char **argv)
{
    char **split_args;
    t_node *stack_a;
    int i;

    split_args = ft_split(argv[1], ' ');
    if (!split_args || !split_args[0])
    {
		write(2, "Error\n", 6);
		return (NULL);
	}
    *argc = 0;
    while (split_args[*argc])
        (*argc)++;
    stack_a = parsing(*argc, split_args, 0);
    i = 0;
    while (split_args[i])
        free(split_args[i++]);
    free(split_args);
    return (stack_a);
}
int	contains_space(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}
int	is_sorted(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return (1);

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
