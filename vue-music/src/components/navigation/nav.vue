<template>
    <div class="navBar">
        <nav-item v-for="item in items" :key="item.id" :classChoice="item.class" :addr= "item.add" :itemText="item.msg" ></nav-item>
    </div>
</template>

<script>
import navItem from './navItem'

export default {
    name: 'difNav',
    data(){
        return {
            msg: 'icon-find',
            msg1: '',
            msg2: '!2345',
            items: [
                {id: 1, class: 'icon-concert', add: '/concert', msg: '音乐馆'},
                {id: 2, class: 'icon-find', add: '/find', msg: '发现'},
                {id: 3, class: 'icon-comment', add: '/comment', msg: '热评'},
                {id: 4, class: 'icon-mine', add: '/mine', msg: '我的'}
            ]
        }
    },
    components: {
        navItem
    }
}
</script>

<style lang="scss" scoped>
.navBar {
    display: flex;
    justify-content: space-around;
    position: fixed;
    width: 100%;
    background: #fff;
    bottom: 0;
    padding: 5px 0 10px;
    border-top: 1px solid #f2f2f2;
}
</style>