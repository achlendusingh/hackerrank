#include<stdio.h>
int main()
{
    // char *arr[]="Hello";
    // for(int i=0;i<sizeof(arr);i++)
    // {
    //     printf("%s ",arr);
    // }
    //  printf("%s ",arr);
    char name[] = "Harry Potter";

  printf("%p\n", *name);     // Output: H
  printf("%p\n", *(name+1));   // Output: a
  printf("%p\n", *(name+2));   // Output: o
  printf("%p\n", *(name+3));   // Output: o
  printf("%p\n", *(name+4));   // Output: o
  printf("%p\n", *(name+11));   // Output: o

  char *namePtr;

  namePtr = name;
  printf("%c", *namePtr);     // Output: H
  printf("%c", *(namePtr+1));   // Output: a
  printf("%c", *(namePtr+90));   // Output: o
    return 0;
}