import '@babel/polyfill'
import Vue from 'vue'
import App from './App.vue'
import router from '@router/index.js'
import fastclick from 'fastclick'

import '@common/scss/index.scss'

fastclick.attach(document.body)
Vue.config.productionTip = false

new Vue({
    render: h => h(App),
    router
}).$mount('#app')