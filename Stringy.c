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


char * strcpyClone(char *dest, const char *src) {
  const char *letter = src;
  char *word = dest;
  while (*letter) {
    *word = *letter;
    word++;
    letter++;
  }
  return dest;
}

char * strcatClone(char *dest, char *source) {
  char *location = dest;
  char *part = source;
  while (*location) {
    location++;
  }
  while (*source) {
    *location = *part;
    location++;
    part++;    
  }
  return dest;
}

//search and returns pointer
//char * strchr(char *s, char *c) {

//}


int main() {
  printf("Testing strlen:\n");
  printf("length of expend: %d\n",strlen("expend"));
  printf("length of expend (my copy): %d\n",strlenClone("expend"));
  printf("length of : %d\n",strlen(""));
  printf("length of (my copy): %d\n",strlenClone(""));
  printf("length of somethingsuperlong: %d\n",strlen("somethingsuperlong"));
  printf("length of somethingsuperlong (my copy): %d\n",strlenClone("somethingsuperlong"));
  
  printf("**************************\n\n");
  
  printf("Testing strcmp:\n");
  char str1[] = "apple";
  char str3[] = "april";
  char str4[] = "apothesis";
  printf("apple to itself: %d\n",strcmp(str1,str1));
  printf("apple to april: %d\n",strcmp(str1,str3));
  printf("apple to apothesis: %d\n",strcmp(str1,str4));  
  printf("-----------------\n");
  printf("apple to itself: %d\n",strcmpClone(str1,str1));
  printf("apple to april: %d\n",strcmpClone(str1,str3));
  printf("apple to apothesis: %d\n",strcmpClone(str1,str4));

  printf("***********************\n\n");

  printf("Testing strcpy:\n");
  char src[] = "This is to be copied.";
  char dest[40] = "llll67l";
  printf("here is the original: %s\n",src);
  printf("here is the dest: %s\n",dest);
  strcpy(dest,src);
  printf("Copied string: %s\n",dest);
  printf("-----------------------\n");
  char src2[] = "This is to be copied.";
  char dest2[40] = "lllll";
  printf("here is the original: %s\n",src2);
  printf("here is the dest: %s\n",dest2);
  strcpyClone(dest2,src2);
  printf("Copied string: %s\n",dest2);

  printf("****************************\n\n");

  printf("Testing strcat:\n");
  char source[] = " Hello";
  char destination[] = "Why don't you say";
  printf("source: %s\n",source);
  printf("destination: %s\n",destination);
  strcat(destination,source);
  printf("Final product: %s\n",destination);
  printf("--------------\n");
  char source2[] = " Hello";
  char destination2[] = "Why don't you say";
  printf("source2: %s\n",source2);
  printf("destination2: %s\n",destination2);
  strcat(destination2,source2);
  printf("Final product: %s\n",destination2);


  printf("*************************\n\n");

  printf("Testing strchr:\n");
  char catch[] = "abrakadabrawalakazam";
  char findme = 'w';
  printf("catch: %s\n",catch);
  printf("findme: %c\n",findme);
  char *where = strchr(catch,findme);
  printf("Pointer is at: %lu\n",where);
  printf("value at pointer: %c\n",*where);

  printf("------------------\n");
  
  char catch2[] = "abrakadabrawalakazam";
  char findme2 = 'w';
  printf("catch2: %s\n",catch2);
  printf("findme2: %c\n",findme2);
  char *where2 = strchr(catch2,findme2);
  printf("Pointer is at: %lu\n",where2);
  printf("value at pointer: %c\n",*where2);
  
}