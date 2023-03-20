/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strlen.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:29:14 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_strlen)
{
	massert(ft_strlen(""), strlen(""));
	massert(ft_strlen("f"), strlen("f"));
	massert(ft_strlen("fo"), strlen("fo"));
	massert(ft_strlen("foo"), strlen("foo"));
}
