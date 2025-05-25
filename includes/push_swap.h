/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:37:23 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/24 21:57:41 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

t_node  *parsing(int argc, char **argv);
void    ft_lstclear(t_node **lst);
t_node  *ft_lstnew(int value);
void    ft_lstadd_back(t_node **lst, t_node *new);

#endif