#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void prompt(void)
{
  printf("* ");
}

int main(void)
{
  /* 行の取得用 */
  char *line = NULL;
  size_t len = 0;
  ssize_t length;
  char *p;

  /* execに渡すやつ */
  char *argv[256];
  int argc;

  prompt();
  while ((length = getline(&line, &len, stdin)) != -1) {
    if (length > 1) { /* 改行のみの場合は無視 */
      argc = 0;
      argv[argc++] = line;

      /* 踏み潰しながらargvを作る */
      for (p = line; *p != '\0'; p++) {
        if (*p == ' ') {
          *p = '\0';
          argv[argc++] = p + 1;
        } else if (*p == '\n') {
          *p = '\0';
          argv[argc] = NULL; /* 改行区切り */
        }
      }

      if (fork() == 0) { /* 子プロセス */

        execvp(line, argv);

        /* エラーの時はここへ */
        fprintf(stderr, "起動できまっせん。\n");
        exit(EXIT_FAILURE);
      }

      wait(NULL);
    }
    prompt();
  }

  if (line)
    free(line);

  return EXIT_SUCCESS;
}


