#include <stdio.h>
#include <string.h>
#define SIZE 20

int main() {
  FILE *file = fopen("output.txt", "w");

  if (file == NULL) {
    printf("can't open file\n");
    return -1;
  }

  char str[] = "String from file";
  fprintf(file, "%s", str);
  fclose(file);

  file = fopen("output.txt", "r");

  if (file == NULL) {
    printf("can't open file\n");
    return -1;
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  
  char c;
  for(long i = size - 1; i >= 0; i--) {
    fseek(file, i, SEEK_SET);
    c = fgetc(file);
    printf("%c", c);
  }
  printf("\n");
  
  fclose(file);

  return 0;
}