/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flower.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:21:11 by dlaure            #+#    #+#             */
/*   Updated: 2020/06/09 02:10:37 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*thread_func(void *thread)
{
	t_fract_m	*fract;

	fract = (t_fract_m *)thread;
	while (fract->current < fract->next)
	{
		distrib_fract(fract);
		fract->current++;
	}
	return (thread);
}

void	fract_pthreads(t_fract_m *fract)
{
	t_fract_m	thread[THREADS];
	pthread_t	pth[THREADS];
	int			i;
	int			depth;

	i = 0;
	depth = WIDTH / THREADS;
	while (i < THREADS)
	{
		ft_memcpy((void*)&thread[i], (void*)fract, sizeof(t_fract_m));
		thread[i].current = depth * i;
		thread[i].next = depth * (i + 1);
		pthread_create(&pth[i], NULL, thread_func, &thread[i]);
		i++;
	}
	while (i--)
		pthread_join(pth[i], NULL);
}
