<template>
    <div>
        <h1>这是login组件</h1>
        <p>{{ msg }}</p>
    </div>
</template>

<script>
export default {
    name: 'login',
    data(){
        return {
            msg: 'test info !'
        }
    },
    methods: {
        show(){
            console.log('ok login!');
        }
    }
}
</script>