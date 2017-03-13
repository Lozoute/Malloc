/*
** free_list.c for malloc in /home/auzou_t/rendu/PSU_2014_malloc
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Wed Feb  4 15:30:47 2015 Thibaud Auzou
** Last update Sat Feb 14 09:23:15 2015 Thibaud Auzou
*/

#include "malloc.h"

int			push(t_header *elem)
{
  t_header		*tmp;
  t_header		*tmp2;

  elem->is_free = 1;
  tmp = *(first());
  tmp2 = tmp;
  while (tmp != NULL && tmp->size > elem->size)
    {
      tmp2 = tmp;
      tmp = tmp->next_free;
    }
  if (tmp == NULL)
    return (push_last(elem, tmp2));
  else if (tmp == elem)
    return (0);
  else if (tmp->prev_free == NULL && tmp == tmp2)
    return (push_first(elem, tmp));
  elem->next_free = tmp;
  elem->prev_free = tmp2;
  tmp2->next_free = elem;
  tmp->prev_free = elem;
  return (0);
}

int			push_first(t_header *elem, t_header *tmp)
{
  elem->prev_free = NULL;
  elem->next_free = tmp;
  tmp->prev_free = elem;
  *(first()) = elem;
  return (0);
}

int			push_last(t_header *elem, t_header *tmp2)
{
  if (tmp2 == NULL)
    *(first()) = elem;
  else
    tmp2->next_free = elem;
  elem->prev_free = tmp2;
  elem->next_free = NULL;
  return (0);
}

int			pop(t_header *elem)
{
  if (elem->prev_free == NULL)
    *(first()) = elem->next_free;
  else
    elem->prev_free->next_free = elem->next_free;
  if (elem->next_free != NULL)
    elem->next_free->prev_free = elem->prev_free;
  elem->is_free = 0;
  elem->next_free = NULL;
  elem->prev_free = NULL;
  return (0);
}

t_header		**first(void)
{
  static t_header	*elem = NULL;

  return (&elem);
}
