#include <avr/io.h>

int main() {
  // Active et allume la broche PB5 (led)
  DDRB |= _BV(PB5);
  PORTB |= _BV(PB5);
}
