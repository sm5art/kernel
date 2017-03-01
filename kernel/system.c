#include "system.h"

void  * memset(void *dest, char val, int len)
{
  char * a = (char *) dest;
  while(len > 0)
    {
      *a = val;
      a++;
      len--;
    }
  return(a);
}

void  * memsetw(void *dest, short val, int len)
{
  short * a = (short *) a;
  while(len > 0)
    {
      *a = val;
      a++;
      len--;
    }
  return(a);
}

void * memcpy(void *dest, void *src, int len)
{
  char * a = (char *) dest;
  char * b = (char *) src;
  while(len > 0){
    *a = *b;
    a++;
    b++;
    len--;
  }
  return (dest);
}

int strlen(char * str){
  int len;
  len = 0;
  while(*str !=0){
    len++;
    str++;
  }
  return (len);
}
