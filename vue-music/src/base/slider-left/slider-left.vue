<template>
    <div class="slider" ref="slider">
        <slot name="title"></slot>
        <div class="slider-group" ref="sliderGroup">
            <slot name="entity"></slot>
        </div>
    </div>
</template>

<script>

// import BScroll from 'better-scroll'

export default {
    mounted() {
        setTimeout(()=>{
            this._setImgWidth()
        }, 20)
    },
    methods:{
        _setImgWidth(){
            // 获取slider的宽度 ，自适应调整大小
            let width = 0;
            let sliderWidth = this.$refs.slider.clientWidth - 40;
            let itemWidth = sliderWidth/3 -10;
            this.children = this.$refs.sliderGroup.children;
            for(let i=0; i<this.children.length; i++){
                let child = this.children[i]
                child.style.width = itemWidth + 'px'
                child.style.marginRight = '10px'
                width += itemWidth + 10;
                // let childImg = child.getElementsByTagName("img")[0]
                // childImg.style.width = itemWidth + 'px';
                // width += itemWidth + 10; 
            } 
            this.$refs.sliderGroup.style.width = width + 'px ';
        }
    }
}
</script>

<style lang="scss" scoped>
.slider {
    padding: 0 10px;
    .slider-group{
        display: flex;
        img {
            width: 100%;
        }
        p {
            font-size: 9px;
        }
    }
}
</style>