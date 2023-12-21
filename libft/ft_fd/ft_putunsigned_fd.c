/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:06:15 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/13 14:24:01 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsigned_fd(unsigned int n, int fd)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (n == 0)
		print_length += ft_putchar_fd('0', fd);
	else
	{
		num = ft_uitoa(n);
		print_length += ft_putstr_fd(num, fd);
		free(num);
	}
	return (print_length);
}
