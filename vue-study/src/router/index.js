import Vue from 'vue';
import VueRouter from 'vue-router';
import Home from '../App.vue';

Vue.use(VueRouter);

const routes = [
    {
        path: '/',
        name: 'home',
        component: Home,
    },
    {
        path: '/1',
        name: 'Code2',
        component: () => import('../components/Code2.vue')
    },
    {
        path: '/test',
        name: 'VueTest',
        component: () => import('@/components/Test.vue')
    }
]

const router = new VueRouter({
    routes,
});

export default router;

