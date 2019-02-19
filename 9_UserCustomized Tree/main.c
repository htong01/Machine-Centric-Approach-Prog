
#include "mon.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
  // This is the example code that was used to generate sample.mon
  // It could be written much more nicely using create_left and create_right


  Element z = { .name = "zebra", .left_child = NULL, .right_child = NULL };
  Element y = { .name = "yak", .left_child = NULL, .right_child = NULL };
  Element x = { .name = "xylophone", .left_child = NULL, .right_child = NULL };
  Element b = { .name = "baboon", .left_child = &x, .right_child = &y };
  Element a = { .name = "aardvark", .left_child = &b, .right_child = &z };


  FILE* f = fopen("sample.mon", "w");
  write_tree(f, &a);
  fclose(f);

  FILE* fp = fopen("sample.mon", "r");
  Element * p = load_tree(fp);
  fclose(fp);
  free(p);
}

