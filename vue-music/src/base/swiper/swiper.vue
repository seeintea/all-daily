<template>
  <div class="swiper-container" :class="swipeid">
      <div class="swiper-wrapper">
          <!-- 存放具体的轮播内容 -->
          <slot name ="swiper-con"></slot>
      </div>
      <!-- 分页器 -->
      <div :class="{'swiper-pagination':pagination}"></div>
  </div>
</template>

<script>
export default {
    name:'swiper',
    data: () => {
        return {

        }
    },
    props: {
        swipeid: {
            type: String,
            default: ""
        },
        effect: {
            type: String,
            default: "slide"
        },
        loop: {
            type: Boolean,
            default: false
        },
        direction: {
            type: String,
            default: "horizontal"
        },
        pagination: {
            type: Boolean,
            default: true
        },
        paginationType: {
            type: String,
            default: "bullets"
        },
        autoPlay: {
            type: Number,
            default: 3000
        }
    }
}
</script>