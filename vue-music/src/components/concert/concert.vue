<template>
    <div>
        <div v-if="banners.length" class="slider-warp">
            <slider>
                <div v-for="item in banners" :key="item.targetId">
                    <a :href="item.imageUrl">
                        <img :src="item.imageUrl">
                    </a>
                </div>
            </slider>
        </div>
        <concert-button></concert-button>
    </div>
</template>

<script>

import { getBanner } from '@api/concert.js'
import concertButton from './button/concertButton'
import slider from '@base/slider/slider'

export default {
    name: 'concert',
    data: ()=>{
        return {
            banners: [],
        }
    },
    created() {
        this._getBanner();
    },
    methods: {
        _getBanner() {
            getBanner().then(res=>{
                this.banners = res.data.banners;
            })
        }
    },
    components: {
        concertButton,
        slider
    }

}
</script>

<style lang="scss" scoped>
.slider-warp {
    overflow: hidden;
}
</style>