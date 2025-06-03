/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 10:37:23 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/30 16:41:01 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;


t_node	*parsing(int argc, char **argv);
void    ft_lstclear(t_node **stack);
t_node  *ft_newlst(int value);
int     lst_size(t_node **stack);
void    lst_add_to_back(t_node **lst, t_node *new);
int		is_sorted(t_node **stack);
t_node *split_args(int *argc, char **argv);
int		contains_space(char *str);
int		is_sorted(t_node **stack);
void	sa2(t_node **stack_a);
void	sb2(t_node **stack_b);
void	ss2(t_node **stack_a, t_node **stack_b);
void	pa2(t_node **stack_b, t_node **stack_a);
void	pb2(t_node **stack_a, t_node **stack_b);
void	ra2(t_node **stack_a);
void	rb2(t_node **stack_b);
void	rr2(t_node **stack_a, t_node **stack_b);
void	rra2(t_node **stack_a);
void	rrb2(t_node **stack_b);
void	rrr2(t_node **stack_a, t_node **stack_b);

#endif