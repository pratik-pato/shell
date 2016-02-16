#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Search_in_File(FILE *fp, char *str)
{
  int line_num = 1;
  char temp[512];
  
  //gcc users
  //if((fp = fopen(fname, "r")) == NULL) {
  //return(-1);
  //}

  //Visual Studio users
  fp=fopen("cmdLst.txt", "r");
  if(fp==NULL)
    return(-1);
  else
    {
      while(fgets(temp, 512, fp) != NULL)
	{
	  //printf("%s\n",temp);
	  if((strstr(temp, str)) != NULL)
	    {
	    //printf("A match found on line: %d\n", line_num);
	    //printf("\n%s\n", temp);
	      return 0;
	    } 
	}
	  
	  //Close the file if still open.
      if(fp)
	{
	  fclose(fp);
	}
      return 1;
    }
}


int main()
{
  FILE *cmdFile;
  char *line,*cmd,*residue;
  line=(char*)malloc(sizeof(char)*100);
  if(line==NULL)
    {
      fprintf(stderr, "Usage: %s string delim subdelim\n");
      return -1;
    }
  else
    {
      scanf("%[^\n]%*c",line);
      //printf("%s\n",line);
      cmd=strtok_r(line," ",&residue);
      //printf("%s\n%s\n",cmd,residue);
      if(Search_in_File(cmdFile,cmd)==0)
	{
	  printf("Found");
	  return 0;
	}
      else
	{
	  printf("Not Found");
	  return 1;
	}
    }
  // return 0;
}
