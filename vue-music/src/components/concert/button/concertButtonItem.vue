<template>
    <div class="concert-button-item" @click="toPath">
        <i class="iconfont" :class="classChoice"></i>
        <p>{{ itemText }}</p>
    </div>
</template>

<script>
export default {
    name: 'navItem',
    props: {
        addr: String,
        classChoice: String,
        itemText: String
    },
    methods: {
        toPath() {
            if(this.$route.path === this.addr) return;
            else this.$router.replace(this.addr);
        }
    }
}
</script>

<style lang="scss" scoped>
.concert-button-item {
    text-align: center;
    font-size: 14px;
    color: #22d59c;
    i {
        font-size: 30px;
        margin: 0 0 3px 0;
        display: inline-block;
    }
    p {
        color: #333;
    }
}
</style>