/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:01:25 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/26 20:01:25 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

t_node *split_args(int *argc, char **argv)
{
    char **split_args;
    t_node *stack_a;
    int i;

    split_args = ft_split(argv[1], ' ');
    if (!split_args)
        return (NULL);
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


void	push_swap(int argc, t_node **stack_a, t_node **stack_b)
{
	int	*array;

	if (argc == 4)
		sort_three(stack_a);
	else if (argc == 5)
		sort_four(stack_a, stack_b);
	else if (argc == 6)
		sort_five(stack_a, stack_b);
	else 
	{
		array = get_array(stack_a, argc);
		sort_array(array, argc);
		assign_index(array, stack_a, argc);
		sort_big(stack_a, stack_b, argc);
		free(array);
	}
}
int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2 && contains_space(argv[1]))
		stack_a = split_args(&argc, argv);
	else if (argc >= 2 && !contains_space(argv[1]))
		stack_a = parsing(argc, argv, 1);
	if (!stack_a)
	{
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
		return (1);
	}
	push_swap(argc, &stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
