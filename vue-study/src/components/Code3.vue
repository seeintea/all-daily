<template>
    <div>
        <p>生命周期DOME ... </p>
        <p id="m">{{ msg }}</p>
        <input type="button" value="msg update" @click="updateMsg" />
    </div>
</template>

<script>
export default {
    name: 'Code3',
    data: function() {
        return { 
            msg: 'ok',
        }
    },
    methods: {
        show() {
            console.log('do show func !');
        },
        updateMsg() {
            this.msg = 'no';
        }
    },
    beforeCreate() {
        // 生命周期函数 表示实例完全被创建之前执行
        //console.log(this.msg);
        //thus.show();
        //执行beforeCreate生命周期函数时 data 和 methods 中的数据还未初始化
    },
    created() {
        //this.show();
        //执行created生命周期函数时 data 和 methods 中的数据初始化完成
    },
    beforeMount() {
        //开始编译模版 执行Vue指令 将模版字符串渲染为内存中的DOM 但此时模版并未挂在到真正的页面中
        //console.log(document.getElementById('m'));
        //页面中的元素还未被替换 只是之前写的一些模版字符串
    },
    mounted() {
        //内存中的模版已经渲染到页面中了
        //实例创建期间最后一个生命周期函数 表示实例已经完全创建完成
        //操作页面中的DOM节点 最早在mounted中实现
        console.log(document.getElementById('m').innerText);
    },
    beforeUpdate() {
        //页面未更新 数据已经更新
        console.log('页面msg:' + document.getElementById('m').innerText);
        console.log('vm中msg:' + this.msg);
    },
    updated() {
        //页面重新渲染完成
        console.log('ed-页面msg:' + document.getElementById('m').innerText);
        console.log('ed-vm中msg:' + this.msg);
    },
    beforeDestroy() {
        //组件被完全被销毁前 所有 date 和 methods 尚可使用
    },
    destroyed() {
        //组件已经完全被销毁 所有 date 和 methods 不可使用
    },
}
</script>