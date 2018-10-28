# include "randf.h"

int random_num(){
  int randfile = open("/dev/random",O_RDONLY);
  int x;
  int r = read(randfile,&x,sizeof(int));
  close(randfile);
  return abs(x);
}
