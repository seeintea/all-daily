<template>
    <div>
        <!-- 轮播图组件 -->
        <div v-if="banners.length" class="slider-warp">
            <slider>
                <div v-for="item in banners" :key="item.targetId">
                    <a :href="item.imageUrl">
                        <img :src="item.imageUrl">
                    </a>
                </div>
            </slider>
        </div>
        <!-- 导航按钮 -->
        <concert-button></concert-button>
        <!-- 滑动组件 -->
        <div v-if="hotDisc.length" class="slider-left-warp">
            <slider-left>
                <div slot="title">测试信息</div>
                <div slot="entity" v-for="item in hotDisc" :key="item.id">
                    <a :href="item.imageUrl">
                        <img :src="item.coverImgUrl">
                    </a>
                    <p>{{item.name}}</p>
                </div>
            </slider-left>
        </div>

    </div>
</template>

<script>

import { getBanner, getHotDisc } from '@api/concert.js'
import concertButton from './button/concertButton'
import slider from '@base/slider/slider'
import sliderLeft from '@base/slider-left/slider-left'

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
                this.hotDisc = res.data.playlists;
            })
        }
    },
    components: {
        concertButton,
        slider,
        sliderLeft
    }

}
</script>

<style lang="scss" scoped>
.slider-warp {
    overflow: hidden;
}
</style>