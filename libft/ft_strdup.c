/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjoukni <sjoukni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:38:39 by sjoukni           #+#    #+#             */
/*   Updated: 2025/04/08 15:38:02 by sjoukni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1, int len)
{
	int		i;
	char	*cpy;

	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (s1[i] && len)
	{
		cpy[i] = s1[i];
		i++;
		len--;
	}
	cpy[i] = 0;
	return (cpy);
}
