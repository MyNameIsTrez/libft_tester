/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_q.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 18:18:08 by sbos          #+#    #+#                 */
/*   Updated: 2023/02/20 18:18:08 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

// Test(test_q_overwriting_with_smaller_priority)
// {
//   const t_q	q = q_new_reserved(2);

//   q_push(&q, 2, 10);
//   q_push(&q, 2, 5);

//   massert(q.heap[0].value, 2);
//   massert(q.heap[0].priority, 5);
//   massert(q.heap[1].value, ENTRY_REMOVED);
//   massert(q.heap[1].priority, 10);

//   massert(q_pop(&q), 2);
//   massert(q_pop(&q), -1);
// }

// Test(test_q_overwriting_with_larger_priority)
// {
//   const t_q	q = q_new_reserved(2);

//   q_push(&q, 2, 5);
//   q_push(&q, 2, 10);

//   massert(q.heap[0].value, ENTRY_REMOVED);
//   massert(q.heap[0].priority, 5);
//   massert(q.heap[1].value, 2);
//   massert(q.heap[1].priority, 10);

//   massert(q_pop(&q), 2);
//   massert(q_pop(&q), -1);
// }

// Test(test_q_different_values_stationary)
// {
//   const t_q	q = q_new_reserved(2);

//   q_push(&q, 1, 3);
//   q_push(&q, 2, 10);

//   massert(q.heap[0].value, 1);
//   massert(q.heap[0].priority, 3);
//   massert(q.heap[1].value, 2);
//   massert(q.heap[1].priority, 10);

//   massert(q_pop(&q), 1);
//   massert(q_pop(&q), 2);
//   massert(q_pop(&q), -1);
// }

// Test(test_q_different_values_swapped)
// {
//   const t_q	q = q_new_reserved(2);

//   q_push(&q, 2, 10);
//   q_push(&q, 1, 3);

//   massert(q.heap[0].value, 1);
//   massert(q.heap[0].priority, 3);
//   massert(q.heap[1].value, 2);
//   massert(q.heap[1].priority, 10);

//   massert(q_pop(&q), 1);
//   massert(q_pop(&q), 2);
//   massert(q_pop(&q), -1);
// }

// Test(test_q_pop_empty)
// {
//   const t_q	q = q_new_reserved(1);
//   massert(q_pop(&q), -1);
// }

// Test(test_q_contains)
// {
//   const t_q	q = q_new_reserved(2);

//   q_push(&q, 2, 10);
//   q_push(&q, 1, 3);

//   massert(q_contains(q, 2), true);
//   massert(q_contains(q, 1), true);
//   massert(q_contains(q, 0), false);
//   massert(q_contains(q, 3), false);

//   massert(q_pop(&q), 1);
//   massert(q_contains(q, 1), false);
//   massert(q_contains(q, 2), true);
// }

// Test(test_q_get_priority)
// {
//   const t_q	q = q_new_reserved(3);

//   q_push(&q, 2, 10);
//   q_push(&q, 1, 3);
//   q_push(&q, 1, 4);

//   massert(q_get_priority(q, 2), 10);
//   massert(q_get_priority(q, 1), 4);
//   massert(q_get_priority(q, 0), -1);
//   massert(q_get_priority(q, 3), -1);

//   massert(q_pop(&q), 1);
//   massert(q_get_priority(q, 1), -1);
// }

// Test(test_q_same_priorities)
// {
//   const t_q	q = q_new_reserved(2);

//   q_push(&q, 2, 0);
//   q_push(&q, 1, 0);

//   massert(q.heap[0].value, 2);
//   massert(q.heap[0].priority, 0);
//   massert(q.heap[1].value, 1);
//   massert(q.heap[1].priority, 0);

//   massert(q_pop(&q), 2);
//   massert(q_pop(&q), 1);
//   massert(q_pop(&q), -1);
// }

// Test(test_q_inbetween_same_priorities)
// {
//   const t_q	q = q_new_reserved(3);

//   q_push(&q, 2, 5);
//   q_push(&q, 3, 4);
//   q_push(&q, 1, 5);

//   massert(q.heap[0].value, 3);
//   massert(q.heap[0].priority, 4);
//   massert(q.heap[1].value, 2);
//   massert(q.heap[1].priority, 5);
//   massert(q.heap[2].value, 1);
//   massert(q.heap[2].priority, 5);

//   massert(q_pop(&q), 3);
//   massert(q_pop(&q), 1);
//   massert(q_pop(&q), 2);
// }

// Test(test_q_swapping_removed_entry)
// {
//   const t_q	q = q_new_reserved(3);

//   q_push(&q, 0, 2);
//   q_push(&q, 0, 3);
//   q_push(&q, 1, 4);

//   massert(q.heap[0].value, ENTRY_REMOVED);
//   massert(q.heap[0].priority, 2);
//   massert(q.heap[1].value, 0);
//   massert(q.heap[1].priority, 3);
//   massert(q.heap[2].value, 1);
//   massert(q.heap[2].priority, 4);

//   massert(q_pop(&q), 0);
//   massert(q_pop(&q), 1);
//   massert(q_pop(&q), -1);
// }
