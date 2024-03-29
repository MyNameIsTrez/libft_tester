/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_isascii.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:44:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_isascii)
{
	int	chr;

	chr = 0;
	while (chr <= 255)
	{
		massert(ft_isascii(chr), isascii(chr));
		chr++;
	}
}
