/**
 * Exercise 4
 *
 * Please read the comments below carefully, they describe your task in detail.
 *
 * NOTE: You should NOT use array notation inside your functions. Use only
 *       pointer notation for any code that you write. Any array notation
 *       used outside of the main function will result in a 0. This includes
 *       making a new array of characters.
 * E.g:   char x[1024]; <--- [] used to create a new array is prohibited
 * E.g:   char y = x[0]; <--- [] used to access an array is prohibited
 *
 */

#include <stdio.h>
#include <stdlib.h>
// NO additional imports allowed. You can make helper functions if you wish.

#define MAX_STRING_LEN 1024

int string_len(char *str){
  int len;
  for(len = 0; *str!='\0'; len++){
    *(str++);
  }
  return len;
}

char *reversed(char *str){
  int length = string_len(str);
  char *reversed_str=(char*)calloc(length+1,sizeof(char));
  char *head = reversed_str;
  str = str+(length-1);
  for(int i=0;i<length;i++){
    *reversed_str = *str;
    reversed_str++;
    str--;
  }
  *reversed_str = '\0';
  return head;
}

int check_vowel(char word){
  char *array_vowels ="aeiouAEIOU";
  char *tmp_array_vowels = array_vowels;
  for(int i=0;*tmp_array_vowels!='\0';i++){
    if(*tmp_array_vowels == word){
      return 1;
    }
    tmp_array_vowels++;
  }
  return 0;
}

char *find_last_substring(char *str, char *a)
{
  /**
   * Given a string `str` and another string `a`, return a pointer to the start
   * of the *LAST* occurrence of `a` in `str`. (Unlike last week's exercise, where you had to
   * find the FIRST occurrence).
   *
   * For instance, if we had:                       (here)
   *                                                  V
   *      char str[MAX_STRING_LEN] = "Hello everyone, Hello world!"
   *      char *res = find_last_substring(str, "Hello");
   *
   * then, we would except `res` to be a pointer to the character marked above.
   * In particular, since the second "Hello" is at index 16, we should get
   * the following:
   *
   *      res - str == 16;      (This is pointer arithmetic)
   *
   * If `a` is not a valid substring of `str`. return NULL.
   */
  char *reversed_str = reversed(str);
  char *reversed_a = reversed(a);
  char *tmp_reversed_str = reversed_str;
  char *tmp_reversed_a = reversed_a;

  int len_str = string_len(str);
  int len_a = string_len(a);
  if(len_str<len_a){
    free(tmp_reversed_a);
    free(tmp_reversed_str);
    return NULL;
  }
  
  int i;
  for(i=0;i<len_str;i++){
    if (i+len_a>len_str){break;}
    if(*reversed_str == *reversed_a){
      int j;
      int check = 1;

      char* tmp_str = reversed_str;
      char* tmp_a = reversed_a;
      for(j=0;j<len_a;j++){
        if(*tmp_str!=*tmp_a){
          check = 0;
          break;
        }
        else{
          tmp_a++;
          tmp_str++;
          continue;
        }
      }
      if(check==1){
        free(tmp_reversed_a);
        free(tmp_reversed_str);
        return str+(len_str-(i+len_a));
      }
    }
    reversed_str++;

  }
  free(tmp_reversed_a);
  free(tmp_reversed_str);
  return NULL;
}

void split_vowels(char *str, char *vowels)
{
  /**
   * Move all of the vowels from `str` (in the order of appearance) to the
   * string `vowels`. (ie, after the function call `str` should not have any
   * vowels in it). You may assume there is enough space allocated in `vowels`.
   *
   * Look at the test case below for an example.
   */

  char *tmp1_str = str;
  char *tmp2_str = str;
  char *tmp_vowels = vowels;
  int len_str = string_len(str);

  char *copy_str = (char*)calloc(len_str+1,sizeof(char));
  char* head_copy_str = copy_str;
  while(*tmp1_str!='\0'){
    *copy_str = *tmp1_str;
    copy_str++;
    tmp1_str++;
  }
  *copy_str = '\0';
  
  while(*head_copy_str!='\0'){
    if(check_vowel(*head_copy_str) == 0){
      *tmp2_str = *head_copy_str;
      tmp2_str++;
      head_copy_str++;
    }
    else{
      *tmp_vowels = *head_copy_str;
      head_copy_str++;
      tmp_vowels++;
    }
  }
  *tmp2_str='\0';
  *tmp_vowels = '\0';
  free(head_copy_str);
}
    

// ----------------------------------------------------------------------------

// Do not change the lines above and below the main function. These
// are here to ensure that the main() function defined here does not
// Conflict with the automarker when testing your code. Changing them
// will result in a 0 for this exercise. You are free to change anything
// inside the main() function itself.
#ifndef __testing__
int main()
{
  char my_str[MAX_STRING_LEN] = "many many people have many many hobbies";
  char *res = find_last_substring(my_str, "many");
  if (res - my_str == 27)
  {
    printf("- find_last_substring() returned the correct result!\n");
  }
  else
  {
    printf("! find_last_substring() did not work properly.\n");
  }

  printf("----------------------------------------------------------------\n");

  char str[MAX_STRING_LEN] = "This sentence has many vowels! AEIOU";
  char vowels[MAX_STRING_LEN];
  split_vowels(str, vowels);

  printf("(Expected Result) str: \"Ths sntnc hs mny vwls! \", "
         "vowels: \"ieeeaaoeAEIOU\"\n");
  printf("(Your Solution) str: \"%s\", vowels: \"%s\"\n", str, vowels);
}
#endif
