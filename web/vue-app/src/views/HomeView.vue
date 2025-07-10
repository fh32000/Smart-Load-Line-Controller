<template>
  <div class="home">
    <!-- Hero Section -->
    <div class="bg-white rounded-lg shadow-sm p-6 mb-8">
      <div class="text-center">
        <h1 class="text-3xl font-bold text-gray-900 mb-4">مرحباً بك في نظام الخط الذكي للأحمال</h1>
        <p class="text-lg text-gray-600 max-w-3xl mx-auto">
          نظام متكامل لتحويل الإنفرترات القديمة إلى أنظمة ذكية لإدارة الأحمال، مع مراقبة مستمرة وجدولة ذكية.
        </p>
      </div>
    </div>

    <!-- Quick Stats -->
    <div class="grid grid-cols-1 md:grid-cols-3 gap-6 mb-8">
      <div class="bg-white rounded-lg shadow-sm p-6">
        <div class="flex items-center">
          <div class="p-3 rounded-full bg-blue-100 text-blue-600 mr-4">
            <span class="material-icons-outlined text-2xl">battery_charging_full</span>
          </div>
          <div>
            <p class="text-sm font-medium text-gray-500">جهد البطارية</p>
            <p class="text-2xl font-semibold">12.6 <span class="text-sm text-gray-500">فولت</span></p>
          </div>
        </div>
      </div>

      <div class="bg-white rounded-lg shadow-sm p-6">
        <div class="flex items-center">
          <div class="p-3 rounded-full bg-green-100 text-green-600 mr-4">
            <span class="material-icons-outlined text-2xl">power</span>
          </div>
          <div>
            <p class="text-sm font-medium text-gray-500">حالة الحمل</p>
            <p class="text-2xl font-semibold text-green-600">يعمل</p>
          </div>
        </div>
      </div>

      <div class="bg-white rounded-lg shadow-sm p-6">
        <div class="flex items-center">
          <div class="p-3 rounded-full bg-purple-100 text-purple-600 mr-4">
            <span class="material-icons-outlined text-2xl">update</span>
          </div>
          <div>
            <p class="text-sm font-medium text-gray-500">وقت التشغيل</p>
            <p class="text-2xl font-semibold">12:45:32</p>
          </div>
        </div>
      </div>
    </div>

    <!-- Features Section -->
    <div class="bg-white rounded-lg shadow-sm p-6">
      <h2 class="text-xl font-semibold mb-6 text-gray-900">مميزات النظام</h2>
      
      <div class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6">
        <div v-for="(feature, index) in features" :key="index" class="border border-gray-100 rounded-lg p-6 hover:shadow-md transition-shadow">
          <div class="text-blue-600 mb-4">
            <span class="material-icons-outlined text-4xl">{{ feature.icon }}</span>
          </div>
          <h3 class="text-lg font-medium text-gray-900 mb-2">{{ feature.title }}</h3>
          <p class="text-gray-600 text-sm">{{ feature.description }}</p>
        </div>
      </div>
    </div>
  </div>
</template>

<script setup>
const features = [
  {
    icon: 'wifi',
    title: 'مراقبة عن بعد',
    description: 'اتصال لاسلكي كامل مع واجهة ويب سهلة الاستخدام للتحكم عن بعد في النظام.'
  },
  {
    icon: 'battery_charging_full',
    title: 'حماية البطارية',
    description: 'حماية تلقائية للبطارية من التفريغ العميق مع إشعارات فورية.'
  },
  {
    icon: 'schedule',
    title: 'جدولة ذكية',
    description: 'إمكانية جدولة تشغيل وإيقاف الأحمال تلقائياً حسب احتياجاتك.'
  },
  {
    icon: 'show_chart',
    title: 'تقارير وإحصائيات',
    description: 'متابعة أداء النظام مع رسوم بيانية وتقارير تفصيلية.'
  },
  {
    icon: 'security',
    title: 'حماية متقدمة',
    description: 'نظام حماية متكامل ضد التحميل الزائد، القصر والدوائر المفتوحة.'
  },
  {
    icon: 'update',
    title: 'تحديثات مستمرة',
    description: 'تحديثات برمجية مستمرة مع ميزات جديدة وتحسينات أداء.'
  }
];
</script>
