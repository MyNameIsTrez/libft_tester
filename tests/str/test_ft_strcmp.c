/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strcmp.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 16:55:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_strcmp)
{
	massert(ft_strcmp("atoms\0", "atomsa"), '\0' - 'a');
	massert(ft_strcmp("atomsf", "atomsa"), 'f' - 'a');
	massert(ft_strcmp("atomsa", "atoms\0"), 'a' - '\0');
	massert(ft_strcmp("", "AAAAAA"), '\0' - 'A');
	massert(ft_strcmp("atoms\0\0\0\0", "atoms\0abc"), 0);
	massert(ft_strcmp("", "469"), '\0' - '4');
}
