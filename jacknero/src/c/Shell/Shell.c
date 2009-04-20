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
  /* �Ԥμ����� */
  char *line = NULL;
  size_t len = 0;
  ssize_t length;
  char *p;

  /* exec���Ϥ���� */
  char *argv[256];
  int argc;

  prompt();
  while ((length = getline(&line, &len, stdin)) != -1) {
    if (length > 1) { /* ���ԤΤߤξ���̵�� */
      argc = 0;
      argv[argc++] = line;

      /* Ƨ���٤��ʤ���argv���� */
      for (p = line; *p != '\0'; p++) {
        if (*p == ' ') {
          *p = '\0';
          argv[argc++] = p + 1;
        } else if (*p == '\n') {
          *p = '\0';
          argv[argc] = NULL; /* ���Զ��ڤ� */
        }
      }

      if (fork() == 0) { /* �ҥץ��� */

        execvp(line, argv);

        /* ���顼�λ��Ϥ����� */
        fprintf(stderr, "��ư�Ǥ��ޤä���\n");
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


