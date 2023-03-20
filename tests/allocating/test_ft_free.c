/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_free.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:47:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 12:18:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_free_ft_alloc)
{
	char	*a;

	a = ft_strdup("foo", "test ft_free_ft_alloc");

	ft_free(&a);
}

Test(ft_free_double_ft_alloc)
{
	char	*a;

	a = ft_strdup("foo", "test ft_free_double_ft_alloc");

	ft_free(&a);
	ft_free(&a);
}


Test(ft_free_double_system)
{
	char	*a;

	a = strdup("foo");

	ft_free(&a);
	ft_free(&a);
}
