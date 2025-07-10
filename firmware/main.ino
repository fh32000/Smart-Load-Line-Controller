/*
 * Smart Load Controller - Main Firmware
 * وحدة التحكم الذكية للحمل - البرنامج الرئيسي
 * 
 * This is the main entry point for the Smart Load Controller firmware.
 * It initializes all components and runs the main control loop.
 * 
 * هذا هو نقطة البداية الرئيسية لبرنامج وحدة التحكم الذكية.
 * يقوم بتهيئة جميع المكونات وتشغيل حلقة التحكم الرئيسية.
 */

 #include <ESP8266WiFi.h>
 #include <FS.h>
 #include "config.h"
 #include "web_server.h"
 
 void connectToWiFiWithFixedIP() {
   Serial.println("🔌 الاتصال بالشبكة مؤقتًا للحصول على IP تلقائي...");
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
   while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
   }
 
   IPAddress dhcpIP = WiFi.localIP();
   Serial.println("\n📡 حصلنا على IP من DHCP:");
   Serial.println(dhcpIP);
 
   byte a = dhcpIP[0];
   byte b = dhcpIP[1];
   byte c = dhcpIP[2];
 
   WiFi.disconnect();
   delay(1000);
 
   IPAddress local_IP(a, b, c, FIXED_IP_LAST_OCTET);
   IPAddress gateway(a, b, c, GATEWAY_LAST_OCTET);
 
   WiFi.config(local_IP, gateway, SUBNET_MASK);
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 
   while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
   }
 
   Serial.println("\n✅ الاتصال تم بنجاح");
   Serial.print("📎 IP الحالي: ");
   Serial.println(WiFi.localIP());
 }
 
 void setup() {
   Serial.begin(115200);
 
   // تهيئة نظام الملفات
   if (!SPIFFS.begin()) {
     Serial.println("❌ فشل في تهيئة SPIFFS");
     return;
   }
 
   connectToWiFiWithFixedIP();
   setupWebServer();
 }
 
 void loop() {
   handleWebServer();
 }
 