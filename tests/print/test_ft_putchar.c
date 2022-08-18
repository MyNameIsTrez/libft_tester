/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_putchar.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:58:15 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/18 14:10:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_putchar)
{
	test_io(ft_putchar, 'a', "a", -1, 0);
	test_io(ft_putchar, '\0', "\0", -1, 1);
}

////////////////////////////////////////////////////////////////////////////////
