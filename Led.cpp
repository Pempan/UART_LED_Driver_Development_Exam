#include "LED.h" //Inkluderar header filen för att även denna fil skall känna till de olika LED-beteckningarna och funktioner

//Konstruktorn för LED-lamporna
Led::Led(LedColor_Type _color, LedState_Type _state) // Detta är implementationen av konstruktorn för klassen 'Led'. Den tar emot två parametrar: '_color' av typen 'LedColor_Type' och '_state' av typen 'LedState_Type'.
// Konstruktorn används för att skapa en ny instans av 'Led'-objektet och sätter färgen och tillståndet för LED.
{
//Från kodrad 7-68: I konstruktorn implementeras logiken för att konfigurera GPIO-pinnarna och sätta deras tillstånd beroende på LED-färg och status. För varje 'case' i switch-satsen
//motsvarande en specifik färg (RED, YELLOW, BLUE,RED).


  this->color = _color;
  this->state = _state;

  //Enablea klockan för LED-porten (GPIOB)
  RCC->AHB1ENR |= LED_PORT_CLOCK;

  //Konfigurera LED-pinsen baserad på deras färg och status
  switch(_color){

    case RED: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      if(this->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_RED_PIN;            
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){
        //Stänga på LED
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Stänga av LED
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;

  }


}

void Led::setState(LedState_Type _state){ // Detta är implementationen av 'setState'-funktionen för klassen 'Led'. Den tar emot en parameter '_state' av typen 'LedState_Type' och används för att ändra tillståndet för LED:n till det angivna tillståndet.
// Funktionen (från rad 78-138) implementerar liknande logik som i konstruktorn för att uppdatera tillståndet och konfigurationen för GPIO-pinnarna baserat på LED:n till det angivna tillståndet.


  //Sätta statusen av LED:n
  this->state = _state;

  //Kolla färgen på LED för att veta att korrekt LED manipuleras
  switch(this->color){

      //om LED Röd
    case RED:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN:
      //sätta pin till outputläge
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      //Om önskad status är ON
      if(this->state == ON){
        //Definerar pinensouput till aktiv
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        //Definerar pin output till inaktiv
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }

}

LedState_Type Led::getState(void)const{  // I 'getState'-funktionen implementeras en switch-sats som kontrollerar LED-färgen och returnerar det aktuella tillståndet för den specifika färgen.

  //Kontrollera färgen av den LED som efterfrågas, printa sedan statusen
  switch(this->color){

    case RED:
      break;

    case YELLOW:
      break;

    case BLUE:
      break;

    case GREEN:
      break;
  }
             //Returnerar LED-lampans status av vald färg
             return this->state;
}