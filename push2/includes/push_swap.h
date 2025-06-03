/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 08:06:42 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 17:57:56 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_op
{
	char		*name;
	struct s_op	*prev;
	struct s_op	*next;
}	t_op;

typedef struct s_op_list
{
	t_op	*head;
	t_op	*tail;
	int		size;
}	t_op_list;

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

void op_list_init(t_op_list *list);
void op_list_free(t_op_list *list);
void	op_list_add(t_op_list *list, char *op_name);
void	remove_two_nodes(t_op_list *list, t_op *a, t_op *b);
void	replace_two_with_one(t_op_list *list, t_op *a, t_op *b, t_op *new);
t_op	*new_op(char *name);
void	op_list_free(t_op_list *list);
void 	print_ops(t_op_list *list);

t_node	*parsing(int size, char **argv);
void	push_swap(t_node **a, t_node **b, int size, t_op_list *op_list);

int 	is_sorted(t_node *stack);
void	sort_big(t_node **a, t_node **b, int size, t_op_list *op_list);
void	sort_three(t_node **a, t_op_list *op_list);
void	sort_five(t_node **a, t_node **b, int size, t_op_list *op_list);
void	sort_array(int *numbers, int size);
int		*get_array(t_node **stack, int size);
void	optimize_op(t_op_list *list);

void	sa(t_node **a, t_op_list *op_list);
void	sb(t_node **b, t_op_list *op_list);
void	ss(t_node **a, t_node **b, t_op_list *op_list);
void	pb(t_node **a, t_node **b, t_op_list *op_list);
void	pa(t_node **b, t_node **a, t_op_list *op_list);
void	rra(t_node **a, t_op_list *op_list);
void	rrb(t_node **b, t_op_list *op_list);
void	rrr(t_node **a, t_node **b, t_op_list *op_list);
void	ra(t_node **a, t_op_list *op_list);
void	rb(t_node **b, t_op_list *op_list);
void	rr(t_node **a, t_node **b, t_op_list *op_list);

#endif