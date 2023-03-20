/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_set_error.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/23 13:53:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/06 13:54:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_get_and_set_error)
{
	massert_success(ft_get_error(), OK);
	ft_set_error(FT_ERROR_TOO_FEW_ARGS);
	massert_success(ft_get_error(), FT_ERROR_TOO_FEW_ARGS);
}
