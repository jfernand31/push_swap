/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:39:58 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/24 10:39:58 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int *parsing(int argc, char **argv)
{
    int i;
    int *stack;

    stack = (int *)malloc(sizeof(int) * (argc - 1));
    if (!stack)
        return (NULL);
    i = 1;
    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
        {
            free(stack);
            return (NULL);
        }
        if (!ft_atoi(argv[i], &stack[i -1 ])
        {
            free(stack);
            return (NULL);
        }
        i++;
    }
    if (!ft_scan(argc, stack))
        return (NULL);
    return (stack);
}

int is_valid_number(char *str)
{
    int i;

    i = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!(str[i] >= '0' && str[i] <= '9'))
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int ft_scan(int argc, int *stack)
{
    int i;
    int j;

    i = 0;
    while (i < (argc - 2))
    {
        j = i + 1;
        while (j < argc - 1)
        {
            if (stack[i] == stack[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int ft_safe_atoi(char *str, int *result)
{
    int i;
    int is_neg;
    int number;

    is_neg = 1;
    i = 0;
    number = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            is_neg *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        if (number > (INT_MAX - (str[i] - '0')) / 10)
            return (0);
        number = number * 10 + (str[i++] - '0');
    }
    if ((is_neg == 1 && number > INT_MAX) || (is_neg == -1 && number > 2147483648))
        return 0;
    *result = number * is_neg;
    return (1);
}
