/*Denna kod har som syfte att inkludera en fil som innehåller definitionen av en LED (led.h), skapa tre
LED-objekt med olika tillstånd och färger, initiera UART-kommunikation, ändra tillståndet för en 
LED samt att frigöra minnet för en LED*/





#include "led.h" //Inkluderar "Led.h" filen, vilket kommer att ge tillgång till deklarationer och definitioner för LED-funktionalitet.

LedState_Type led1_state; // Deklarerar en variabel "led1_state" av typen LedState_Type" vilket antas vara en enum som representerar tillståndet för en LED.
LedState_Type led2_state; 
LedState_Type led3_state;

Led led1(RED, ON); // Skapar ett objekt av typen "Led" med namnet "led1" och initierar det med färgen "RÖD" 
//och tillståndet "ON". Detta kommer att innebära att en LED av röd färg kommer att skapas och slås på.

int main(void) {
   
    USART2_init(); // Initierar UART-kommunikationen genom att anropa funktionen, Initierar UART-kommunikationen genom att anropa funktionen.

    Led led2(BLUE, ON); //Skapar ett objekt av typen "Led" med namnet "Led2" och tillståndet till på.

    Led *led3 = new Led(YELLOW, ON); // Skapar en pekare 'led3' till ett LED-objekt genom att använda nyckelordet 'new'. Objektet skapas med färgen gul och tillståndet på.
    

    //Hämtar och sparar det aktuella tillståndet för led1
    led1_state = led1.getState(); 

    //Ändrar tillståndet för led1 till OFF
    led1.setState(OFF);

    // Rensar minnet för led3-objektet genom att ta bort det från heapen
    delete led3;

    while (1) {
        // Huvudloopen
    }
}







