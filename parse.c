#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line){
   char ** a = malloc(sizeof(char*) * 20);
   int i = 0;
   while (line != NULL){
     a[i] = line;
     strsep(&line, " ");
     i++;
   }
   return a;
}
int main(){
  char line[] = "ls -l";
  /*char line[100] = "wow-this-is-cool";
  char *s1 = line;
  printf("[%s]\n", strsep( &s1, "-" ));
  printf("[%s]\n", s1);*/
  char ** args = parse_args(line);
  execvp(args[0], args);
  return 0;
}
