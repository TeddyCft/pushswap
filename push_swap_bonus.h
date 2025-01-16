/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoeffet <tcoeffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:22:25 by tcoeffet          #+#    #+#             */
/*   Updated: 2025/01/16 14:20:50 by tcoeffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

int	checker(t_stack **st_a, t_stack **st_b, int *error);
int	do_push(char *op, t_stack **st_a, t_stack **st_b);
int	do_swap(char *op, t_stack **st_a, t_stack **st_b);
int	do_rot(char *op, t_stack **st_a, t_stack **st_b);
int	do_rev_rot(char *op, t_stack **st_a, t_stack **st_b);
int	do_op(char *op, t_stack **st_a, t_stack **st_b);

#endif