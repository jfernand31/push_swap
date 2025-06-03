/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 08:11:10 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/31 08:11:10 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	safe_atol(char *str, int *out)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		if (sign * res > 2147483647 || sign * res < -2147483648)
			return (0);
		i++;
	}
	*out = (int)(res * sign);
	return (1);
}

static int	is_duplicate(int size, char **argv)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (!safe_atol(argv[i], &num1) || !safe_atol(argv[j], &num2))
				return (1);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	has_invalid(char **str, int size)
{
	int	i;
	int j;

	i = 1;
	while (i < size)
	{
		j = 0;
		if (str[i][j] == '-'|| str[i][j] == '+')
			j++;
		if (!str[i][j])
			return (1);
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_node	*parsing(int size, char **argv)
{
	int 	i;
	t_node	*stack;
	t_node	*node;
	int		value;

	stack = NULL;
	if (has_invalid(argv, size) || is_duplicate(size, argv))
		return (NULL);
	i = 1;
	while (i < size)
	{
		if(!safe_atol(argv[i], &value))
			return (stack_clear(&stack), NULL);
		node = new_node(value);
		if (!node)
			return (stack_clear(&stack), NULL);
		add_to_back(&stack, node);
		i++;
	}
	return (stack);
}
