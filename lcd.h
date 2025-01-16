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

void lcdkomut(unsigned char); //0 la 255 aras�nda veri;
//rs=0
//d4 - d7 aras�nda veri yaz
//ve en a� kapat

void lcdkarakteryaz(unsigned char);
//rs=1
//d4 - d7 aras�nda veri yaz
//ve en a� kapat

void lcdilkayarlar();

//giri� kipini se� 00000001I/DS
//ekran a� kapa    0000001DCB
//kurs�r kayd�r    000001S/CR/L**

void lcdfonksiyonayarla(unsigned char DL, unsigned char N, unsigned char F); //DL,N,F
//DL=0/1
//N=0/1
//F=0/1

void lcdtemizle();
//rs=0
//d4 - d7 aras�nda veri yaz 01h
//ve en a� kapat

void lcdgit(unsigned char, unsigned char);
//1,5  1.sat�r 5.s�tun
//85 h

//2,7
//c7h


#endif /* LCD_H_ */
