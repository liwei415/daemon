#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int do_work()
{
  char *s = "Do something here!";
  FILE *fd;
  fd = fopen("daemon.txt", "a+");
  fwrite(s, strlen(s), 1, fd);
  fclose(fd);
  return 0;
}

int main()
{
  daemon(1,1); //0还是1按照实际需要来设置
  while (1) {
    do_work();
    sleep(1);
  }
}
