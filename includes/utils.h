/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 20:10:42 by lnoisome          #+#    #+#             */
/*   Updated: 2020/08/26 18:29:06 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
    
# include <unistd.h>
# include <stdio.h>

size_t				ft_strlen(const char *s);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void *ft_calloc(size_t elem, size_t size_elem);
void *ft_memset(void *ptr, int c, size_t bytes);
int		ft_strequ(const char *s1, const char *s2);
__int64_t	ft_atoi(const char *s);
int	ft_strcmp(const char *s1, const char *s2);
int ft_isdigit(char c);
void ft_swap(t_player **a, t_player **b);
void	ft_putnbr(int nb);
void	ft_putstr(const char *s);
void	ft_putchar(char c);
void free_data(t_vm *vm);
void	print_memory(const void *arena, size_t size);
t_car *del_start(t_car **head, t_car *cur_car);
t_car *del_end(t_car *cur_car);
t_car *del_midl(t_car *cur_car);

#endif