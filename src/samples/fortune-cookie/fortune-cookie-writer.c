#include <stdio.h>

int main()
{
  FILE* file = fopen("/proc/fortune", "w"), *rfile = NULL;
  char* buffer = (char*) malloc(1024), *wbuffer = malloc(1024);
  int len = 1024;
  int written = 0, ret = 0;

  if (file == NULL)
  {
    printf("Could not open the file\n");
    return -1;
  }

  memset(wbuffer, 0, 1024);
  memcpy(wbuffer, "This is a test", strlen("This is a test") + 1);
  written = fwrite(wbuffer, 1, strlen(wbuffer) + 1, file);
  printf("Characters written = %d, buffer = %s\n", written, wbuffer);

  fclose(file);

  memset(buffer, 0, 1024);
  rfile = fopen("/proc/fortune", "rw");
  ret = fread(buffer, 1, len, rfile);
  printf("Characters read = %d, buffer = %s\n", ret, buffer);

  free(wbuffer);
  free(buffer);

  fclose(rfile);
  return 0;
}
