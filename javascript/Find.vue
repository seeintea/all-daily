<template>
  <div class="home">
    <bbnBottom></bbnBottom>
  </div>
</template>

<script lang="ts">
import { Component, Vue } from 'vue-property-decorator';
import bbnBottom from '@/components/common/bbnBotton.vue';

@Component({
  components: {
    bbnBottom,
  },
})
export default class Find extends Vue {}
</script>
