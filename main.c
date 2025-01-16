#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h" //sistemle ilgili k�t�phaneler
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"  //GPIO_PIN_X tan�mlamalar� i�in
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "lcd.h"    //LCD ba�l�k dosyas�

int main(void)
{
    // Sistemi ba�lat
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // LCD ilk ayarlar�n� yap
    lcdilkayarlar();
    lcdfonksiyonayarla(0, 1, 0); //4 bit mod , 2 sat�r , 5x8 karakter
    lcdtemizle();  // LCD'yi temizle

    // LCD'nin ilk sat�r ve s�tununa git
    lcdgit(0, 0); //1.sat�r,1.s�tun
    lcdkarakteryaz('A');
    lcdgit(0, 1);
    lcdkarakteryaz('x');

//    // LCD'nin ikinci sat�r ve ilk s�tununa git
//    lcdgit(1, 0);
//    lcdkarakteryaz('B');


    while(1){} // Sonsuz d�ng�

}




