#define DSH_TOK_BUFSIZE 64
#define DSH_TOK_DELIM " \t\r\n\a"
char **dsh_split_line(char *line)
{
  int bufsize = DSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "dsh: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, DSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += DSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "dsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, DSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}
