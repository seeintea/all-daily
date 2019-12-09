<template>
    <div class="bbn_bottom">
            <router-link to="/Find">发现</router-link>
            <router-link to="/Video">视频</router-link>
            <router-link to="/Mine">我的</router-link>
            <router-link to="/Country">云村</router-link>
            <router-link to="/Account">账号</router-link>
        <router-view />
    </div>
</template>

<style scoped>
.bbn_bottom {
    height: 2rem;
    width: 100%;
    background: #fff;
}
</style>