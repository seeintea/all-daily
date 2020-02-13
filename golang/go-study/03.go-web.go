package main

import (
	"fmt"
	"net/http"
)

// 创建处理器函数
func handler(w http.ResponseWriter, r *http.Request)  {
	fmt.Fprintln(w, "测试HTTP协议")
}

func main() {
	// 点用处理器处理请求
	http.HandleFunc("/", handler)
	// 路由
	http.ListenAndServe(":8080", nil)
}