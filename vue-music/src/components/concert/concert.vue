<template>
    <div>
        音乐馆
    </div>
</template>

<script>

import { getBannerAdr } from '@api/concert.js'

export default {
    name: 'concert',
    data: ()=>{
        return {
            bannerList: [],
        }
    },
    methods: {
        _getBannerAdr() {
            let data = getBannerAdr();
            console.log(data)
        }
    },
    created() {
        this._getBannerAdr();
    },
}
</script>