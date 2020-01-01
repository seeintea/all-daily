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
        <hr />
        <!-- 使用钩子函数 模拟小球 半场动画 -->
        <input type="button" value="# 3 To Do." @click="flag2 = !flag2">
        <transition name="bs"
            @before-enter = "beforeEnter"
            @enter = "enter"
            @after-enter = "afterEnter"
        >
            <div v-show="flag2" class="ball"></div>
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
            flag2: false,
        }
    },
    methods: {
        toggle() {
            this.flag = !this.flag;
        },
        // 动画钩子函数的第一个参数 表示要执行的DOM元素 原生的JS DOM 对象
        // document.getElenmetById('')
        beforeEnter(el) {
            //console.log(el);
            //动画开始之前的起始位置
            el.style.transform = 'translate(0,0)';
        },
        enter(el, done) {
            //console.log(el);
            //开始动画
            el.offsetWidth;   //强制页面刷新
            el.style.transform = 'translate(150px, 150px)';
            el.style.transition = 'all 3s ease';
            // 过渡哦完成立即执行 afterEnter()
            done();
        },
        afterEnter(el) {
            console.log(el);
            this.flag2 = !this.flag2;
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

.ball {
    width: 15px;
    height: 15px;
    border-radius: 50%;
    background: #b20000;
}

</style>