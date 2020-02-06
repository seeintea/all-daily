<template>
    <div class="slider" ref="slider">
        <div class="slider-group" ref="sliderGroup">
            <slot></slot>
        </div>
        <div class="dots"></div>
    </div>
</template>

<script>

import { addClass } from '@/utils/dom';
import BScroll from 'better-scroll';

export default {
    props: {
        loop: {
            type: Boolean,
            default: true
        },
         autoPlay: {
            type: Boolean, 
            default: true
        },
        interval: {
             type: Number,
             default: 3500
        }
    },
    mounted() {
        setTimeout(()=>{
			this._setSliderWidth();
			this._initSlider();
        }, 20)
    },
    methods: {
        _setSliderWidth() {
            this.children = this.$refs.sliderGroup.children;
            let width = 0;
            let sliderWidth = this.$refs.slider.clientWidth;
            for(let i=0; i<this.children.length; i++){
                let child = this.children[i]
                addClass(child, 'slider-item');
                child.style.width = sliderWidth + 'px';
                width += sliderWidth; 
                
            } 
            if(this.loop){
                width += 2*sliderWidth;
            }
            this.$refs.sliderGroup.style.width = width + 'px ';
        },
        _initSlider () {
          this.slider = new BScroll(this.$refs.slider, {
            scrollX: true,
            momentum: false,
            snap: {
              loop: this.loop,
              threshold: 0.3,
              speed: 400
            },
            snapSpeed: 400,
            bounce: false,
            stopPropagation: true,
            click: true
          })
        }
    }
}
</script>

<style lang="scss" scoped>
@import "@common/scss/variable";
.slider {
  min-height: 1px;
  position: relative;
  .slider-group {
    position: relative;
    overflow: hidden;
    white-space: nowrap;
    .slider-item {
      float: left;
      box-sizing: border-box;
      overflow: hidden;
      text-align: center;
      img {
        display: block;;
        width: 100%
      }
    }
  }
  .dots {
    position: absolute;
    right: 0;
    left: 0;
    bottom: 12px;
    text-align: center;
    // font-size: 0;
    .dot {
      display: inline-block;
      margin: 0 4px;
      width: 8px;
      height: 8px;
      border-radius: 50%;
      background: $color-text-l;
      &.active {
        border-radius: 5px;
        background: $color-highlight-background;
      }
    }
  }
}
</style>