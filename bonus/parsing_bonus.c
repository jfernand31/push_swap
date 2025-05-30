/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:39:58 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/27 17:47:56 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	ft_scan(t_node *stack)
{
	t_node	*outer;
	t_node	*inner;

	outer = stack;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			if (outer->value == inner->value)
				return (0);
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (1);
}

int	ft_safe_atoi(char *str, int *result)
{
	int		i;
	int		is_neg;
	long	number;

	is_neg = 1;
	i = 0;
	number = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			is_neg = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number > (INT_MAX - (str[i] - '0')) / 10)
			return (0);
		number = number * 10 + (str[i++] - '0');
	}
	if ((number * is_neg) < INT_MIN || (number * is_neg) > INT_MAX)
		return (0);
	*result = (int)(number * is_neg);
	return (1);
}

t_node	*parsing(int argc, char **argv)
{
	int		i;
	int		value;
	t_node	*stack;
	t_node	*new;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]) || !ft_safe_atoi(argv[i], &value))
			return (ft_lstclear(&stack), NULL);
		new = ft_newlst(value);
		if (!new)
			return (ft_lstclear(&stack), NULL);
		lst_add_to_back(&stack, new);
		i++;
	}
	if (!ft_scan(stack))
	{
		write(2, "Error\n", 6);
		ft_lstclear(&stack);
		return (NULL);
	}
	return (stack);
}
