package main

import (
	"fmt"
	"net/http"
)

// 处理器, 获取请求参数
func handler(w http.ResponseWriter, r *http.Request) {
	// 必须先解析表单
	/* 请求地址和form表单中有相同的参数，其值都会被获得
	   并且form中的参数值在请求地址参数的前面
	*/
	// r.ParseForm()
	// fmt.Fprintln(w, "请求参数有:", r.Form)
	// r.PostForm字段只支持 application/x-www-form-urlencoded 编码
	// fmt.Fprintln(w, "POST表单中的参数:", r.PostForm)
	// 快速获取请求参数
	fmt.Fprintln(w, "url中的参数值", r.FormValue("user"))
	fmt.Fprintln(w, "Form表单中的参数值", r.PostFormValue("ts_info"))
}

func main() {
	http.HandleFunc("/world", handler)
	http.ListenAndServe(":8082", nil)
}
