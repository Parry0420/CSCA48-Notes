/**
 * Exercise 3
 *
 * Please read the comments below carefully, they describe your task in detail.
 * 
 */

#include <stdio.h>
// NO additional imports allowed.
//You can create helper functions.

// Maximum length of a string
#define MAX_STRING_LEN 1024

//-----------------------------------------------------------------------------
int strlen(char str[]){
  int len;
  for(len = 0; str[len]!='\0'; len++);
  return len;
}

int find_index(char str[], char a[]){
  int i;
  for(i=0;str[i]!='\0';i++){
    if(str[i] == a[0]){
      int j;
      int check = 1;
      for(j=0;a[j]!='\0';j++){
        if(str[i+j]!=a[j]){
          check = 0;
        }
      }
      if(check==1){return i;}
    }
  }
  return -1;
}

void replaceSubstring(char str[], char a[], char b[])
{
  /**
   * If `a` is a substring of `str`, then the first occurence of `a` in `str`
   * is replaced with `b`.
   *
   * For example:
   *
   *    char str[50] = "Hello World!";
   *    replaceSubstring(str, "llo W", "---");
   *    printf("%s\n", str);
   *
   * should print out "He---orld!"
   *
   * You may assume that `str[]`` has enough space to store the modified string.
   * Remember that all the strings here all null-terminated, and you must
   * also null-terminate the modified string.hg
   */
  int len_a = strlen(a);
  int len_str = strlen(str);
  int star = find_index(str,a);
  if(star==-1){return;}
  int end = star + len_a;
  int i ;
  int x;
  char copy_str_end[MAX_STRING_LEN];

  for(x=0;str[end+x]!='\0';x++){
    copy_str_end[x] = str[end+x];
  }
  copy_str_end[x] = '\0';

  for(i=0;b[i]!='\0';i++){
    str[star+i] = b[i];
  }

  for(int y=0;copy_str_end[y]!='\0';y++){
    str[star+i] =copy_str_end[y]; 
    i++;
  }
  str[star+i]='\0';
}

void changeSubstringCase(char str[], char a[])
{
  /**
   * If `a` is a substring of `str`, then change the case (capitalization) of
   * the first occurence of the corresponding substring in `str`. Special
   * characters (' ', '.', ...) do not need to be handled. You should only
   * change the letters.
   *
   * For example:
   *
   *    char str[100] = "This IS a SENTence WITH BAd CAPITalizaTION";
   *    changeSubstringCase(str, "IS a SENTence WI");
   *    printf("%s\n", str);
   *
   * should print out "This is A sentENCE wiTH BAd CAPITalizaTION".
   */
  char copy1_a[MAX_STRING_LEN];
  char copy2_a[MAX_STRING_LEN];
  int j;
  for(j=0;a[j]!='\0';j++){
    copy1_a[j] = a[j];
    copy2_a[j]=a[j];
  }
  copy1_a[j]='\0';
  copy2_a[j]='\0';

  for(int i=0;copy2_a[i]!='\0';i++){
    if(copy2_a[i]>=65 && copy2_a[i]<=90){
      copy2_a[i]=copy2_a[i]+32;
    }
    else if(copy2_a[i]>=97 && copy2_a[i]<=122){
      copy2_a[i] = copy2_a[i]-32;
    }
  }
  replaceSubstring(str,copy1_a,copy2_a);
}

//-----------------------------------------------------------------------------

// Do not change the lines above and below the main function. These
// are added to ensure that the main() function defined here does not
// Conflict with the automarker when testing your code. Changing them
// will result in a 0 for this exercise. You are free to change anything
// inside the main() function itself.
#ifndef __testing__
int main()
{
  char str[MAX_STRING_LEN] = "CSCA48 Exercise 3";

  // This should replace the substring:
  replaceSubstring(str, "A48 Ex", "A48 sUMMER Ex");

  // This should NOT replace anything, since some of the letters
  // in `a` have a different capitalization than in the string, so it is
  // NOT a valid substring.
  replaceSubstring(str, "summer", "Winter");

  // This should change the capitalization of the substring:
  changeSubstringCase(str, "sUMMER");

  // This should NOT change the capitalization, since the corresponding letters
  // in `a` are lowercase, and it is not a valid substring.
  changeSubstringCase(str, "csca48");

  printf("Expected result: \"CSCA48 Summer Exercise 3\"\n");
  printf("Your solution: \"%s\"\n", str);
  return 0;
}
#endif
