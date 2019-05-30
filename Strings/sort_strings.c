// File: sort_strings.c
// Purpose: Sort an array of strings using bubblesort
// Written by: Lamiaa Dakir
// Date: March 25, 2019
#include <stdio.h>
#define MAX_LEN 22
#define NUM_STRINGS 10

int length(char *string);
int scompare(char *string1,char *string2);
void fixfgetstring(char *str);
void bubblesort(char * string);
void swap(char string1[], char string2[]);

int main(){
  char string[NUM_STRINGS][MAX_LEN]; //2D array to store the strings

  printf("Enter 10 strings, seperated by linefeed:\n");
  for(int i =0; i<NUM_STRINGS; i++)
    fgets(string+i, MAX_LEN, stdin); //prompt user for string

  bubblesort((char *) string); //Sort the strings

  printf("\nThe sorted array is:\n");
  for(int i =0; i<NUM_STRINGS; i++){
    fixfgetstring((char *)string); //fixes the length of the string
    printf("%s\n",string+i); //prints the sorted strings
  }
  return 0;
}

int length(char *string){
  int l = 0;
  while(*string != '\0'){
    l++;
    string++;
  }
  return l;
}//length()

int scompare(char *string1,char *string2){
  while(*string1 != '\0' || *string2 != '\0'){
    if(*string1 == *string2){
      string1++;
      string2++;
      continue;
    }
    else if(*string1 > *string2){
      return 1;
      break;
    }
    else if (*string1 < *string2){
      return -1;
      break;
    }
    return 0;
  }
} //scompare()

void fixfgetstring(char *str){
  while(*str != '\n'){
    str++;
  }
  *str = '\0';
}//fixfgetstring()

void bubblesort(char * string){
  for(int i = 0; i < (NUM_STRINGS - 1); i++) {
    for(int j = 0; j < (NUM_STRINGS - i - 1); j++) {
      if(scompare(string + j * MAX_LEN, string + (j + 1) * MAX_LEN)== 1) {
        swap(string + j * MAX_LEN, string + (j + 1) * MAX_LEN);
      } // end if
    } // end for
  } // end for
} //bubblesort()

//swap two strings by copying character by character
void swap(char string1[], char  string2[]) {
  char temp[MAX_LEN];

  for(int i = 0; i < MAX_LEN; i++){
    temp[i] = string1[i];
  }
  for(int i = 0; i < MAX_LEN; i++){
    string1[i] =string2[i];
  }
  for(int i = 0; i < MAX_LEN; i++){
    string2[i]=temp[i];
  }

} //swap()
