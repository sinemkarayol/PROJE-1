/*
 * lcd.h
 *
 *  Created on: 5 Kas 2024
 *      Author: snmkr
 */

#ifndef LCD_H_
#define LCD_H_


#define LCDPORT                GPIO_PORTB_BASE
#define LCDPORTENABLE          SYSCTL_PERIPH_GPIOB
#define RS                     GPIO_PIN_0 //PORTB nin 0. pini
#define E                      GPIO_PIN_1

#define D4                     GPIO_PIN_4
#define D5                     GPIO_PIN_5
#define D6                     GPIO_PIN_6
#define D7                     GPIO_PIN_7

void lcdkomut(unsigned char); //0 la 255 arasýnda veri;
//rs=0
//d4 - d7 arasýnda veri yaz
//ve en aç kapat

void lcdkarakteryaz(unsigned char);
//rs=1
//d4 - d7 arasýnda veri yaz
//ve en aç kapat

void lcdilkayarlar();

//giriþ kipini seç 00000001I/DS
//ekran aç kapa    0000001DCB
//kursör kaydýr    000001S/CR/L**

void lcdfonksiyonayarla(unsigned char DL, unsigned char N, unsigned char F); //DL,N,F
//DL=0/1
//N=0/1
//F=0/1

void lcdtemizle();
//rs=0
//d4 - d7 arasýnda veri yaz 01h
//ve en aç kapat

void lcdgit(unsigned char, unsigned char);
//1,5  1.satýr 5.sütun
//85 h

//2,7
//c7h


#endif /* LCD_H_ */
