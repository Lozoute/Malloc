/*
** wrappers.c for malloc in /home/auzou_t/rendu/PSU_2014_malloc/new
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Thu Feb  5 11:09:36 2015 Thibaud Auzou
** Last update Fri Feb 13 16:34:00 2015 Thibaud Auzou
*/

#include "malloc.h"

t_header		**start(void)
{
  static t_header	*v_start = NULL;

  if (v_start == NULL)
    {
      v_start = sbrk(0);
      if (v_start == (void *)(-1))
	{
	  write(1, "sbrk failed\n", 12);
	  return (NULL);
	}
    }
  return (&v_start);
}

t_header		**v_end(void)
{
  static t_header	*v_end = NULL;

  if (v_end == NULL)
    {
      v_end = *(start());
      v_end->size = 0;
    }
  return (&v_end);
}

size_t			page_size(void)
{
  static size_t		size = 0;

  if (size == 0)
    size = getpagesize() * 3;
  return (size);
}

pthread_mutex_t		*mutex(void)
{
  static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

  return (&lock);
}
