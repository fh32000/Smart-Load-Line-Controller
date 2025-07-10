<template>
  <div class="min-h-screen flex flex-col rtl">
    <!-- Header -->
    <header class="bg-white shadow-sm">
      <div class="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
        <div class="flex justify-between h-16">
          <div class="flex items-center">
            <div class="flex-shrink-0 flex items-center">
              <span class="text-2xl font-bold text-blue-600">
                <span class="hidden md:inline">الخط الذكي للأحمال</span>
                <span class="md:hidden">SLLC</span>
              </span>
            </div>
            <nav class="hidden md:ml-6 md:flex space-x-reverse space-x-8">
              <router-link 
                v-for="item in navigation" 
                :key="item.name"
                :to="item.to"
                class="inline-flex items-center px-1 pt-1 border-b-2 text-sm font-medium"
                :class="[
                  $route.path === item.to 
                    ? 'border-blue-500 text-gray-900' 
                    : 'border-transparent text-gray-500 hover:border-gray-300 hover:text-gray-700'
                ]"
              >
                <span class="material-icons-outlined text-lg mr-1">{{ item.icon }}</span>
                {{ item.name }}
              </router-link>
            </nav>
          </div>
          <div class="hidden md:ml-4 md:flex-shrink-0 md:flex md:items-center">
            <span class="inline-flex items-center px-3 py-1 rounded-full text-sm font-medium bg-blue-100 text-blue-800">
              <span class="w-2 h-2 mr-1.5 rounded-full bg-blue-500"></span>
              متصل
            </span>
          </div>
          <!-- Mobile menu button -->
          <div class="-mr-2 flex items-center md:hidden">
            <button @click="isMenuOpen = !isMenuOpen" class="inline-flex items-center justify-center p-2 rounded-md text-gray-400 hover:text-gray-500 hover:bg-gray-100 focus:outline-none">
              <span class="material-icons-outlined">
                {{ isMenuOpen ? 'close' : 'menu' }}
              </span>
            </button>
          </div>
        </div>
      </div>

      <!-- Mobile menu -->
      <div v-if="isMenuOpen" class="md:hidden">
        <div class="pt-2 pb-3 space-y-1">
          <router-link
            v-for="item in navigation"
            :key="item.name"
            :to="item.to"
            class="block pl-3 pr-4 py-2 border-r-4 text-base font-medium"
            :class="[
              $route.path === item.to 
                ? 'border-blue-500 bg-blue-50 text-blue-700' 
                : 'border-transparent text-gray-600 hover:bg-gray-50 hover:border-gray-300 hover:text-gray-800'
            ]"
          >
            <div class="flex items-center">
              <span class="material-icons-outlined text-lg ml-2">{{ item.icon }}</span>
              {{ item.name }}
            </div>
          </router-link>
        </div>
      </div>
    </header>

    <!-- Main content -->
    <main class="flex-grow bg-gray-50">
      <div class="max-w-7xl mx-auto py-6 sm:px-6 lg:px-8">
        <router-view />
      </div>
    </main>

    <!-- Footer -->
    <footer class="bg-white border-t border-gray-200">
      <div class="max-w-7xl mx-auto py-4 px-4 sm:px-6 lg:px-8">
        <p class="text-center text-sm text-gray-500">
          &copy; {{ new Date().getFullYear() }} الخط الذكي للأحمال. جميع الحقوق محفوظة.
        </p>
      </div>
    </footer>
  </div>
</template>

<script setup>
import { ref } from 'vue';
import { useRoute } from 'vue-router';

const route = useRoute();
const isMenuOpen = ref(false);

const navigation = [
  { name: 'الرئيسية', to: '/', icon: 'home' },
  { name: 'حالة النظام', to: '/status', icon: 'speed' },
  { name: 'الإعدادات', to: '/settings', icon: 'settings' },
];
</script>

<style>
/* Material Icons */
@import url('https://fonts.googleapis.com/icon?family=Material+Icons+Outlined');

/* Base styles */
html {
  font-family: 'Tajawal', sans-serif;
}

/* Router link active state */
.router-link-exact-active {
  @apply border-blue-500 text-gray-900;
}

/* Custom scrollbar */
::-webkit-scrollbar {
  width: 8px;
  height: 8px;
}

::-webkit-scrollbar-track {
  @apply bg-gray-100;
}

::-webkit-scrollbar-thumb {
  @apply bg-gray-300 rounded-full;
}

::-webkit-scrollbar-thumb:hover {
  @apply bg-gray-400;
}
</style>
