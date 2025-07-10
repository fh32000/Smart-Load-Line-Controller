<template>
  <div class="status-view">
    <div class="grid grid-cols-1 lg:grid-cols-3 gap-6">
      <!-- System Status -->
      <div class="lg:col-span-2">
        <div class="bg-white rounded-lg shadow-sm p-6 mb-6">
          <h2 class="text-xl font-semibold mb-6 text-gray-900">حالة النظام</h2>
          
          <div class="space-y-6">
            <!-- Battery Status -->
            <div>
              <div class="flex justify-between items-center mb-2">
                <h3 class="text-sm font-medium text-gray-500">حالة البطارية</h3>
                <span class="text-sm font-medium" :class="batteryStatus.class">
                  {{ batteryStatus.text }}
                </span>
              </div>
              <div class="w-full bg-gray-200 rounded-full h-2.5">
                <div 
                  class="bg-blue-600 h-2.5 rounded-full" 
                  :style="{ width: batteryLevel + '%' }"
                ></div>
              </div>
              <div class="flex justify-between mt-1">
                <span class="text-xs text-gray-500">0%</span>
                <span class="text-xs text-gray-500">100%</span>
              </div>
              <div class="mt-2 text-right">
                <span class="text-2xl font-bold">{{ batteryVoltage }}V</span>
                <span class="text-sm text-gray-500 mr-1">الجهد الحالي</span>
              </div>
            </div>

            <!-- Load Status -->
            <div class="pt-4 border-t border-gray-100">
              <h3 class="text-sm font-medium text-gray-500 mb-4">حالة الحمل</h3>
              <div class="grid grid-cols-2 gap-4">
                <div class="bg-gray-50 p-4 rounded-lg">
                  <p class="text-sm text-gray-500 mb-1">الحمل الرئيسي</p>
                  <div class="flex items-center">
                    <span 
                      class="w-3 h-3 rounded-full mr-2"
                      :class="mainLoad ? 'bg-green-500' : 'bg-gray-300'"
                    ></span>
                    <span class="font-medium">{{ mainLoad ? 'قيد التشغيل' : 'متوقف' }}</span>
                  </div>
                </div>
                <div class="bg-gray-50 p-4 rounded-lg">
                  <p class="text-sm text-gray-500 mb-1">حالة الاتصال</p>
                  <div class="flex items-center">
                    <span 
                      class="w-3 h-3 rounded-full mr-2"
                      :class="isConnected ? 'bg-green-500' : 'bg-red-500'"
                    ></span>
                    <span class="font-medium">{{ isConnected ? 'متصل' : 'غير متصل' }}</span>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>

        <!-- System Logs -->
        <div class="bg-white rounded-lg shadow-sm p-6">
          <div class="flex justify-between items-center mb-4">
            <h2 class="text-xl font-semibold text-gray-900">سجل النظام</h2>
            <button class="text-sm text-blue-600 hover:text-blue-800">عرض الكل</button>
          </div>
          
          <div class="space-y-4">
            <div v-for="(log, index) in systemLogs" :key="index" class="flex items-start pb-3 border-b border-gray-100 last:border-0">
              <span class="material-icons-outlined text-gray-400 text-lg mt-0.5 ml-2">circle_notifications</span>
              <div class="flex-1">
                <p class="text-sm text-gray-800">{{ log.message }}</p>
                <p class="text-xs text-gray-400 mt-1">{{ log.time }}</p>
              </div>
            </div>
          </div>
        </div>
      </div>

      <!-- System Info -->
      <div>
        <div class="bg-white rounded-lg shadow-sm p-6 sticky top-6">
          <h2 class="text-xl font-semibold mb-6 text-gray-900">معلومات النظام</h2>
          
          <div class="space-y-4">
            <div class="flex justify-between py-2 border-b border-gray-100">
              <span class="text-sm text-gray-500">إصدار البرنامج</span>
              <span class="text-sm font-medium">v1.0.0</span>
            </div>
            <div class="flex justify-between py-2 border-b border-gray-100">
              <span class="text-sm text-gray-500">وقت التشغيل</span>
              <span class="text-sm font-mono">12:45:32</span>
            </div>
            <div class="flex justify-between py-2 border-b border-gray-100">
              <span class="text-sm text-gray-500">آخر تحديث</span>
              <span class="text-sm">منذ دقيقتين</span>
            </div>
            <div class="flex justify-between py-2 border-b border-gray-100">
              <span class="text-sm text-gray-500">عنوان IP</span>
              <span class="text-sm font-mono">192.168.1.100</span>
            </div>
            <div class="flex justify-between py-2 border-b border-gray-100">
              <span class="text-sm text-gray-500">معرف الجهاز</span>
              <span class="text-sm font-mono truncate max-w-[150px]" title="ESP_AB12CD34">ESP_AB12CD34</span>
            </div>
            
            <div class="pt-4 mt-4 border-t border-gray-100">
              <h3 class="text-sm font-medium text-gray-500 mb-3">الذاكرة المستخدمة</h3>
              <div class="w-full bg-gray-200 rounded-full h-2.5 mb-1">
                <div class="bg-blue-600 h-2.5 rounded-full" style="width: 65%"></div>
              </div>
              <div class="flex justify-between text-xs text-gray-500">
                <span>65% مستخدم</span>
                <span>32KB / 80KB</span>
              </div>
            </div>
            
            <div class="pt-4 mt-4 border-t border-gray-100">
              <button class="w-full bg-blue-600 hover:bg-blue-700 text-white py-2 px-4 rounded-lg text-sm font-medium transition-colors">
                <span class="material-icons-outlined align-middle text-base ml-1">refresh</span>
                تحديث البيانات
              </button>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref, computed } from 'vue';

// Mock data - replace with real data from your API
const batteryVoltage = ref(12.6);
const mainLoad = ref(true);
const isConnected = ref(true);

const systemLogs = ref([
  { 
    message: 'تم تشغيل النظام بنجاح', 
    time: 'منذ ثانيتين' 
  },
  { 
    message: 'تم تحديث إعدادات النظام', 
    time: 'منذ 5 دقائق' 
  },
  { 
    message: 'تم اكتشاف انخفاض في جهد البطارية', 
    time: 'منذ 15 دقيقة' 
  },
  { 
    message: 'تم تفعيل وضع توفير الطاقة', 
    time: 'منذ 30 دقيقة' 
  },
]);

// Computed properties
const batteryLevel = computed(() => {
  // Simple calculation - adjust based on your battery specs
  const minVoltage = 10.5;
  const maxVoltage = 13.8;
  return Math.min(100, Math.max(0, (batteryVoltage.value - minVoltage) / (maxVoltage - minVoltage) * 100));
});

const batteryStatus = computed(() => {
  const level = batteryLevel.value;
  
  if (level > 75) return { text: 'ممتاز', class: 'text-green-600' };
  if (level > 50) return { text: 'جيد', class: 'text-blue-600' };
  if (level > 25) return { text: 'منخفض', class: 'text-yellow-600' };
  return { text: 'منخفض جداً', class: 'text-red-600' };
});
</script>
