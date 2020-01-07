<template>
  <div id="app">
    <!--  router-link  -->
    <!-- <router-link to="/11?id=10" tag="span">Code11 test</router-link> -->
    <router-link to="/11" tag="span">Code11 test</router-link>
    <hr />
    <router-link to="/10/10" tag="span">Code10 test</router-link>
    <hr />
    <!-- router-view 可以被 transition 包裹 -->
    <router-view></router-view>

    <!-- <router-view></router-view>
    <router-view name="left" ></router-view>
    <router-view name="right" ></router-view> -->
    <!-- 利用路由布局 -->
    <!-- {
        path: '/test',
        name: 'VueTest',
        component:  {
          'defaute' : com1,
          'left' : com2,
          'right': com3
        }
    } -->
  </div>
</template>

<script>
export default {
  name: 'app',
  components: {
  },
  watch: {
      // 监视路由
      // $route(to, from) {
      //     console.log(to.name);
      //     console.log("------"); 
      //     console.log(from);
      // }
  }
}

</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}
</style>
