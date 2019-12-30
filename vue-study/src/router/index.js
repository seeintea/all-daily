import Vue from 'vue';
import VueRouter from 'vue-router';
import Home from '../App.vue';

Vue.use(VueRouter);

const routes = [{
        path: '/',
        name: 'home',
        component: Home,
    },
    {
        path: '/1',
        name: 'Code2',
        component: () =>
            import ('../components/Code2.vue')
    },
    {
        path: '/2',
        name: 'Code3',
        component: () =>
            import ('../components/Code3.vue')
    },
    {
        path: '/3',
        name: 'Code4',
        component: () =>
            import ('../components/Code4.vue')
    },
    {
        path: '/test',
        name: 'VueTest',
        component: () =>
            import ('@/components/Test.vue')
    }
]

const router = new VueRouter({
    routes,
});

export default router;