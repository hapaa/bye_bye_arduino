#include <avr/io.h>

void setDac(unit16_t value){
  unit8_t octet1, octet2;
  // Mettre CS à 0

  if(!channelA){
    octet1 |= (1<<7);
  }

  octet1 = (value >> 8) & 0xf;
  octet1 |= (1<<4);
  octet2 = value & 0xff;

  SPI_MasterTransmit(octet1);
  SPI_MasterTransmit(octet2);

  // Mettre CS à 1
  // Mettre LDAC à 0
  // Mettre LDAC à 1
}

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
  setDac(123);
}
