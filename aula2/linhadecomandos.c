#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAXARGS 100
typedef struct command {
  char *cmd;              // string apenas com o comando
  int argc;               // número de argumentos
  char *argv[MAXARGS+1];  // vector de argumentos do comando
} COMMAND;

COMMAND parse(char *linha);
void print_parse(COMMAND com);

int main() {
  char *linha;
  COMMAND com;

  while (1) {
    if ((linha = readline("my_prompt$ ")) == NULL)
      exit(0);
    if (strlen(linha) != 0) {
      add_history(linha);
      com = parse(linha);
      print_parse(com);
    }
    free(linha);
  }
}

COMMAND parse(char *linha) {
  COMMAND new;
  char *token;
  const char s[2] = " ";
  token = strtok(linha,s);
  new.cmd = token;
  new.argc = 0;
  for (int i=0; token != NULL; i++) {
    new.argv[new.argc]=token;
    new.argc++;
    token = strtok(NULL,s);
  }
  return new;
}

void print_parse(COMMAND com) {
  char *temp = "exit";
  if (*com.cmd == *temp) {
    exit(0);
  }
  printf("cmd: %s\n",com.cmd);
  printf("argc: %d\n",com.argc);
  for (int i=0; i < com.argc; i++) {
    printf("argv[%d]: %s\n",i,com.argv[i]);
  }
}
