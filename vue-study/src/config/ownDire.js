import Vue from 'vue';

// 定义自定义指令
// 参数1: 指令名称 不需要加 v- 前缀 调用时 需要用 v-前缀
// 参数2: 是一个对象， 一些指令相关的钩子函数 在特定时间做一些操作
Vue.directive('focus', {

    // 以下钩子函数的第一个参数 都是被绑定的元素， 是一个元素 JS 对象 DOM

    // 每当指令绑定到元素上时 会立即执行 只执行一次
    bind: function() {
        // bind 时元素还未被渲染时执行，无法绑定
        //el.focus();
        console.log("el 未渲染之前！");
    },
    // 元素插入到 DOM 中时 会执行
    // 和 JS 行为相关的操作 放到 inserted 中执行
    inserted: function(el) {
        el.focus();
        console.log("el 插入父元素中！");
    },
    // VNode 更新时， 会执行，可能会更新多次
    update: function() {
        console.log("el 未更新之前！");
    }
});

Vue.directive('color', {
    // 样式 只要通过指令绑定到元素中 不管元素有没有插入到页面中
    //bind: function(el) {
    //    el.style.color = 'red';
    //}
    bind: function(el, binding) {
        el.style.color = binding.value;
        console.log(binding)
    }
})