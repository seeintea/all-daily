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

import { getBanner, getHotDisc } from '@api/concert.js'
import concertButton from './button/concertButton'
import slider from '@base/slider/slider'

export default {
    name: 'concert',
    data: ()=>{
        return {
            banners: [],
            hotDisc: [],
        }
    },
    created() {
        this._getBanner();
        this._getHotDisc();
    },
    methods: {
        _getBanner() {
            getBanner().then(res=>{
                this.banners = res.data.banners;
            })
        },
        _getHotDisc() {
            getHotDisc().then(res => {
                this.hotDisc = res.data.tags;
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