<template>
  <div class="settings-view">
    <div class="bg-white rounded-lg shadow-sm p-6">
      <h2 class="text-xl font-semibold mb-6 text-gray-900">إعدادات النظام</h2>
      
      <form @submit.prevent="saveSettings" class="space-y-8">
        <!-- Voltage Settings -->
        <div class="border-b border-gray-200 pb-8">
          <h3 class="text-lg font-medium text-gray-900 mb-4">إعدادات الجهد</h3>
          
          <div class="grid grid-cols-1 md:grid-cols-2 gap-6">
            <div>
              <label for="cutOffVoltage" class="block text-sm font-medium text-gray-700 mb-1">
                جهد قطع الحمل (فولت)
              </label>
              <div class="relative rounded-md shadow-sm">
                <input 
                  type="number" 
                  id="cutOffVoltage" 
                  v-model="settings.cutOffVoltage"
                  step="0.1"
                  min="10"
                  max="15"
                  class="focus:ring-blue-500 focus:border-blue-500 block w-full pr-12 sm:text-sm border-gray-300 rounded-md"
                >
                <div class="absolute inset-y-0 left-0 pl-3 flex items-center pointer-events-none">
                  <span class="text-gray-500 sm:text-sm">V</span>
                </div>
              </div>
              <p class="mt-1 text-xs text-gray-500">سيتم فصل الحمل عند انخفاض الجهد عن هذه القيمة</p>
            </div>
            
            <div>
              <label for="restoreVoltage" class="block text-sm font-medium text-gray-700 mb-1">
                جهد إعادة التشغيل (فولت)
              </label>
              <div class="relative rounded-md shadow-sm">
                <input 
                  type="number" 
                  id="restoreVoltage" 
                  v-model="settings.restoreVoltage"
                  step="0.1"
                  min="10"
                  max="15"
                  class="focus:ring-blue-500 focus:border-blue-500 block w-full pr-12 sm:text-sm border-gray-300 rounded-md"
                >
                <div class="absolute inset-y-0 left-0 pl-3 flex items-center pointer-events-none">
                  <span class="text-gray-500 sm:text-sm">V</span>
                </div>
              </div>
              <p class="mt-1 text-xs text-gray-500">سيتم إعادة تشغيل الحمل عند ارتفاع الجهد فوق هذه القيمة</p>
            </div>
          </div>
        </div>
        
        <!-- Timing Settings -->
        <div class="border-b border-gray-200 pb-8">
          <h3 class="text-lg font-medium text-gray-900 mb-4">إعدادات التوقيت</h3>
          
          <div class="grid grid-cols-1 md:grid-cols-2 gap-6">
            <div>
              <label for="cutOffDelay" class="block text-sm font-medium text-gray-700 mb-1">
                تأخير قطع الحمل (ثواني)
              </label>
              <input 
                type="number" 
                id="cutOffDelay" 
                v-model="settings.cutOffDelay"
                min="0"
                max="300"
                class="focus:ring-blue-500 focus:border-blue-500 block w-full sm:text-sm border-gray-300 rounded-md"
              >
              <p class="mt-1 text-xs text-gray-500">الوقت قبل قطع الحمل بعد انخفاض الجهد</p>
            </div>
            
            <div>
              <label for="restoreDelay" class="block text-sm font-medium text-gray-700 mb-1">
                تأخير إعادة التشغيل (ثواني)
              </label>
              <input 
                type="number" 
                id="restoreDelay" 
                v-model="settings.restoreDelay"
                min="0"
                max="300"
                class="focus:ring-blue-500 focus:border-blue-500 block w-full sm:text-sm border-gray-300 rounded-md"
              >
              <p class="mt-1 text-xs text-gray-500">الوقت قبل إعادة تشغيل الحمل بعد عودة الجهد</p>
            </div>
          </div>
        </div>
        
        <!-- Network Settings -->
        <div class="border-b border-gray-200 pb-8">
          <h3 class="text-lg font-medium text-gray-900 mb-4">إعدادات الشبكة</h3>
          
          <div class="space-y-4">
            <div>
              <label for="ssid" class="block text-sm font-medium text-gray-700 mb-1">
                اسم الشبكة (SSID)
              </label>
              <input 
                type="text" 
                id="ssid" 
                v-model="settings.network.ssid"
                class="focus:ring-blue-500 focus:border-blue-500 block w-full sm:text-sm border-gray-300 rounded-md"
              >
            </div>
            
            <div>
              <label for="password" class="block text-sm font-medium text-gray-700 mb-1">
                كلمة المرور
              </label>
              <input 
                type="password" 
                id="password" 
                v-model="settings.network.password"
                class="focus:ring-blue-500 focus:border-blue-500 block w-full sm:text-sm border-gray-300 rounded-md"
              >
            </div>
            
            <div class="grid grid-cols-1 md:grid-cols-2 gap-6">
              <div>
                <label for="ip" class="block text-sm font-medium text-gray-700 mb-1">
                  عنوان IP الثابت
                </label>
                <input 
                  type="text" 
                  id="ip" 
                  v-model="settings.network.ip"
                  placeholder="192.168.1.100"
                  class="focus:ring-blue-500 focus:border-blue-500 block w-full sm:text-sm border-gray-300 rounded-md"
                >
              </div>
              
              <div>
                <label for="subnet" class="block text-sm font-medium text-gray-700 mb-1">
                  قناع الشبكة الفرعية
                </label>
                <input 
                  type="text" 
                  id="subnet" 
                  v-model="settings.network.subnet"
                  placeholder="255.255.255.0"
                  class="focus:ring-blue-500 focus:border-blue-500 block w-full sm:text-sm border-gray-300 rounded-md"
                >
              </div>
            </div>
          </div>
        </div>
        
        <!-- Form Actions -->
        <div class="flex justify-end space-x-3">
          <button 
            type="button" 
            @click="resetToDefaults"
            class="bg-white py-2 px-4 border border-gray-300 rounded-md shadow-sm text-sm font-medium text-gray-700 hover:bg-gray-50 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500"
          >
            إعادة التعيين
          </button>
          
          <button 
            type="submit" 
            class="inline-flex justify-center py-2 px-4 border border-transparent shadow-sm text-sm font-medium rounded-md text-white bg-blue-600 hover:bg-blue-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-blue-500"
          >
            حفظ الإعدادات
          </button>
        </div>
      </form>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue';

