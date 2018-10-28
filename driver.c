#include "rand.h"

int main() {
  printf("Generating random numbers:\n");
  int *output = calloc(10,sizeof(int));
  int *check = calloc(10,sizeof(int));
  
  for (int i = 0; i < 10; i++) {
    output[i] = rand_f();
    printf("random %d: %d\n", i, output[i]);
  }
  
  printf("------------------");
  
  printf("Writing numbers to file\n\n");
  int f = open("foo.txt", O_WRONLY | O_CREAT, S_IRWXU);
  if(f < 0){
    printf("open error: %s\n",strerror(errno));
  }
  int w = write(f, output, sizeof(int) * 10);
  if (w < 0) {
    printf("write error: %s\n", strerror(errno));
    return 0;
  }
  close(f);

  printf("------------------");
  
  printf("Reading numbers from file\n\n");
  int fd = open("foo.txt", O_RDONLY);
  if (fd < 0) {
    printf("open error: %s\n", strerror(errno));
  }
  read(fd,check, sizeof(int) * 10);
  
  printf("Checking randoms\n");
  for(int i = 0; i<10;i++){
    printf("random %d: %d \n",i,check[i]);
  }
  close(fd);
  return 0;
}
