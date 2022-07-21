/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_lower.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 14:33:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/21 14:48:53 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_str_lower)
{
	{
		char	*tested = ft_str_lower(strdup("FOO"));
		massert(tested, "foo");
		ft_free(&tested);
	}

	{
		char	*tested = ft_str_lower(strdup("foo"));
		massert(tested, "foo");
		ft_free(&tested);
	}

	{
		char	*tested = ft_str_lower(strdup("$"));
		massert(tested, "$");
		ft_free(&tested);
	}
}

////////////////////////////////////////////////////////////////////////////////
