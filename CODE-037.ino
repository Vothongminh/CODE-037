//VTM channel
// Gọi thư viện DHT11
#include "DHT.h"
//Thêm thư viện LiquitCrystal - nó có sẵn vì vậy bạn không cần cài thêm gì cả
#include <LiquidCrystal.h>
//Khởi tạo với các chân
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int DHTPIN = 8;       //Đọc dữ liệu từ DHT11 ở chân 2 trên mạch Arduino
const int DHTTYPE = DHT11;  //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();         // Khởi động cảm biến
  //Thông báo đây là LCD 1602 
}
void loop() {
  float h = dht.readHumidity();    //Đọc độ ẩm
  float t = dht.readTemperature(); //Đọc nhiệt độ
  lcd.begin(16, 2);
  lcd.print("Nhiet do: ");
  lcd.print(t);
  lcd.setCursor(0, 1);
  // In ra dong chu
  lcd.print("Do am:   :");
  lcd.print(h);
}
