void dsh_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = dsh_read_line();
    args = dsh_split_line(line);
    status = dsh_execute(args);

    free(line);
    free(args);
  } while (status);
}
