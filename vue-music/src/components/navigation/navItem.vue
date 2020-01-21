<template>
    <div class="nav-item" @click="sc">
        <i class="iconfont" :class="classChoice"></i>
        <router-link tag='div' to='/concert'>音乐馆</router-link>
    </div>
</template>

<script>
export default {
    name: 'navItem',
    props: ["classChoice","urlDir"],
    methods: {
        sc() {
            let ic = document.getElementsByTagName('i')[0];
            let x = ic.className+"-click";
            ic.className = x;            
        }
    }
}
</script>

<style lang="scss" scoped>
.nav-item {
    i {
        font-size: 32px;
    }
}
</style>