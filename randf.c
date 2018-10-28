# include "rand.h"

int random_f(){
  int randfile = open("/dev/random",O_RDONLY);
  int x;
  unsigned int r = read(randfile,&x,sizeof(int));
  close(randfile);
  return x;
}
