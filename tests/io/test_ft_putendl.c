/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_putendl.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:59:52 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/25 17:58:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_putendl)
{
	test_io(ft_putendl, "foo", "foo\n", -1);
}

////////////////////////////////////////////////////////////////////////////////
