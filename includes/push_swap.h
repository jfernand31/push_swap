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
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

char	**ft_split(char const *s, char c);
t_node	*parsing(int argc, char **argv, int start);
void	ft_lstclear(t_node **lst);
t_node	*ft_lstnew(int value);
int		ft_lstsize(t_node **stack);
int		is_sorted(t_node **stack);
int		get_smallest(t_node **stack);
int		get_case(int first, int second , int third);
void	bring_to_top(t_node **stack, int index);
int		find_max_position(t_node **stack);
void	sort_four(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack);
void	sort_five(t_node **stack_a, t_node **stack_b);
void	sort_big(t_node **stack_a, t_node **stack_b, int argc);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	assign_index(int *numbers, t_node **stack, int argc);
void	sort_array(int *numbers, int argc);
int		*get_array(t_node **stack, int argc);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_b, t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif