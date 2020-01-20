<template>
    <div>
        <router-link tag='div' to='/concert'>音乐馆</router-link>
        <router-link tag='div' to='/find'>发现</router-link>
        <router-link tag='div' to='/comment'>热评</router-link>
        <router-link tag='div' to='/mine'>我的</router-link>
        <i class="iconfont icon-concert-click"></i>
    </div>
</template>

<script>
export default {
    name: 'difNav'
}
</script>

<style lang="scss" scoped>
i {
    width: 100px;
    height: 100px;
}
</style>