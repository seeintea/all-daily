// 在 webpack 构建的项目中 使用 VUE 开发

// import Vue from 'vue' 导入的Vue包不完整 只提供 runtime-only 功能
// import Vue from '../node_modules/vue/dist/vue.js';
import Vue from 'vue' // 需要在 webpack.config.js 中额外配置

import login from '../src/login.vue'

let vm = new Vue({
    el: '#app',
    data: {
        msg: '123',
    },
    render: createElement => {
        return createElement(login)
    }
})