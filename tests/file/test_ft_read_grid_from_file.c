/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_read_grid_from_file.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:37:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/11 18:06:14 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_read_grid_from_file)
{
	t_u8_grid	grid;
	t_status	success;

	success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/empty");
	massert(success, (t_status)ERROR);
	if (NOT was_malloc_unstable)
		massert(ft_get_error(), (t_ft_error)FT_ERROR_EMPTY_FILE);
}

Test(ft_read_grid_from_file2)
{
	t_u8_grid		grid;
	t_status	success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/no_trailing_newline");
	m_safe_assert(t_status, success, OK, ERROR, false);
	if (NOT was_malloc_unstable)
	{
		massert(grid.width, (size_t)13);
		massert(grid.height, (size_t)5);
		massert(ft_memcmp(&grid.cells[0 * 13], "1111111111111", 13), 0);
		massert(ft_memcmp(&grid.cells[1 * 13], "10010000000C1", 13), 0);
		massert(ft_memcmp(&grid.cells[2 * 13], "1000011111001", 13), 0);
		massert(ft_memcmp(&grid.cells[3 * 13], "1P0011E000001", 13), 0);
		massert(ft_memcmp(&grid.cells[4 * 13], "1111111111111", 13), 0);
	}
}

Test(ft_read_grid_from_file3)
{
	t_u8_grid		grid;
	t_status	success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/not_rectangular");
	massert_success(success, ERROR);
	if (NOT was_malloc_unstable)
	{
		massert_success(ft_get_error(), FT_ERROR_NON_RECTANGULAR_GRID);
	}
}

Test(ft_read_grid_from_file4)
{
	t_u8_grid		grid;
	t_status	success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/trailing_newline");
	m_safe_assert(t_status, success, OK, ERROR, false);
	if (NOT was_malloc_unstable)
	{
		massert(grid.width, (size_t)13);
		massert(grid.height, (size_t)5);
		massert(ft_memcmp(&grid.cells[0 * 13], "1111111111111", 13), 0);
		massert(ft_memcmp(&grid.cells[1 * 13], "10010000000C1", 13), 0);
		massert(ft_memcmp(&grid.cells[2 * 13], "1000011111001", 13), 0);
		massert(ft_memcmp(&grid.cells[3 * 13], "1P0011E000001", 13), 0);
		massert(ft_memcmp(&grid.cells[4 * 13], "1111111111111", 13), 0);
	}
}

////////////////////////////////////////////////////////////////////////////////
