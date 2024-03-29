/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_striteri.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:10:14 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/20 12:13:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

static void	increase_by_index(unsigned int i, char *c)
{
	*c += (char)i;
}

Test(ft_striteri)
{
	char	s[] = "foo";

	ft_striteri(s, increase_by_index);
	massert(s, "fpq");
}
