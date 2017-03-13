/*
** memalign.c for malloc in /home/auzou_t/rendu/PSU_2014_malloc/new
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Fri Feb  6 15:15:52 2015 Thibaud Auzou
** Last update Sat Feb 14 09:24:47 2015 Thibaud Auzou
*/

#include "malloc.h"

int		posix_memalign(void **memptr, size_t alignment, size_t size)
{
  *memptr = NULL;
  alignment++;
  size++;
  return (0);
}
