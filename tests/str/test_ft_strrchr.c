/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strrchr.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:37:14 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_strrchr)
{
	massert((void *)ft_strrchr("bonjour", 's'), (void *)strrchr("bonjour", 's'));
	massert((void *)ft_strrchr("bonjour", 'j'), (void *)strrchr("bonjour", 'j'));
}
