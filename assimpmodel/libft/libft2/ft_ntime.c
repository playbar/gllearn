/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 18:56:46 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/19 18:51:13 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>
#include <mach/mach_time.h>

t_timespec		orwl_gettime(void)
{
	struct timespec				t;
	double						diff;
	static double				orwl_timebase = 0.0;
	static uint64_t				orwl_timestart = 0;
	mach_timebase_info_data_t	tb;

	if (!orwl_timestart)
	{
		mach_timebase_info(&tb);
		orwl_timebase = tb.numer;
		orwl_timebase /= tb.denom;
		orwl_timestart = mach_absolute_time();
	}
	diff = (mach_absolute_time() - orwl_timestart) * orwl_timebase;
	t.tv_sec = diff * 1.0e-9;
	t.tv_nsec = diff - (t.tv_sec * 1e9);
	return (t);
}

size_t			ft_ntime(void)
{
	struct timespec	thetime;
	size_t			time;

	time = 0;
	thetime = orwl_gettime();
	time = thetime.tv_sec * 1e9 + thetime.tv_nsec;
	return (time);
}
