import service from '@utils/http.js'

// achieve banner
export function getBanner() {
    return service.get('/banner')
}

// promise achieve hot disc
export function getHotDisc() {
    return service.get('/playlist/hot')
}