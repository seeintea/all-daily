package main

import (
	"fmt"
	"net/http"
)

// 处理器函数
func handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintln(w, "发送的请求地址为:", r.URL.Path)
	fmt.Fprintln(w, "发送请求地址后的查询字符串:", r.URL.RawQuery)
	fmt.Fprintln(w, "请求头中的所有信息:", r.Header)
	fmt.Fprintln(w, "获取请求头中的某一个信息:", r.Header["Accept-Encoding"])
	fmt.Fprintln(w, "获取请求头中的某一个信息的属性值:", r.Header.Get("Accept-Encoding"))
}

// 读取请求体
func reqHandler(w http.ResponseWriter, r *http.Request) {
	// 获取请求体内容长度
	len := r.ContentLength
	// 创建切片
	body := make([]byte, len)
	// 将请求体的内容读到body中
	r.Body.Read(body)
	//打印出
	fmt.Fprintln(w, "请求体中的内容:", string(body))
}

func main() {
	http.HandleFunc("/hello", handler)
	http.HandleFunc("/world", reqHandler)
	http.ListenAndServe(":8082", nil)
}
