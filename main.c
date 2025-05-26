/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:35:52 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/24 10:35:52 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*temp;
	t_node	*next;

	if (argc < 2)
		return (0);
	stack_a = parsing(argc, argv);
	//this next section is just for testing if it worked
	temp = stack_a;
	while (temp != NULL)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	while (stack_a)
	{
		next = stack_a->next;
		free(stack_a);
		stack_a = next;
	}
	//section ends here
	return (0);
}
