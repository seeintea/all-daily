<template>
    <div class='concert-button'>
        <nav-item v-for="item in items" :key="item.id" :classChoice="item.class" :addr= "item.add" :itemText="item.msg" ></nav-item>
    </div>
</template>

<script>

import navItem from './concertButtonItem'

export default {
    data: () => {
        return {
            items: [
                {id: 1, class: 'icon-singer', add: '/concert/singer', msg: '歌手'},
                {id: 2, class: 'icon-rank', add: '/concert/rank', msg: '排行'},
                {id: 3, class: 'icon-songList', add: '/concert/songList', msg: '分类歌单'},
                {id: 4, class: 'icon-broading', add: '/concert/broading', msg: '电台'},
                {id: 5, class: 'icon-listing', add: '/concert/listing', msg: '一起听'}
            ]
        }
    },
    components: {
        navItem
    }
}
</script>

<style lang="scss" scoped>
.concert-button {
    display: flex;
    justify-content: space-around;
    width: 100%;
    padding: 5px 0 10px;
}
</style>