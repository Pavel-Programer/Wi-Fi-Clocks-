#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>
LCD_1602_RUS lcd(0x27, 16, 2);

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

const char *ssid = "Ssid-name"; //enter ssid here
const char *password = "Passward";  //enter passward here

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 10800, 60000);// Time sittings

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Соитие с WiFi:");
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  int num = 0;
  while (WiFi.status() != WL_CONNECTED) {
    lcd.setCursor(num, 1);
    delay(500);
    lcd.print(".");
    num++;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Текущее время:");
}

void loop(){
  timeClient.update();
  lcd.setCursor(3, 1);
  lcd.print(timeClient.getFormattedTime());
  delay(1000);
}






