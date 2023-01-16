/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:08:58 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/16 13:41:35 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_list
{
	int				content;
	int				pos;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct start
{
	int	f;
	int	u;
}		t_starter;

int		is_nbr(char **str);

int		check_doubles(t_list *lst);

int		check_args(char **str);

int		check_order(t_list	*lst);

int		check_order_b(t_list	*lst);

int		check_bigger(t_list *lst, t_list *temp);

int		check_lower(t_list *lst);

int		check_half(t_list *lst);

int		check_stacks(t_list *lst, int counter);

int		count_lst(t_list *lst);

int		check_pos(t_list *lst_b, t_list *lst_a);

void	put_pos(t_list *lst);

void	extract_number(t_list **lst, char **av);

void	*ft_mallox(size_t nmemb, size_t size);

void	new_node(t_list ***lst, int nbr);

void	print_lst(t_list *lst_a, t_list *lst_b);

void	swap_top(t_list ****lst);

void	check_swap(t_list ***lst, t_list ***lst_b, int swap);

int		to_print(int keep, int swap);

void	show_mov(int keep);

void	swap_rotate(t_list ****lst);

void	swap_reverse(t_list ****lst);

void	swap_ab(t_list *****lst_a, t_list *****lst_b);

void	free_lst(t_list **lst);

void	algo(t_list **lst_a, t_list **lst_b);

void	algoii(t_list **lst_a, t_list **lst_b, int counter_a, int counter_b);

int		lessthanseven(t_list *lst_a, int counter_a, int counter);

int		morethansix(t_list *lst_a, t_list *lst_b, int counter_a,\
int counter_b, int laststep);

int		lessthanthree(t_list *lst_a);

int		b3(t_list *lst_b);

int		upto100parti(t_list *lst, int counter);

int		upto100partii(t_list *lst, int counter);

int		upto100partiii(t_list *lst_a, t_list *lst_b, int counter);

t_list	*get_last(t_list *lst_a);

#endif