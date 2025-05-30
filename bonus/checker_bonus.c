/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:58:40 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/30 16:41:05 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	check_operation(char *op)
{
	if (!ft_strncmp(op, "pa\n", 3))
		return (0);
	else if (!ft_strncmp(op, "pb\n", 3))
		return (1);
	else if (!ft_strncmp(op, "sa\n", 3))
		return (2);
	else if (!ft_strncmp(op, "sb\n", 3))
		return (3);
	else if (!ft_strncmp(op, "ss\n", 3))
		return (4);
	else if (!ft_strncmp(op, "ra\n", 3))
		return (5);
	else if (!ft_strncmp(op, "rb\n", 3))
		return (6);
	else if (!ft_strncmp(op, "rr\n", 3))
		return (7);
	else if (!ft_strncmp(op, "rra\n", 4))
		return (8);
	else if (!ft_strncmp(op, "rrb\n", 4))
		return (9);
	else if (!ft_strncmp(op, "rrr\n", 4))
		return (10);
	return (-1);
}

static void	sort_case(int op_case, t_node **a, t_node **b)
{
	if (op_case == 0)
		pa2(a,b);
	if (op_case == 1)
		pb2(b,a);
	if (op_case == 2)
		sa2(a);
	if (op_case == 3)
		sb2(b);
	if (op_case == 4)
		ss2(a,b);
	if (op_case == 5)
		ra2(a);
	if (op_case == 6)
		rb2(b);
	if (op_case == 7)
		rr2(a,b);
	if (op_case == 8)
		rra2(a);
	if (op_case == 9)
		rrb2(b);
	if (op_case == 10)
		rrr2(a,b);
}

void	checker(t_node **stack_a, t_node **stack_b)
{
	char	*operation;
	int		op_case;

	op_case = 0;
	operation = " ";
	while ((operation = get_next_line(0))!= NULL)
	{
		if (!operation)
			break ;
		op_case = check_operation(operation);
		if (op_case < 0)
		{
			free(operation);
			break ;
		}
		sort_case(op_case, stack_a, stack_b);
		free(operation);
	}
	if (is_sorted(stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	else
		stack_a = parsing(argc, argv);
	if(!stack_a)
		return(1);
	ft_printf("size is %d\n", argc - 1);
	checker(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
