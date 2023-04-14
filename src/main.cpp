#include <Arduino.h>
#define BLYNK_TEMPLATE_ID "TMPL6b9i2-sZ4"
#define BLYNK_TEMPLATE_NAME "suhomeNW"
#define BLYNK_AUTH_TOKEN "nHZcJc9TAiZw_8sn3i3XbPi8Zi62vzS-"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Surasak_2.4GHz";    // ชื่อ Wi-Fi ของคุณ
char pass[] = "suoneone"; // รหัสผ่านของ Wi-Fi ของคุณ
char auth[] = BLYNK_AUTH_TOKEN;
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
}

BLYNK_WRITE(V1) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw2: ");
  Serial.println(value);
}

BLYNK_WRITE(V2) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw3: ");
  Serial.println(value);
}

BLYNK_WRITE(V3) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw4: ");
  Serial.println(value);
}

BLYNK_WRITE(V4) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw5: ");
  Serial.println(value);
}

BLYNK_WRITE(V5) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw6: ");
  Serial.println(value);
}

BLYNK_WRITE(V6) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw7: ");
  Serial.println(value);
}

BLYNK_WRITE(V7) {  // เมื่อมีการส่งข้อมูลเข้ามาผ่าน Virtual Pin 1
  int value = param.asInt();  // รับค่าจาก Virtual Pin 1
  Serial.print("Value received Sw8: ");
  Serial.println(value);
}

void setup()
{
  Serial.begin(9600);
  search_wifi();
  delay(5000);
  //WiFi.begin(ssid,pass);
  /*
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi : "+String(WiFi.localIP()));
  */
  // เชื่อมต่อกับ Blynk
  Serial.println("Connecting to Bylnk 2.0 .....");
  Blynk.begin(auth,ssid,pass);
  while (Blynk.connect() != true) {
    // Wait until connected
    Serial.println(" wait blynk 2.0 ....");
  }

  //Serial.println("Connected to Blynk!");
  Serial.println("Connected to WiFi : "+String(WiFi.localIP()));
  Serial.println("connected blynk complete !!!");
}

void loop()
{
  // ใช้งาน Blynk
  Blynk.run();
}
