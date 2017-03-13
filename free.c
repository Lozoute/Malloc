/*
** free.c for malloc in /home/auzou_t/rendu/PSU_2014_malloc/new
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Thu Feb  5 12:09:12 2015 Thibaud Auzou
** Last update Sat Feb 14 09:18:23 2015 Thibaud Auzou
*/

#include "malloc.h"

void		free(void *ptr)
{
  t_header	*elem;

  if (ptr != NULL)
    {
      pthread_mutex_lock(mutex());
      elem = (t_header *)(ptr) - 1;
      if (elem->prev != NULL && elem->prev->is_free == 1)
	elem = backward_fusion(elem);
      if (elem->next != NULL && elem->next->is_free == 1)
	elem = forward_fusion(elem);
      push(elem);
      pthread_mutex_unlock(mutex());
    }
}

t_header	*backward_fusion(t_header *elem)
{
  t_header	*prev;

  prev = elem->prev;
  prev->size += elem->size + sizeof(t_header);
  prev->next = elem->next;
  if (elem->next != NULL)
    elem->next->prev = prev;
  if (elem == *(v_end()))
    *(v_end()) = prev;
  pop(prev);
  return (prev);
}

t_header	*forward_fusion(t_header *elem)
{
  t_header	*next;

  next = elem->next;
  elem->next = next->next;
  elem->size += next->size + sizeof(t_header);
  if (next->next != NULL)
    next->next->prev = elem;
  if (*(v_end()) == next)
    *(v_end()) = elem;
  pop(next);
  return (elem);
}
