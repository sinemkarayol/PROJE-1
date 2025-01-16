#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h" //sistemle ilgili kütüphaneler
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"  //GPIO_PIN_X tanýmlamalarý için
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "lcd.h"    //LCD baþlýk dosyasý

int main(void)
{
    // Sistemi baþlat
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // LCD ilk ayarlarýný yap
    lcdilkayarlar();
    lcdfonksiyonayarla(0, 1, 0); //4 bit mod , 2 satýr , 5x8 karakter
    lcdtemizle();  // LCD'yi temizle

    // LCD'nin ilk satýr ve sütununa git
    lcdgit(0, 0); //1.satýr,1.sütun
    lcdkarakteryaz('A');
    lcdgit(0, 1);
    lcdkarakteryaz('x');

//    // LCD'nin ikinci satýr ve ilk sütununa git
//    lcdgit(1, 0);
//    lcdkarakteryaz('B');


    while(1){} // Sonsuz döngü

}




