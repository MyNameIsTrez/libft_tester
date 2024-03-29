/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_is_upper.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 14:12:24 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_is_upper)
{
	massert(ft_is_upper('A'), (bool)true);
	massert(ft_is_upper('A'), (bool)true);

	massert(ft_is_upper('a'), (bool)false);
	massert(ft_is_upper('z'), (bool)false);
	massert(ft_is_upper('#'), (bool)false);
}
