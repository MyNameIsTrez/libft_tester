/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_print_fd.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:55:55 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_print_fd)
{
	test_io_fd(ft_print_fd, "foo\nbar", "foo\\nbar", -1);
}

////////////////////////////////////////////////////////////////////////////////