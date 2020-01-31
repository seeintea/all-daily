import service from '@utils/http.js'

// achieve banner
export function getBanner() {
    return service.get('/banner')
}