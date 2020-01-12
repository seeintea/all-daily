<template>
    <div>
        <input type="text" v-model="firstName" />+
        <input type="text" v-model="lastName" />=
        <input type="text" v-model="fullName" />
        <hr/>
        <input type="text" v-model="firstName1" />+
        <input type="text" v-model="lastName2" />=
        <input type="text" v-model="fullName3" />
    </div>
</template>

<script>
export default {
    name: 'Code12',
    data: () => {
        return {
            firstName: '',
            lastName: '',
            fullName: '',
            firstName1: '',
            lastName2: '',
        }
    },
    methonds: {

    },
    // 监视 data 中的指定数据变化 然后处罚 watch 中的对应函数
    // 检测 非 DOM 元素
    watch: {
        firstName: function (newVal, oldVal){
            this.fullName = newVal + '-' + this.lastName;
            console.log(oldVal)
        },
        lastName: function(newVal){
            this.fullName = this.firstName + '-' + newVal;
        },
    },
    // 可以定义一些属性 叫做计算属性 
    //  func 中的 data 发生变化后 就会改变
    computed: {
        'fullName3': function() {
            return this.firstName1 + '-' + this.lastName2;
        }
    }
}
</script>