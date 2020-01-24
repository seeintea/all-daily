<template>
    <div class="nav-item" @click="toPath" :class="{ change: active }">
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
    data() {
        return {
            active: true
        }
    },
    watch: {
        // 检测路由变化
        $route(to){
            if(to.path == this.addr){
                this.active = true;
            }else {
                this.active = false;
            }
        }
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
.nav-item {
    text-align: center;
    font-size: 14px;
    i {
        font-size: 30px;
        margin: 0 0 5px 0;
        display: inline-block;
    }
}

.change {
    color: #22d59c;
}
</style>