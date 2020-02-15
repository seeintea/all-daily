<template>
    <div class="slider" ref="slider">
        <slot name="title"></slot>
        <div class="slider-group" ref="sliderGroup">
            <slot name="entity"></slot>
        </div>
    </div>
</template>

<script>

//import BScroll from 'better-scroll'

export default {
    mounted() {
        setTimeout(()=>{
            this._setImgWidth()
            this._initSlider()
        }, 20)

        // 刷新
        window.addEventListener("resize", ()=>{
			if(!this.slider){
				return
			} 
			this._setImgWidth();
		})
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
            } 
            this.$refs.sliderGroup.style.width = width + 'px ';
        },

        _initSlider () {
            // 左右滑动利用margin控制
            // 注意左右极限
            // 判断左右滑动
		},
    }
}
</script>

<style lang="scss" scoped>
.slider {
    padding: 0 10px;
    position: relative;
    .slider-group{
        display: flex;
        position: relative;
        margin: 5px 0 0 0;
        img {
            width: 100%;
            border-radius: 10px;
        }
        p {
            margin: 3px 0 0 0;
            font-size: 10px;
            text-overflow: -o-ellipsis-lastline;
            overflow: hidden;
            text-overflow: ellipsis;
            display: -webkit-box;
            -webkit-line-clamp: 2;
            line-clamp: 2;
            -webkit-box-orient: vertical;
        }
    }
}
</style>