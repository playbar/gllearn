/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 13:25:12 by edelangh          #+#    #+#             */
/*   Updated: 2015/01/21 12:06:31 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(void **a, void **b)
{
	void	*s;

	s = *a;
	*a = *b;
	*b = s;
}

void	ft_swap_int(int *a, int *b)
{
	int	i;

	i = *a;
	*a = *b;
	*b = i;
}

void	ft_swap_double(double *a, double *b)
{
	double	i;

	i = *a;
	*a = *b;
	*b = i;
}
