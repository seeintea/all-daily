<template>
    <div>
        <router-link tag='div' to='/find'>发现</router-link>
        <router-link tag='div' to='/comment'>热评</router-link>
        <router-link tag='div' to='/mine'>我的</router-link>
        <nav-item :classChoice="msg"></nav-item>
    </div>
</template>

<script>
import navItem from './navItem'

export default {
    name: 'difNav',
    data(){
        return {
            msg: 'icon-find',
        }
    },
    components: {
        navItem
    }
}
</script>

<style lang="scss" scoped>
i {
    width: 100px;
    height: 100px;
}
</style>