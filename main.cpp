#include <Arduino.h>
#include "serial.h"

void setup() {
  uart_init(); // Initiera UART
}

void loop() {
  uart_putstr("Hello, world!"); // Skriv ut en sträng över UART
  delay(1000); // Vänta i 1 sekund
}
