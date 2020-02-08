package main

import (
	"fmt"
	"net/http"
	"time"
)

// MyHandler 自定义处理器
type MyHandler struct{}

func (m *MyHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintln(w, "通过自己创建的处理器处理请求！")
}

func main() {

	myHandler := MyHandler{}

	// 通过 Server 结构体对服务器进行详细设计
	server := http.Server{
		Addr:              ":8080",
		Handler:           &myHandler,
		ReadHeaderTimeout: 2 * time.Second,
	}

	// http.Handle("/myHandler", &myHandler)
	// http.ListenAndServe(":8080", nil)
	server.ListenAndServe()
}
