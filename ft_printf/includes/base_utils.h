/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnickole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:48:50 by lnickole          #+#    #+#             */
/*   Updated: 2020/02/08 14:48:53 by lnickole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_UTILS_H
# define BASE_UTILS_H

void			set_spaces_base(t_data *data);
void			set_zeros_base(t_data *data, unsigned long nb, int base_len);
unsigned long	cast_base(t_data *data);

#endif
