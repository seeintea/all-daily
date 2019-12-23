import Vue from 'vue';
import VueRouter from 'vue-router';
import Home from '../App.vue';

import VueTest from '../components/Test.vue';

Vue.use(VueRouter);

const routes = [
    {
        path: '/',
        name: 'home',
        component: Home,
    },
    {
        path: '/test',
        name: 'VueTest',
        component: VueTest,
    }
]

const router = new VueRouter({
    routes,
});

export default router;