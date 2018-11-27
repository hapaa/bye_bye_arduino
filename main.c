#include <avr/io.h>



void SPI_MasterInit(void) {
  /* Set MOSI and SCK output, all others input */
  DDR_SPI = (1<<DDB3)|(1<<DDB5);
  /* Enable SPI, Master, set clock rate fck/16 */
  SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}


void SPI_MasterTransmit(char cData) {
  /* Start transmission */
  SPDR = cData;
  /* Wait for transmission complete */
  while(!(SPSR & (1<<SPIF)));
}


int main() {
  // Active et allume la broche PB5 (led)
  //DDRB |= _BV(PB5);
  //PORTB |= _BV(PB5);

  
  SPI_MasterInit();
  SPI_MasterTransmit('c');
}
