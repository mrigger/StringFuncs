#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlenClone(char *s) {
  int len = 0;
  char *cp = s;
  
  while (*cp != 0) {
    len++;
    cp++;
  }
  return len;
}


char strcpyClone(char *dest, const char *src) {
  const char *letter = src;
  char *word = dest;
  while (*letter) {
    *word = *letter;
    word++;
    letter++;
  }
  return *dest;
}


int strcmpClone(char *str1, char *str2) {
  char *cp1 = str1;
  char *cp2 = str2;
  while (*cp1 == *cp2 && *cp1 && *cp2) {
    cp1++;
    cp2++;
  }
  if (*cp1 < *cp2) {return -1;}
  else if (*cp1 > *cp2) {return 1;}
  else {return 0;}
}


int main() {
  char str1[] = "apple";
  char str2[] = "apple";
  char str3[] = "april";
  char str4[] = "apothesis";
  printf("%d\n",strcmp(str1,str2));
  printf("%d\n",strcmp(str1,str3));
  printf("%d\n",strcmp(str1,str4));  
  printf("-----------------\n");
  printf("%d\n",strcmpClone(str1,str2));
  printf("%d\n",strcmpClone(str1,str3));
  printf("%d\n",strcmpClone(str1,str4));

  printf("***********************");
  
  char src[] = "This is to be copied.";
  char dest[40];
  strcpy(dest,src);
  printf("Copied string: %s\n",dest);
  printf("-----------------------");
  char src2[] = "This is to be copied.";
  char dest2[40];
  strcpyClone(dest2,src2);
  printf("Copied string: %s\n",dest2);
  
}