// Default settings
const defaultSettings = {
  cutOffVoltage: 11.5,
  restoreVoltage: 12.5,
  cutOffDelay: 10,
  restoreDelay: 30,
  network: {
    ssid: '',
    password: '',
    ip: '192.168.1.100',
    subnet: '255.255.255.0',
    gateway: '192.168.1.1'
  }
};

// Current settings
const settings = ref(JSON.parse(JSON.stringify(defaultSettings)));

// Load settings from localStorage or use defaults
function loadSettings() {
  const savedSettings = localStorage.getItem('loadLineSettings');
  if (savedSettings) {
    try {
      settings.value = JSON.parse(savedSettings);
    } catch (e) {
      console.error('Failed to parse saved settings', e);
    }
  }
}

// Save settings to localStorage
function saveSettings() {
  try {
    localStorage.setItem('loadLineSettings', JSON.stringify(settings.value));
    alert('تم حفظ الإعدادات بنجاح');
  } catch (e) {
    console.error('Failed to save settings', e);
    alert('حدث خطأ أثناء حفظ الإعدادات');
  }
}

// Reset settings to defaults
function resetToDefaults() {
  if (confirm('هل أنت متأكد من إعادة تعيين جميع الإعدادات إلى القيم الافتراضية؟')) {
    settings.value = JSON.parse(JSON.stringify(defaultSettings));
    saveSettings();
  }
}

// Load settings when component is mounted
loadSettings();
</script>
