package main

import (
	"shopping/controller"
)

func main() {
	//处理器
	controller.HTTPHandle()
	//开启服务
	controller.HTTPServe()
}
