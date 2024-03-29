/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_char_to_digit.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:32:15 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_char_to_digit)
{
	int	i;

	i = 0;
	while (i <= 9)
	{
		massert(ft_char_to_digit((char)(i + '0')), i);
		i++;
	}
	massert(ft_char_to_digit(-1 + '0'), -1);
	massert(ft_char_to_digit(10 + '0'), -1);
}
