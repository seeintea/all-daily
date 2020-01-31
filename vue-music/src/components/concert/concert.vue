<template>
    <div>
        音乐馆
        <concert-button></concert-button>
    </div>
</template>

<script>

import { getBanner } from '@api/concert.js'
import concertButton from './button/concertButton'

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
        concertButton
    }

}
</script>