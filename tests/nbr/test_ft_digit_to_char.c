/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_digit_to_char.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:29:01 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_digit_to_char)
{
	int	i = 0;

	while (i <= 9)
	{
		massert(ft_digit_to_char(i), (char)(i + '0'));
		i++;
	}

	massert(ft_digit_to_char(-1), (char)'\0');
	massert(ft_digit_to_char(10), (char)'\0');
}
