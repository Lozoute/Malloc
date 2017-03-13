/*
** calloc.c for malloc in /home/auzou_t/rendu/PSU_2014_malloc
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Sat Jan 31 20:49:22 2015 Thibaud Auzou
** Last update Sat Feb 14 09:32:15 2015 Thibaud Auzou
*/

#include <string.h>
#include "malloc.h"

void		*calloc(size_t nmemb, size_t size)
{
  void		*ptr;

  if ((intptr_t)(nmemb) <= 0 || (intptr_t)(size) <= 0)
    return (NULL);
  ptr = malloc(nmemb * size);
  ptr = memset(ptr, 0, nmemb * size);
  return (ptr);
}
