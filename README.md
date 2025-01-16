# PROJE-1
LCD Ekran Kullanımı (Tiva C TM4C123)

Bu proje, Texas Instruments Tiva C TM4C123 serisi mikrodenetleyiciler ile bir LCD ekranın nasıl kullanılacağını göstermektedir. Kod, GPIO pinleri üzerinden LCD'ye veri göndererek temel fonksiyonları gerçekleştirmektedir.
Özellikler

4-bit modunda LCD kontrolü
Ekran temizleme, karakter yazma, imleç konumlandırma
Tiva C mikrodenetleyicisine özel GPIO pin atamaları
Delay kullanılarak zamanlama ayarları
Donanım Bağlantıları

LCD Pin ->Tiva C Bağlantısı
RS -> PB0
E -> PB1
D4->PB4
D5->PB5
D6->PB6
D7->PB7
Dosya Açıklamaları

main.c: Ana program dosyası, LCD başlatma ve temel işlemler içerir.
lcd.c: LCD'nin tüm fonksiyonları burada tanımlanmıştır.
lcd.h: LCD fonksiyon prototipleri ve tanımlamalar içerir.

Kullanılan Kütüphaneler
Kod, TivaWare sürücü kütüphanesini kullanmaktadır. TivaWare yüklenmiş olmalıdır.
driverlib/gpio.h
driverlib/sysctl.h
driverlib/interrupt.h
inc/hw_types.h
inc/hw_memmap.h
inc/hw_gpio.h

Kurulum ve Derleme
TivaWare Kurulumu: TivaWare Download
Code Composer Studio (CCS) veya Keil IDE kullanarak derleyin
Tiva C TM4C123 LaunchPad'e yükleyin
Bağlantıları yapın ve LCD üzerinde çıktıyı gözlemleyin
