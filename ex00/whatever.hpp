/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:19:46 by jisokim2          #+#    #+#             */
/*   Updated: 2026/07/02 17:20:41 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void Swpas(T &t1, T &t2)
{
    T temp = &t1;
    &t1 = &t2;
    &t2 = temp;
}

template <typename T>
const T& min(T const &t1, T const &t2)
{
   return (t1 >= t2) ? t2 : t1;
}

template <typename T>
const T &max(T const &t1, T const &t2)
{
   return (t1 <= t2) ? t2 : t1;
}

