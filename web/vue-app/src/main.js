import { createApp } from 'vue'
import { createRouter, createWebHistory } from 'vue-router'
import './assets/main.css'
import App from './App.vue'
import HomeView from './views/HomeView.vue'
import SettingsView from './views/SettingsView.vue'
import StatusView from './views/StatusView.vue'

// Create router instance
const router = createRouter({
  history: createWebHistory(),
  routes: [
    { path: '/', component: HomeView },
    { path: '/settings', component: SettingsView },
    { path: '/status', component: StatusView }
  ]
})

// Create and mount the app
const app = createApp(App)
app.use(router)
app.mount('#app')
