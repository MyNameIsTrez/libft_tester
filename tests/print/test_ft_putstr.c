/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_putstr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:03:43 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_putstr)
{
	test_io(ft_putstr, "foo", "foo", -1);
}

////////////////////////////////////////////////////////////////////////////////
