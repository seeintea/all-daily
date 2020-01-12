<template>
    <div>
        <h3>这是父组件</h3>
        <code9 :parentMsg="msg" @parentFunc="show" @parentFun="show2"></code9>
        {{ msgFromSon }}
    </div>
</template>

<script>
import Code9 from './Code9.vue';

export default {
    name: 'Code8',
    data: () => {
        return {
            msg: 'form parent !',
            msgFromSon: 'from self',
        }
    },
    methods: {
        show() {
            console.log("show() from parent !");
        },
        show2(data) {
            console.log("show() from parent !" + data);
            //子组件向父组件传值
            this.msgFromSon = data;
        }
    },
    components:{
        Code9
    },
}
</script>

<style scoped>
div {
    margin: 10px;
}
</style>