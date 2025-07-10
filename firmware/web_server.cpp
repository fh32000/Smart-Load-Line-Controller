/*
 * Smart Load Controller - Web Server
 * وحدة التحكم الذكية للحمل - خادم الويب
 * 
 * This module implements a web server to provide a user interface
 * and API for monitoring and controlling the device.
 * 
 * تقوم هذه الوحدة بتنفيذ خادم ويب لتوفير واجهة مستخدم
 * وواجهة برمجة تطبيقات لمراقبة جهازك والتحكم به.
 */

 #include <ESP8266WebServer.h>
 #include <FS.h>
 #include "web_server.h"
 
 ESP8266WebServer server(80);
 
 // معالجة الطلب إلى "/"
 void handleRoot() {
   if (SPIFFS.exists("/index.html")) {
     File file = SPIFFS.open("/index.html", "r");
     server.streamFile(file, "text/html");
     file.close();
   } else {
     server.send(500, "text/plain", "الملف غير موجود!");
   }
 }
 
 void setupWebServer() {
   server.on("/", handleRoot);
   server.begin();
 }
 
 void handleWebServer() {
   server.handleClient();
 }
 