/*
  Function Declarations for builtin shell commands:
 */
int dsh_cd(char **args);
int dsh_help(char **args);
int dsh_exit(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
  "cd",
  "help",
  "exit"
};

int (*builtin_func[]) (char **) = {
  &dsh_cd,
  &dsh_help,
  &dsh_exit
};

int dsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
int dsh_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "dsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("dsh");
    }
  }
  return 1;
}

int dsh_help(char **args)
{
  int i;
  printf("David McFall's DSH\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < dsh_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

int dsh_exit(char **args)
{
  return 0;
}
