/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:10:26 by eperaita          #+#    #+#             */
/*   Updated: 2021/08/03 16:45:30 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	int	r;

	r = 0;
	if ((a >= 'a' && a <= 'z') || (a <= 'Z' && a >= 'A'))
		r = 1;
	if (ft_isdigit(a))
		r = 1;
	return (r);
}
