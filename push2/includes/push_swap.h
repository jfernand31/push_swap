/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 08:06:42 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/31 08:06:42 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				index;
	int 			value;
	struct s_node	*next;
}	t_node;

int		ft_strcmp(const char *s1, const char *s2);

void	stack_clear(t_node **lst);
int		stack_size(t_node *lst);
t_node	*new_node(int value);
void	add_to_back(t_node **lst, t_node *new);

t_node	*parsing(int size, char **argv);
void	push_swap(t_node **a, t_node **b, int size);

int 	is_sorted(t_node *stack);
void	sort_big(t_node **a, t_node **b, int size);
void	sort_three(t_node **a);
void	sort_five(t_node **a, t_node **b, int size);
void	sort_array(int *numbers, int size);
int		*get_array(t_node **stack, int size);

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	pa(t_node **b, t_node **a);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

#endif