/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:16:37 by jisokim2          #+#    #+#             */
/*   Updated: 2026/07/02 17:28:28 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void print_i(T &t)
{
  std::cout << t << std::endl;
}

// const T
template <typename T>
void print(const T &t)
{
  std::cout << t << std::endl;
}

template <typename T, typename F>
void iter(T *arr, size_t len, F func)
{
  for (size_t i = 0; i < len; i++)
    func(arr[i]);
}

#endif