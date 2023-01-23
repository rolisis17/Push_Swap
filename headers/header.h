/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:08:58 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/23 21:03:37 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <math.h>

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

int		check_intmax(long nbr);

int		error_printer(void);

int		check_doubles(t_list *lst);

int		check_args(char **str);

int		check_order(t_list	*lst);

int		check_order_b(t_list	*lst);

int		check_bigger(t_list *lst, t_list *temp);

int		check_half(t_list *lst);

int		check_stacks(t_list *lst, int counter);

int		check_lowest(t_list *lst_b, t_list *lst_a);

int		count_lst(t_list *lst);

int		check_pos(t_list *lst_b, t_list *lst_a);

int		findlowestbeforerotate(t_list *lst);

void	put_pos(t_list *lst);

int		extract_number(t_list **lst, char **av);

void	*ft_mallox(size_t nmemb, size_t size);

void	new_node(t_list **lst, int nbr);

void	print_lst(t_list *lst_a, t_list *lst_b);

void	swap_top(t_list **lst);

void	check_swap(t_list **lst, t_list **lst_b, int swap);

int		to_print(int keep, int swap);

void	show_mov(int keep);

void	swap_rotate(t_list **lst);

void	swap_reverse(t_list **lst);

void	swap_ab(t_list **lst_a, t_list **lst_b);

void	free_lst(t_list *lst);

void	algo1(t_list **lst_a, t_list **lst_b);

void	algo2(t_list **lst_a, t_list **lst_b, int counter_a, int counter_b);

int		lessthanseven(t_list *lst_a, int counter_a, int counter);

int		morethansix(t_list **lst_a, t_list **lst_b, int laststep);

int		lessthanthree(t_list *lst_a);

int		b3(t_list *lst_b);

int		upto100parti(t_list **lst_a, t_list **lst_b, int counter);

int		upto100partia(t_list *lst, int counter);

int		upto100partib(t_list *lst, int counter);

int		upto100partii(t_list *lst, t_list *lst_b);

int		upto100partiia(t_list *lst, int counter);

int		upto100partiib(t_list *lst);

int		upto100partiii(t_list **lst_a, t_list **lst_b, int counter_a);

int		chunkdiv(int counter_a, int check);

int		change_div(t_list *lst_a, int counter);

int		rotatebchecker(t_list **lst_b, int pos);

int		tabesttomove(int count1, int count2, int count3, int count4);

int		talowerchecker(t_list *lst_a, int pos);

int		talowerfinder(t_list *lst_a, int pos);

int		tacountnbrposition(t_list *lst_a, int nbr);

int		taclosesposition(t_list **lst_a, t_list **lst_b, int a);

int		distancetohead(int pos, int counter);

t_list	*tacloses(t_list **lst_b, int counter);

int		tabesttomove(int count1, int count2, int count3, int count4);

int		upto100partiv(t_list *lst_a, int counter);

int		choose_rotate(int pos, int counter_a);

int		choose_rotate2(int pos, int counter_a, int lock);

t_list	*get_last(t_list *lst_a);

#endif