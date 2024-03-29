/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_putchar_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:58:15 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/18 14:08:30 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_putchar_fd)
{
	test_io_fd(ft_putchar_fd, 'a', "a", -1, 0);
	test_io_fd(ft_putchar_fd, '\0', "\0", -1, 1);
}
