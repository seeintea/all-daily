<template>
    <div>
        <input type="button" value="To Do." @click="flag = !flag">
        <transition
            @before-enter = "beforeEnter"
            @enter = "enter"
            @after-enter = "afterEnter"
        >
            <div class="ball" v-show="flag"></div>
        </transition>
    </div>
</template>

<script>
export default {
    name: 'Code7',
    data: () => {
        return {
            flag: false,
        }
    },
    methods: {
        beforeEnter(el) {
            el.style.transform = 'translate(0, 0)';
        },
        enter(el, done) {
            el.offsetWidth;
            el.style.transform = 'translate(50px, 150px)';
            el.style.transition = 'all 1.5s ease';
            done();
        },
        afterEnter() {
            this.flag = !this.flag;
        }
    },
}
</script>

<style scoped>
div {
    margin: 3px;
}

.ball {
    width: 30px;
    height: 30px;
    border-radius: 50%;
    background: #b20000;
    margin: 3px;
}
</style>