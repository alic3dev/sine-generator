#include <stdlib.h>
#include <stdio.h>

#include "sine-generator.h"

#include "circles.h"

int main(int argc, char* argv[]) {
  double amplitude = 1;
  double precision = 100;
  unsigned short int waves = 2;

  if (argc > 1) {
    amplitude = (double) atof(argv[1]);
  }

  if (argc > 2) {
    precision = (double) atof(argv[2]);
  }

  if (argc > 3) {
    waves = (double) atoi(argv[3]);
  }

  precision = amplitude / precision;

  for (unsigned short w = 0; w < waves; w++) {
    unsigned char oddWave = w % 2;

    for (double i = -amplitude; i <= amplitude; i += precision) {
      double y = getYPoint((double) i, amplitude);

      if (oddWave) {
        printf("%f\n", -y);
      } else {
        printf("%f\n", y);
      }
    }
  }
  return 0;
}

