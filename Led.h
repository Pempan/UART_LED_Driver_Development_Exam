/*Denna kod är en inkluderingsfil (header) för en LED-klass.*/

#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "UART.h" // Inkluderar en annan fil med namnet 'UART.h'.
#include "stm32f4xx.h" //Device Header för enhetsspecifika angivelser om hårdvaran

//Definera vilken GPIO som skall vara ansvarig för LED-funktionen
#define LED_PORT GPIOB // Definerar också också symbolen 'LED_PORT' som motsvarar GPIO porten 'GPIOB'. Betyder att LED-lamporna är anslutna till denna GPIO-port.

//Definerar klocksignalen för porten
#define LED_PORT_CLOCK (1U<<1) // '(1U<<1) är en bitförskjutning som ställer in den andra biten (från höger) till 1.

//Definera de olika pinsen för de olika LED-färgerna
#define LED_RED_PIN (1U<<14)  //'(1U<<14)' är en bitförskjutning som ställer in den fjortonde biten till 1. Räknat från höger.
#define LED_GREEN_PIN (1U<<12) //'(1U<<12)' är en bitförskjutning som ställer in den tolfte biten till 1. Räknat från höger.
#define LED_BLUE_PIN (1U<<15) //'(1U<<15)' är en bitförskjutning som ställer in den femtonde biten till 1. Räknat från höger.
#define LED_YELLOW_PIN (1U<<13) //'(1U<<13)' är en bitförskjutning som ställer in den trettonde biten till 1. Räknat från höger.

//Definera mode bits för varje LED-färg
#define LED_RED_MODE_BIT (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

//Definerar de olika LED-färgerna som finns
typedef enum {
  RED = 0,
  GREEN,
  YELLOW,
  BLUE
}LedColor_Type;

//Definerar ju / numrerar de olika lägena som LED kan befinna sig i. Denna typ används för att representera olika tillstånd för en LED. av eller på.
typedef enum { 
  OFF = 0,
  ON = 1
}LedState_Type;

// Definerar de attribut som LED består utav
class Led{

  private:
      LedColor_Type color; //Deklarerar ett privat attribut.
      LedState_Type state; //Deklarerar ett privat attribut.

  public: 

      Led(LedColor_Type _color,LedState_Type _state); // Konstruktor för klassen 'Led'. Tar emot två parametrar. 'Color' och 'state'. Konstruktorn används för att skapa en ny instans av 'Led'-objektet och sätter färgen och tillståndet för LED:n.
      void setState(LedState_Type _state); //En funktion som inte returnerar något värde. Funktionen tar emoy parameter '_state' av typen 'LedState_Type' och används för att ändra tillståndet för LED:n till det angivna tillståndet.
      LedState_Type getState() const; // Detta är en funktion som returnerar en 'LedState_Type'. Funktionen används för att hämta det aktuella tillståndet för LED:n.

};

#endif // Avslutar inkluderingsfilen och matchar '#ifndef' från början av filen.