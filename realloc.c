/*
** realloc.c for malloc in /home/auzou_t/rendu/PSU_2014_malloc/new
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Thu Feb  5 12:20:46 2015 Thibaud Auzou
** Last update Sat Feb 14 10:05:10 2015 Thibaud Auzou
*/

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
  t_header	*elem;

  if (ptr == NULL)
    return (malloc(size));
  if ((intptr_t)(size) <= 0)
    {
      free(ptr);
      return (NULL);
    }
  elem = (t_header *)(ptr) - 1;
  if (size < elem->size)
    return (ptr);
  if (elem->next != NULL && elem->next->is_free == 1 &&
      elem->size + sizeof(t_header) + elem->next->size >= size)
    return (enlarge_alloc(elem, size));
  return (move_alloc(elem, size));
}

void		*enlarge_alloc(t_header *elem, size_t size)
{
  pthread_mutex_lock(mutex());
  elem = forward_fusion(elem);
  elem = cut_free_space(elem, size, 0);
  return (elem);
}

void		*move_alloc(t_header *elem, size_t size)
{
  char		*old;
  char		*new;
  size_t	i;

  old = (char *)(elem + 1);
  new = malloc(size);
  i = 0;
  while (i < size && i < elem->size)
    {
      new[i] = old[i];
      ++i;
    }
  free(old);
  return (new);
}
