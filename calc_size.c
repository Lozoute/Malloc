/*
** calc_size.c for malloc in /home/auzou_t/rendu/PSU_2014_malloc/thibaud
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Fri Jan 30 17:11:20 2015 Thibaud Auzou
** Last update Wed Feb 11 16:01:47 2015 Thibaud Auzou
*/

#include "malloc.h"

size_t		padd_size(size_t size)
{
  if (size < ALIGN)
    return (ALIGN);
  return (size + (ALIGN - (size % ALIGN)));
}

size_t		calc_alloc_size(size_t size)
{
  size += sizeof(t_header);
  if (size < page_size())
    return (page_size());
  return (size + (page_size() - (size % page_size())));
}
