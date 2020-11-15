/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-madi <ael-madi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 00:47:39 by ael-madi          #+#    #+#             */
/*   Updated: 2020/11/09 10:47:32 by ael-madi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		len_nb(long int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int		len_nb_hexa(long int n, t_format *format)
{
	int i;

	i = 0;
	if (format->p_special)
		i += 2;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}
