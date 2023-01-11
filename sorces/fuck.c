/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:54:27 by dcella-d          #+#    #+#             */
/*   Updated: 2023/01/10 19:54:31 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	*ft_mallox(size_t nmemb, size_t size)
{
	void	*nmembp;
	size_t	f;

	f = -1;
	nmembp = (void *) malloc(nmemb * size);
	if (!nmembp)
		return (NULL);
	while (++f < nmemb * size)
		((unsigned char *)nmembp)[f] = 0;
	return (nmembp);
}
