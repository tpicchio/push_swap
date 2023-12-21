/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:05:33 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/13 14:24:02 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(unsigned int num, char format, int fd)
{
	char	*base;
	int		print_length;

	print_length = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num == 0)
		print_length += ft_putchar_fd('0', fd);
	else
		print_length += ft_putnbrbase_wrapper_fd(num, base, fd);
	return (print_length);
}
