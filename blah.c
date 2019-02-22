
#include <stdint.h>

void write_synth(uint8_t data) {
  for (int i = 7; i >= 0; i--) {
  //for (int i = 0; i < 8; i++) {
    if((data>>i)&1) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
}

int main(void) {

write_synth(0xF0);

/*
int i=0;
for(i=7;i>=0;i--) {
  printf("%d\n",i);
}
*/
return 0;
}
