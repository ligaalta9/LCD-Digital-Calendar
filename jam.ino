#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h> 

// Inisialisasi LCD (Alamat 0x27, 16 kolom, 2 baris)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Inisialisasi DS1302 (CLK, DAT, RST)
virtuabotixRTC myRTC(5, 4, 2);

void setup() {
  lcd.init();
  lcd.backlight();

  // --- BAGIAN PENTING: SETTING WAKTU ---
  // Format: detik, menit, jam, hari_dalam_seminggu, tanggal, bulan, tahun
  // Contoh: Detik 00, Menit 10, Jam 08, Hari ke-3 (Rabu), Tanggal 4, Bulan 3, Tahun 2026
  // Hapus tanda "//" di bawah ini untuk mengatur waktu pertama kali, lalu Upload.
  
  myRTC.setDS1302Time(01, 50, 01, 3, 4, 3, 2026); 
}

void loop() {
  myRTC.updateTime();

  // Tampilkan Tanggal di Baris 1
  lcd.setCursor(0, 0);
  lcd.print("Tgl: ");
  if (myRTC.dayofmonth < 10) lcd.print("0");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  if (myRTC.month < 10) lcd.print("0");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);

  // Tampilkan Jam di Baris 2
  lcd.setCursor(0, 1);
  lcd.print("Jam: ");
  if (myRTC.hours < 10) lcd.print("0");
  lcd.print(myRTC.hours);
  lcd.print(":");
  if (myRTC.minutes < 10) lcd.print("0");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  if (myRTC.seconds < 10) lcd.print("0");
  lcd.print(myRTC.seconds);

  delay(1000);
}
