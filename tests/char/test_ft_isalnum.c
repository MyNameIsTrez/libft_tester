/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_isalnum.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:39:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

#ifndef linux
Test(ft_isalnum)
{
	int	chr;

	chr = 0;
	while (chr <= 255)
	{
		massert(ft_isalnum(chr), isalnum(chr));
		chr++;
	}
}
#endif
