/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_flags.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adisco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:52:09 by adisco            #+#    #+#             */
/*   Updated: 2020/02/24 15:42:39 by adisco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_SPEC_FLAGS_H
# define PF_SPEC_FLAGS_H

typedef struct	s_spec_flags
{
	int		l;
	int		h;
	int		l_upper;
	int		z;
	int		j;
}				t_spec_flags;

void			pf_init_spec_flags(t_spec_flags *sf);
void			pf_upd_spec_flags(t_spec_flags *sf, char c);
int				pf_get_size(t_spec_flags sf);

#endif
