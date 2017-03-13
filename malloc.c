/*
** malloc.c for malloc in /home/auzou_t/rendu/PSU_2014_malloc/new
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Thu Feb  5 11:06:35 2015 Thibaud Auzou
** Last update Fri Feb 13 16:20:14 2015 Thibaud Auzou
*/

#include "malloc.h"

void		*malloc(size_t size)
{
  t_header	*tmp;

  if ((intptr_t)(size) <= 0 || start() == NULL)
    return (NULL);
  pthread_mutex_lock(mutex());
  size = padd_size(size);
  if ((tmp = *(first())) != NULL && tmp->size >= size)
    return (cut_free_space(tmp, size, 1));
  return (new_alloc(size));
}

void		*cut_free_space(t_header *elem, size_t size, int need_pop)
{
  t_header	*new;

  if (elem->size > size + sizeof(t_header))
    {
      new = (t_header *)((char *)(elem) + sizeof(t_header) + size);
      new->next = elem->next;
      new->prev = elem;
      if (elem->next != NULL)
	elem->next->prev = new;
      new->size = elem->size - size - sizeof(t_header);
      elem->next = new;
      elem->size = size;
      push(new);
      if (*(v_end()) == elem)
	*(v_end()) = new;
    }
  if (need_pop)
    pop(elem);
  pthread_mutex_unlock(mutex());
  return (elem + 1);
}

void		*new_alloc(size_t size)
{
  t_header	*elem;
  size_t	alloc_size;

  alloc_size = calc_alloc_size(size);
  if (sbrk(alloc_size) == (void *)(-1))
    {
      write(1, "sbrk failed\n", 12);
      pthread_mutex_unlock(mutex());
      return (NULL);
    }
  elem = set_new_end(alloc_size - sizeof(t_header));
  return (cut_free_space(elem, size, 0));
}

t_header	*set_new_end(size_t size)
{
  t_header	*old_end;
  t_header	*new_end;

  old_end = *(v_end());
  if (old_end->size == 0)
    return (first_alloc(old_end, size));
  new_end = (t_header *)((char *)(old_end) + sizeof(t_header) + old_end->size);
  old_end->next = new_end;
  new_end->next = NULL;
  new_end->prev = old_end;
  new_end->size = size;
  new_end->is_free = 0;
  new_end->next_free = NULL;
  new_end->prev_free = NULL;
  *(v_end()) = new_end;
  return (new_end);
}

t_header	*first_alloc(t_header *first, size_t size)
{
  first->size = size;
  first->prev = NULL;
  first->next = NULL;
  first->next_free = NULL;
  first->prev_free = NULL;
  first->is_free = 0;
  return (first);
}
