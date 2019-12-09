<template>
  <div id="app">
      <bbnBottom></bbnBottom>
  </div>
</template>

<script lang="ts">
import { Component, Vue } from 'vue-property-decorator';
import bbnBottom from '@/components/common/bbnBottom.vue';

export default Vue.extend({
  components: {
    bbnBottom,
  },
});

</script>
