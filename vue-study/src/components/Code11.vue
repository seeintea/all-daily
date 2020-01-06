<template>
    <div>
        <input type="button" value="achieveElement" class="btn-primary" @click="getElement" />
        <h3 id="myh3" ref="myRef">Text test ... </h3>
        <hr />
        <comp1 ref="myComp1"></comp1>
        <router-view></router-view>
        <router-link to="/11/test1">Test Component !</router-link>
    </div>
</template>

<script>
import Comp1 from './Comp1';

export default {
    name: 'Code11',
    data: () => {
        return {

        }
    },
    methods: {
        getElement() {
            // console.log(document.getElementById('myh3').innerText);
            console.log(this.$refs.myRef.innerText);
            console.log(this.$refs.myComp1.msg);
            
        }
    },
    components: {
        Comp1
    },
    created() {
        console.log(this.$route);
        console.log(this.$route.query.id)
    },
}
</script>

<style scoped>

</style>