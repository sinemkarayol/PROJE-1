 /*
 * lcd.c
 *
 *  Created on: 5 Kas 2024
 *      Author: snmkr
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/gpio.c"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.c"
#include "lcd.h"


void otuzhexgonder()
{
    SysCtlDelay(10000000);
    //rs=0
    GPIOPinWrite(LCDPORT, RS , 0);
    //ayar yaz�ld�
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7 , 0x30); //30h g�nderdik
    //en a� kapa
    GPIOPinWrite(LCDPORT, E , 2);  //pin 1 i 2yle a��yorduk
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E , 0);
    //3kez 30h g�nder

}

void lcdkomut(unsigned char c) //0x07 geldi
{
    GPIOPinWrite(LCDPORT, RS , 0);
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7 , (c & 0xf0));
    GPIOPinWrite(LCDPORT, E , 2);  //pin 1 i 2yle a��yorduk
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E , 0);

    SysCtlDelay(1000);

    GPIOPinWrite(LCDPORT, RS , 0);
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7 , (c & 0x0f)<<4);
    GPIOPinWrite(LCDPORT, E , 2);  //pin 1 i 2yle a��yorduk
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E , 0);

    SysCtlDelay(1000);
}

void lcdilkayarlar()
{
  //portf_base_enable
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, 0xFF); //hepsi out  GPIO_PORTB_BASE=LCD_PORT
    otuzhexgonder();
    otuzhexgonder();
    otuzhexgonder();

    //ayarlar devam
    //lcd komut kullan
    //lcdkomut(0x07);  //

    lcdkomut(0x02);
}

void lcdfonksiyonayarla(unsigned char DL, unsigned char N, unsigned char F)
{
  //if n=�uysa
  //if dL=�uysa diye kendimn ayarla
    unsigned char cmd = 0x20; //fonksiyon set komutu ba�lang�c�

    if (DL) cmd |=  0x10 ; //DL: data length (0=4bit , 1=8bit)
    if (N) cmd |=  0x08 ; //N:display lines (0 = 1 sat�r , 1=2 sat�r)
    if(F) cmd |=  0x04 ; //F: font (0 = 5x8 , 1= 5x10)
    lcdkomut(cmd); //fonksiyon set komutunu g�nder
}

void lcdkarakteryaz(unsigned char c)
{ //buralarla u�ra�
    GPIOPinWrite(LCDPORT, RS , RS);  //3.y� tekrar rs yazd�k
    //�st 4 bit
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7 , (c & 0xf0));
    GPIOPinWrite(LCDPORT, E , 2);  //pin 1 i 2yle a��yorduk
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E , 0);
    SysCtlDelay(1000);

    //alt 4 bit
    //GPIOPinWrite(LCDPORT, RS , 1);
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7 , (c & 0x0f)<<4);
    GPIOPinWrite(LCDPORT, E , 2);  //pin 1 i 2yle a��yorduk
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E , 0);

    SysCtlDelay(1000);
}

void lcdtemizle()
{
    lcdkomut(0x01);
    SysCtlDelay(1000);
}

void lcdgit(unsigned char k , unsigned char m)
{
    unsigned char address;
    if(k==0) address = 0x80 + m; //1.sat�r
    else if (k==1) address = 0xC0 + m; //2.sat�r

    lcdkomut(address); //imleci belirli konuma g�t�rme komutu
}
