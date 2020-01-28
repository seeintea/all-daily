<template>
    <div>
        音乐馆
    </div>
</template>

<script>

export default {
    name: 'concert',
    created() {
        this.add();    
    },
    methods: {
        add(){
            console.log("!")
        },
    }
}
</script>