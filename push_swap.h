/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:53:10 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/21 10:19:13 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/ft_printf/ft_printf.h"
# include "libft/includes/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	*index_stack;
	int	size_a;
	int	size_b;
	int	size_i;
}		t_stacks;

// error_msg.c_________________________________
void	printf_and_exit(char *message, t_stacks *stacks);
void	check_doubles(t_stacks *stacks);
void	free_array(int *array);
void	free_stacks(t_stacks *stacks);
void	printf_exit_and_str(char *message, t_stacks *stacks, char *arg_str);

// utils.c_____________________________________
int		ft_strlen_index(char *map[]);
void	free_split(char **map);
void	check_argument(char *stack_a);
long	ft_atolo(const char *str);
int		ft_sqrt(int nb);

// more_utils.c_________________________________
int		find_min(t_stacks *stacks);
int		check_sorted(t_stacks *stack);
void	init_default_stacks(t_stacks *stacks);

// Malloc_func.c_______________________________
char	**create_stack_a_split(char *stack_a);
int		*create_stack_a_int(char **stack_a_split);
char	*create_argument_str(char *argv[]);
void	prepair_stacks(char *stack_a, t_stacks *stacks);

// sorting_func.c______________________________
int		*bubble_sort_stack(int *stack_a_int, int stack_a_length);
void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_four(t_stacks *stacks);
void	sort_five(t_stacks *stacks);

// s_operations.c______________________________
void	sa_no_print(t_stacks *stacks);
void	sb_no_print(t_stacks *stacks);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

// p_operations.c_______________________________
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

// r_operations.c________________________________
void	ra_no_print(t_stacks *stacks);
void	rb_no_print(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

// rr_operations.c_________________________________
void	rra_no_print(t_stacks *stacks);
void	rrb_no_print(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

// k_sort.c______________________________________
void	k_sort(t_stacks *stacks);
void	set_index(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	push_back(t_stacks *stacks);
int		get_moves(t_stacks *stacks);

#endif