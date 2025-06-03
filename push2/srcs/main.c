/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 07:59:55 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/31 07:59:55 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else
		stack_a = parsing(argc, argv);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	push_swap(&stack_a, &stack_b, argc -1);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
