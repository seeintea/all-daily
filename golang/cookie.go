package main

import (
	"fmt"
	"sync"
)

/*
session 设计管理
全局session管理器
保证sessionid 的全局唯一性
为每个客户关联一个session
session 的存储(可以存储到内存、文件、数据库等)
session 过期处理
*/

// define session manager
type Manager struct {
	cookieName  string
	lock        sync.Mutex
	provider    Provider
	maxLifeTime int64
}

func NewManger(provideName, cookieName string, maxLifeTIme int64) (*Manager, error) {
	provider, ok := provides[provideName]
	if !ok {
		return nil, fmt.Errorf("session: unknow provide %q (forgotten import?", provideName)
	}
	return &Manager{provider: provider, cookieName: cookieName, maxLifeTime: maxLifeTime}, nil
}

// Provider interface symbol session basic save
type Provider interface {
	SessionInit(sid string) (Session, error)
	SessionRead(sid string) (Session, error)
	SessionDestroy(sid string) error
	SessionGC(maxLifeTime int64)
}

//	Session interface basic func
type Session interface {
	Set(key, value interface{}) error
	Get(key interface{}) interface{}
	Delete(key interface{}) error
	SessionID() string
}

func main() {

}
