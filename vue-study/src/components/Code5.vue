<template>
    <div style="margin-top: 50px;">
        <input type="button" value="To Do." @click="toggle()">
        <transition>
            <h3 v-if="flag">这是一个H3</h3>
        </transition>
        <hr />
        <input type="button" value="# 2 To Do." @click="flag1 = !flag1">
        <transition name="own">
            <h3 v-if="flag1">这是一个H4</h3>
        </transition>
    </div>
</template>

<script>
export default {
    name: 'Code5',
    data: () => {
        return {
            flag: true,
            flag1: true,
        }
    },
    methods: {
        toggle() {
            this.flag = !this.flag;
        }
    }
}
</script>

<style scoped>
/* 进入 和 离开 的状态 */
.v-enter,
.v-leave-to {
    opacity: 0;
    transform: translateX(150px);
}

/* 入场 和 离场 的时间段 */
.v-enter-active,
.v-leave-active {
    transition: all 1s ease;
}

/* 进入 和 离开 的状态 */
.own-enter,
.own-leave-to {
    opacity: 0;
    transform: translateX(-150px);
}

/* 入场 和 离场 的时间段 */
.own-enter-active,
.own-leave-active {
    transition: all 1s ease;
}
</style>