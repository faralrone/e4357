#include "mbed.h"
#include "C12832.h"
#include "Arial_9.h"
#include "Small_7.h"
#include "graphics.h"


C12832 lcd(p5, p7, p6, p8, p11);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);


int main()
{

    int j=0;
    while(true) 
    {   
        if ( j <= 3)
        {
            lcd.cls();
            lcd.set_font((unsigned char*) Arial_9);
            lcd.locate(0,3);
            lcd.printf("Hello.Final Project- K&J!!");

            lcd.locate(0,15);
            lcd.printf("Counting : %d",j);
            j++;
            wait(1.0);
        }
        else if (( j > 3) && (j <= 6))
        {
            lcd.cls();
            lcd.locate(0,3);
            lcd.printf("LCD Left to Right");

            lcd.locate(0,15);
            lcd.printf("Counting : %d",j);
            j++;
            wait(0.1);
            led4 = 0;
            led1 = 1;
            wait(0.1);
            led1 = 0;
            led2 = 1;
            wait(0.1);
            led2 = 0;
            led3 = 1;
            wait(0.1);
            led3 = 0;
            led4 = 1;
            wait(0.1);
        }
        else if (( j > 6) && (j <= 9))
        {
            lcd.cls();
            lcd.locate(0,3);
            lcd.printf("LED flashing ALL!!");

            lcd.locate(0,15);
            lcd.printf("Counting : %d",j);
            j++;
            led1 = 1;
            led2 = 1;
            led3 = 1;
            led4 = 1;
            wait(0.5);
            led1 = 0;
            led2 = 0;
            led3 = 0;
            led4 = 0;
            wait(0.5);
        }
        
        else if (( j > 9) && (j <= 12))
        {
            lcd.cls();
            lcd.locate(0,3);
            lcd.printf("LED Right to Left");

            lcd.locate(0,15);
            lcd.printf("Counting : %d",j);
            j++;
            wait(0.1);
            led1 = 0;
            led4 = 1;
            wait(0.1);
            led4 = 0;
            led3 = 1;
            wait(0.1);
            led3 = 0;
            led2 = 1;
            wait(0.1);
            led2 = 0;
            led1 = 1;
            wait(0.1);
        }
        else if (( j > 12) && (j <= 15))
        {
            lcd.cls();
            lcd.locate(0,3);
            lcd.printf("LED skiping");

            lcd.locate(0,15);
            lcd.printf("Counting : %d",j);
            j++;
            wait(0.2);
            led1 = 0;
            led4 = 1;
            wait(0.2);
            led4 = 0;
            led2 = 1;
            wait(0.2);
            led2 = 0;
            led3 = 1;
            wait(0.2);
            led3 = 0;
            led1 = 1;
            wait(0.2);
        }
        else if (( j > 15) && (j <= 18))
        {
            lcd.cls();
            lcd.locate(0,3);
            lcd.printf("LED flashing 2 at a time ");

            lcd.locate(0,15);
            lcd.printf("Counting : %d",j);
            j++;
            led1 = 1;
            led2 = 1;
            led3 = 0;
            led4 = 0;
            wait(0.5);
            led1 = 0;
            led2 = 0;
            led3 = 1;
            led4 = 1;
            wait(0.5);
        }
        else if (( j > 18) && (j <= 20))
        {
            int i,s;
            lcd.cls();
            lcd.set_font((unsigned char*) Arial_9);
            s = 3;
            lcd.print_bm(bitmTree,95,0);  // print chistmas tree
            lcd.copy_to_lcd(); 
            lcd.setmode(XOR);             // XOR - a second print will erase  
            for(i = -15; i < 75; ){     
                lcd.print_bm(bitmSan1,i,2);
                wait(0.1);
                lcd.copy_to_lcd();           // update lcd  
                lcd.print_bm(bitmSan1,i,2);  // erase
                i= i+s;
                lcd.print_bm(bitmSan2,i,2);  // print next
                wait(0.1);
                lcd.copy_to_lcd();           // update lcd   
                lcd.print_bm(bitmSan2,i,2);  // erase
                i= i+s;
                lcd.print_bm(bitmSan3,i,2);  // print next 
                wait(0.1);
                lcd.copy_to_lcd();           // update lcd
                lcd.print_bm(bitmSan3,i,2);  // erase
                i= i+s;
            }
            lcd.print_bm(bitmSan3,i,2);
            
            
            //lcd.set_auto_up(0);
            for(i=-20; i<5; i++){             // scrolling text
                lcd.locate(5,i);
                lcd.printf("Happy");
                lcd.locate(5,i+12);
                lcd.printf("Christmas");
                lcd.copy_to_lcd();
                lcd.locate(5,i);
                wait(0.05);
                lcd.printf("Happy");
                lcd.locate(5,i+12);
                lcd.printf("Christmas");
                lcd.copy_to_lcd();
                i=i+1;
            }  
            lcd.locate(5,i);
            lcd.printf("Happy");
            lcd.locate(5,i+12);
            lcd.printf("Christmas");
            lcd.copy_to_lcd();
            j++;
        } 
        if (j >= 20)
        {   
            
            lcd.cls();
            lcd.locate(0,3);
            lcd.printf("Replay?? ");
            wait(0.5);
            lcd.cls();
            lcd.locate(0,3);
            lcd.printf("You got it :) ");
            wait(0.8);
            j = 3;
        }
    }
}
