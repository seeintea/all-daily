import Vue from 'vue'
import App from './App.vue'

// 引入 CSS 文件
import 'assets/css/base.css'
// 添加路由
import router from './router/index.js';

Vue.config.productionTip = false

new Vue({
    render: h => h(App),
    router
}).$mount('#app')