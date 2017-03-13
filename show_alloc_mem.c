/*
** show_alloc_mem.c for malloc in /home/auzou_t/rendu/PSU_2014_malloc/thibaud
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Fri Jan 30 14:49:31 2015 Thibaud Auzou
** Last update Tue Feb 10 17:33:43 2015 Thibaud Auzou
*/

#include "malloc.h"

void            show_alloc_mem(void)
{
  t_header      *tmp1;
  char          *tmp2;

  tmp1 = *(start());
  printf("break : %p\n", sbrk(0));
  while (tmp1 != NULL)
    {
      printf("%p - ", (void *)(tmp1 + 1));
      tmp2 = (char *)(tmp1);
      tmp2 += tmp1->size + sizeof(t_header);
      printf("%p : %d octects ", (void *)(tmp2), (int)(tmp1->size));
      if (tmp1->is_free == 1)
        printf("libres\n");
      else
        printf("\n");
      tmp1 = tmp1->next;
    }
  printf("!Show\n");
}

int		dump(void)
{
  t_header	*tmp;

  tmp = *(first());
  while (tmp != NULL)
    {
      printf("%p - ", (void *)(tmp + 1));
      printf("%p ", (void *)(((char *)(tmp + 1)) + tmp->size));
      printf(": %d free bytes\n", (int)(tmp->size));
      tmp = tmp->next_free;
    }
  return (0);
}
