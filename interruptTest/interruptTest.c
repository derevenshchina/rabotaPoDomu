/*
 * interruptTest.c:
 * Use wiringPiISR() to trigger something to happen on a logic level
 * state change.
 * 
 * derived from isr.c from wiringPi
 */ 

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>

/* globalCounter:
 * Global var to count interrupts
 * Needs to be declared as volatile to make sure the compiler doesn't cache it.
 */

static volatile int globalCounter[8];

/*
 * myInterrupt:
 ************************************************
 * This is the new thread that eventually will do fun things
 * but for now it just increments the counter
 */

void myInterrupt0 (void) { ++globalCounter [0] ;}
void myInterrupt1 (void) { ++globalCounter [1] ;}
void myInterrupt2 (void) { ++globalCounter [2] ;}
void myInterrupt3 (void) { ++globalCounter [3] ;}
void myInterrupt4 (void) { ++globalCounter [4] ;}
void myInterrupt5 (void) { ++globalCounter [5] ;}

/* 
 * main:
 ************************************************
 * main routine
 */

int main (void)
{
   int gotOne, pin;
   myCounter[8];

   for (pin = 0; pin <6; pin++)
      /* Initialize to zero */
      globalCounter[pin] = myCounter[pin] = 0;   

   /* Mandidtory call to wiringPiSetup */
   wiringPiSetup();

   /* calls to watch for interrupts */
   wiringPiISR(0, INT_EDGE_RISING, &myInterrupt0);
   /* Start with just one for now, will uncomment the rest later */
   wiringPiISR(1, INT_EDGE_RISING, &myInterrupt1);
   wiringPiISR(2, INT_EDGE_RISING, &myInterrupt2);
   wiringPiISR(3, INT_EDGE_RISING, &myInterrupt3);
   wiringPiISR(4, INT_EDGE_RISING, &myInterrupt4);
   wiringPiISR(5, INT_EDGE_RISING, &myInterrupt5);

   /* Set up some infinite for loops to look for 1 (one) interrupt */
   for (;;)
   {
      gotOne = 0;
      printf("Waiting for an interrupt ... "); fflush(stdout);

      for(;;)
      {
         for (pin = 0; pin < 6; pin++)
         {
            if (globalCounter[pin] != myCounter[pin])
            {
               printf(" Interrupt on pin %d: Counter: %5d\n", pin, globalCounter[pin]);
               myCounter[pin] = globalCounter[pin];
               gotOne++;
            }
         }
         if (gotOne != 0)
            break;
      }
   }

   return 0;
}

