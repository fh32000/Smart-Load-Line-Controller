/*
 * Smart Load Controller - Configuration
 * وحدة التحكم الذكية للحمل - ملف الإعدادات
 * 
 * This file contains all configurable parameters for the Smart Load Controller.
 * Adjust these values according to your specific requirements.
 * 
 * يحتوي هذا الملف على جميع المعلمات القابلة للتعديل لوحدة التحكم الذكية.
 * قم بتعديل هذه القيم وفقًا لمتطلباتك الخاصة.
 */

 #ifndef CONFIG_H
 #define CONFIG_H
 
 // بيانات الشبكة المنزلية
 #define WIFI_SSID     "اسم_شبكتك"
 #define WIFI_PASSWORD "كلمة_المرور"
 
 // إعدادات الشبكة الثابتة
 #define FIXED_IP_LAST_OCTET 66
 #define GATEWAY_LAST_OCTET  1
 #define SUBNET_MASK         IPAddress(255, 255, 255, 0)
 
 #endif
 