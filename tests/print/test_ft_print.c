/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_print.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:55:55 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/18 14:06:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_print)
{
	test_io(ft_print, "foo\nbar", "foo\\nbar", -1, 0);
}
