<template>
    <div>
        <input type="button" value="test" @click="myShow" />
        <h3>父子组件 子组建  - {{msg}} - {{ parentMsg }}</h3>
    </div>
</template>

<script>
export default {
    name: 'Code9',
    //子组件中 props 中所有的数据 均来自父组件
    //父组件传递过来的的属性 需要预先在 props 数组中定义
    //data 中的数据可读可写 props 中的数据只读
    props: ['parentMsg'],
    data: () => {
        return {
            msg: 'from child !',
            msg2: '++++传参！'
        }
    },
    methods: {
        myShow() {
            console.log("msg from myself !");
            //获取父组件传递的方法
            this.$emit('parentFunc');
            this.$emit('parentFun', this.msg2);
        }
    }
}
</script>

<style scoped>

</style>