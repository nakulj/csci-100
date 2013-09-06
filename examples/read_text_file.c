#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *read_file_to_string(char *filename)
{
	FILE *fp=fopen(filename,"r");
	int size, i;
	char *str;
	fseek(fp,0,SEEK_END);
	size=ftell(fp);
	printf("Byte count: %d\n",size);
	str=(char *)malloc(size+1);
	fseek(fp,0,SEEK_SET);
	for(i=0;i<size;i++) {
		str[i]=tolower((char)getc(fp));
	}
	str[i]=NULL;
	return str;
}



int main(int argc, char *argv[])
{
  char *text_buf;
  int i, num_targets;
  if(argc < 2){
    fprintf(stderr,"Usage: ./%s text_file\n", argv[0]);
    exit(1);
  }
  if(argc > 2){
    fprintf(stderr,"Error:  Too many arguments\n.");
    exit(1);
  }

  text_buf = read_file_to_string(argv[1]);
  printf("\nDone reading text file.  Contents are:\n\n");
  printf("%s",text_buf);
  free(text_buf);
  return 0;
}

