#include <Arduino.h>
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
#define BLYNK_TEMPLATE_ID "TMPL6b9i2-sZ4"
#define BLYNK_TEMPLATE_NAME "suhomeNW"
#define BLYNK_AUTH_TOKEN "nHZcJc9TAiZw_8sn3i3XbPi8Zi62vzS-" // Blynk Token
//#define LINE_TOKEN "S7fWR5EKIjyfagLQ4W8XigR4cZOuwVYI5yHkpvAXLS1"   // Line TOKEN

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


// กำหนดชื่อและ Token ของ Line Notify
const char* LINE_TOKEN = "S7fWR5EKIjyfagLQ4W8XigR4cZOuwVYI5yHkpvAXLS1";
const char* LINE_NAME = "ESP32";


char ssid[] = "SuOne_2.4";    // ชื่อ Wi-Fi ของคุณ
char pass[] = "suoneone"; // รหัสผ่านของ Wi-Fi ของคุณ
char auth[] = BLYNK_AUTH_TOKEN;
char ssid2[]="Suoneone_2.4GHz";
char pass2[]="Toyo@8635";

void search_wifi()
{
  Serial.println();
  Serial.println("Scanning for WiFi networks...");
  int numNetworks = WiFi.scanNetworks();
  if (numNetworks == 0) {
    Serial.println("No networks found");
  } else {
    Serial.print(numNetworks);
    Serial.println(" networks found");
    for (int i = 0; i < numNetworks; i++) {
      Serial.print(i+1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      delay(10);
    }
  }
  //delay(10000); // Wait 10 seconds before scanning again
}


BLYNK_WRITE(V0) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw1: ");
  Serial.println(value);
  if(value == 1)
    {
      digitalWrite(18,HIGH);
      Serial.println("18 Sw1 : on");
    } 
  if(value == 0)
  {
    digitalWrite(18,LOW);
    Serial.println("18 Sw1 : off");
  }
}

BLYNK_WRITE(V1) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw2: ");
  Serial.println(value);
  if(value == 1)
    {
      digitalWrite(19,HIGH);
      Serial.println("19 Sw2 : on");
    } 
  if(value == 0)
  {
    digitalWrite(19,LOW);
    Serial.println("19 Sw2 : off");
  }
}

BLYNK_WRITE(V2) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw3: ");
  Serial.println(value);
  if(value == 1)
    {
      digitalWrite(21,HIGH);
      Serial.println("21 Sw3 : on");
    } 
  if(value == 0)
  {
    digitalWrite(21,LOW);
    Serial.println("21 Sw3 : off");
  }
}

BLYNK_WRITE(V3) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw4: ");
  Serial.println(value);
  if(value == 1)
    {
      digitalWrite(22,HIGH);
      Serial.println("22 Sw4 : on");
    } 
  if(value == 0)
  {
    digitalWrite(22,LOW);
    Serial.println("22 Sw4 : off");
  }
}

BLYNK_WRITE(V4) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw5: ");
  Serial.println(value);
  if(value == 1)
    {
      digitalWrite(15,HIGH);
      Serial.println("15 Sw5 : on");
    } 
  if(value == 0)
  {
    digitalWrite(15,LOW);
    Serial.println("15 Sw5 : off");
  }
}

BLYNK_WRITE(V5) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw6: ");
  Serial.println(value);
  if(value == 1)
    {
      digitalWrite(2,HIGH);
      Serial.println("2 Sw6 : on");
    } 
  if(value == 0)
  {
    digitalWrite(2,LOW);
    Serial.println("2 Sw6 : off");
  }

}

BLYNK_WRITE(V6) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw7: ");
  Serial.println(value);
  if(value == 1)
    {
      digitalWrite(0,HIGH);
      Serial.println("0 Sw7 : on");
    } 
  if(value == 0)
  {
    digitalWrite(0,LOW);
    Serial.println("0 Sw7 : off");
  }
}

BLYNK_WRITE(V7) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw8: ");
  Serial.println(value);
  if(value == 1)
    {
      digitalWrite(4,HIGH);
      Serial.println("4 Sw8 : on");
    } 
  if(value == 0)
  {
    digitalWrite(4,LOW);
    Serial.println("4 Sw8 : off");
  }
}

void setup()
{
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable detector
  Serial.begin(9600);//18/19/21/22  15/2/0/4
  
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(21,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(0,OUTPUT);
  pinMode(4,OUTPUT);

  search_wifi();
  delay(5000);
  // เชื่อมต่อกับ Blynk
  Serial.println("Connecting to Bylnk 2.0 .....");
  Blynk.begin(auth,ssid,pass);
  while (Blynk.connect() != true) {
    // Wait until connected
    Serial.println(" wait blynk 2.0 ....");
  }


  //Serial.println("Connected to Blynk!");
  Serial.print("Connected to WiFi : ");
  Serial.println(WiFi.localIP());
  Serial.println("connected blynk complete !!!");
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);
  Blynk.syncVirtual(V6);
  Blynk.syncVirtual(V7);
  Serial.println("Sync value pin !!");



}

void loop()
{
  // ใช้งาน Blynk
  Blynk.run();
}
