import Vue from 'vue'
import App from './App.vue'
import router from './router' // 引入路由
import '../dist/bootstrap.css'
import '../src/filter/index'
import '../src/config/config'

Vue.config.productionTip = false;

new Vue({
    router, // 加载router
    render: h => h(App),
}).$mount('#app')