<template>
  <div id="app">
    <dif-header></dif-header>
    <keep-alive>
          <router-view></router-view>
    </keep-alive>
    <navigation></navigation>
  </div>
</template>

<script>
import DifHeader from '@components/header/header'
import Navigation from '@components/navigation/nav'
export default {
  name: 'app',
  components: {
    DifHeader,
    Navigation
  }
}
</script>

<style lang="scss" scoped>

</style>
