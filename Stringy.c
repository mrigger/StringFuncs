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

int strncmpClone(char *str1, char *str2, int n) {
  char *cp1 = str1;
  char *cp2 = str2;
  while (n) {
    if (*cp1 > *cp2) {return 1;}
    else if (*cp1 < *cp2) {return -1;}
    n--;
    cp1++;
    cp2++;
  }
  return 0;
}


char * strcpyClone(char *dest, char *source) {
  char *letter = source;
  char *word = dest;
  while (*letter) {
    *word = *letter;
    word++;
    letter++;
  }
  return dest;
}


char * strncpyClone(char *dest, char* source, int n) {
  char *letter = source;
  char *word = dest;
  while (n && *letter) {
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
  while (*part) {
    *location = *part;
    location++;
    part++;    
  }
  *location = 0;
  return dest;
}

char * strncatClone(char *dest, char * source, int n) {
  char *location = dest;
  char *part = source;
  while (*location) {
    location++;
  }
  while (*part && n) {
    *location = *part;
    location++;
    part++;
    n--;
  }
  *location = 0;
  return dest;
}


//search and returns pointer
char * strchrClone(char *s, char c) {
  char *word = s;
  while (*word != c) {
    word++;
  }
  if (*word == c) {
    return word;
  }
  return 0;
}


char * strstrClone(char *s, char *c) {
  char *word = s;
  char *check = c;
  //printf("start word: %c\n",*word);
  char *wordchar;
  char *checkchar;
  while (*word) {
    //printf("word: %c   check: %c\n",*word,*check);
    if (*word == *check) {
      wordchar = word;
      checkchar = check;
      while (*wordchar == *checkchar && *wordchar && *checkchar) {
	//printf("comapre2: %c %c\n",*wordchar,*checkchar);
	checkchar++;
	wordchar++;
      }
      if (!*checkchar) {
	return word;
      }
    }
    word++;
  }
  printf("end loop");
  return 0;
}



int main() {
  printf("Testing strlen:\n");
  printf("length of expend: %lu\n",strlen("expend"));
  printf("length of expend (my copy): %d\n",strlenClone("expend"));
  printf("length of : %lu\n",strlen(""));
  printf("length of (my copy): %d\n",strlenClone(""));
  printf("length of somethingsuperlong: %lu\n",strlen("somethingsuperlong"));
  printf("length of somethingsuperlong (my copy): %d\n",strlenClone("somethingsuperlong"));
  
  printf("**************************\n\n");
  
  printf("Testing strcmp:\n");
  char str1[] = "apple";
  char str3[] = "april";
  char str4[] = "apothesis";
  printf("apple to itself: %d\n",strcmp(str1,str1));
  printf("apple to april: %d\n",strcmp(str1,str3));
  printf("apple to apothesis: %d\n",strcmp(str1,str4));  
  printf("----------------- Mine up next\n");
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
  char destination[200] = "Why don't you say";
  printf("source: %s\n",source);
  printf("destination: %s\n",destination);
  strcat(destination,source);
  printf("Final product: %s    :)\n",destination);
  printf("------------------ Mine up next\n");
  char source2[] = " Hello";
  char destination2[200] = "Why don't you say";
  printf("source2: %s\n",source2);
  printf("destination2: %s\n",destination2);
  strcat(destination2,source2);
  printf("Final product: %s    :)\n",destination2);

  printf("*************************\n\n");

  printf("Testing strchr:\n");
  char catch[] = "abrakadabrawalakazam";
  char findme = 'w';
  printf("catch: %s\n",catch);
  printf("findme: %c\n",findme);
  char *where = strchr(catch,findme);
  //printf("Pointer is at: %lu\n",where);
  printf("value at pointer: %c\n",*where);

  printf("------------------ Mine up next\n");

  
  char catch2[] = "abrakadabrawalakazam";
  char findme2 = 'w';
  printf("catch2: %s\n",catch2);
  printf("findme2: %c\n",findme2);
  char *where2 = strchrClone(catch2,findme2);
  //printf("Pointer is at: %lu\n",where2);
  printf("value at pointer: %c\n",*where2);

  printf("*******************\n\n");

  printf("Testing strncmp:\n");
  char word1[] = "banana";
  char word2[] = "bandana";
  char word3[] = "baidu";
  printf("banana to bandana up to char 3: %d\n",strncmp(word1,word2,3));
  printf("banana to bandana up to char 4: %d\n",strncmp(word1,word2,4));
  printf("bandana to baidu up to char 4: %d\n",strncmp(word2,word3,3));
  printf("--------------------------- Mine up next\n");
  char word12[] = "banana";
  char word22[] = "bandana";
  char word32[] = "baidu";
  printf("banana to bandana up to char 3: %d\n",strncmpClone(word12,word22,3));
  printf("banana to bandana up to char 4: %d\n",strncmpClone(word12,word22,4));
  printf("bandana to baidu up to char 4: %d\n",strncmpClone(word22,word32,3));

  printf("***********************\n\n");

  printf("Testing strncpy:\n");
  char copyme[] = "railroad";
  char crushme[] = "bluecarjunction";
  printf("copyme (source): %s\n",copyme);
  printf("crushme (dest): %s\n",crushme);
  strncpy(crushme,copyme,4);
  printf("crushme after strncpy 4: %s\n",crushme);
  printf("-----------------------\n");
  char copyme2[] = "railroad";
  char crushme2[] = "bluecarjunction";
  printf("copyme2 (source): %s\n",copyme2);
  printf("crushme2 (dest): %s\n",crushme2);
  strncpy(crushme2,copyme2,4);
  printf("crushme2 after strncpy 4: %s\n",crushme2);


  printf("****************************\n\n");

  printf("Testing strcat:\n");
  char sourcey[] = "applebee employee";
  char destinationy[200] = "I am an ";
  printf("sourcey: %s\n",sourcey);
  printf("destinationy: %s\n",destinationy);
  strncat(destinationy,sourcey,5);
  printf("Final product: %s    :)\n",destinationy);
  printf("------------------ Mine up next\n");
  char sourcey2[] = "applebee employee";
  char destinationy2[200] = "I am an ";
  printf("sourcey2: %s\n",sourcey2);
  printf("destinationy2: %s\n",destinationy2);
  strncatClone(destinationy2,sourcey2,5);
  printf("Final product: %s    :)\n",destinationy2);


  printf("*************************\n\n");

  printf("Testing strstr:\n");
  char catchy[] = "abrakadabrawalakazam";
  char findmey[] = "kadabra";
  printf("catchy: %s\n",catchy);
  printf("findmey: %s\n",findmey);
  char *wherey = strstr(catchy,findmey);
  printf("value at pointer: %c\nString from the value: ",*wherey);
  while (*wherey) {
    printf("%c",*wherey);
    wherey++;
  }
  printf("\n");

  printf("------------------ Mine up next\n");

  
  char catchy2[] = "abrakadabrawalakazam";
  char findmey2[] = "kadabra";
  printf("catchy2: %s\n",catchy2);
  printf("findmey2: %s\n",findmey2);
  char *wherey2 = strstrClone(catchy2,findmey2);
  printf("value at pointer: %c\nString from the value: ",*wherey2);
  while (*wherey2) {
    printf("%c",*wherey2);
    wherey2++;
  }
  printf("\n");
  
  return 0;
}
