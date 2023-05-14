/*Dessa kodrader kan man sammanfatta med att de definierar och inkluderar en headerfil för UART-funktionalitet och relaterade funktioner samt inkluderar
 nödvändiga bibliotek och registerdefinitioner för att arbeta med STM32F4-hårdvaruplattformen.*/


#ifndef __UART_H
#define __UART_H

#include "stm32f4xx.h" // Inkluderar STM32F411x.h, vilket är en källkod och hänvisning för att arbeta med STM32F4-hårvaruplattformen. Det ger tillgång till deklarationer och definitioner för hårdvaru och registeradresser.
#include <stdio.h>

void USART2_Init(void); // Är en funktionsdeklaration för att initiera UART2-protokollet och dess komponenter. 
void test_setup(void); // En funktionsdeklaration för att utföra en testuppsättning.
#endif


