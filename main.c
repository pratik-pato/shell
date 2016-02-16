#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  char *line,*cmd,*residue;
  line=(char*)malloc(sizeof(char)*100);
  if(line==NULL)
    {
      fprintf(stderr, "Usage: %s string delim subdelim\n");
      exit(EXIT_FAILURE);
    }
  else
    {
      scanf("%[^\n]%*c",line);
      printf("%s\n",line);
      cmd=strtok_r(line," ",&residue);
      printf("%s\n%s\n",cmd,residue);
      checkValidCmd(cmd);
      exit(EXIT_SUCCESS);
    }
}
