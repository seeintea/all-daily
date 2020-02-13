package main

import (
	"encoding/json"
	"net/http"
)

// User user结构体
type User struct {
	ID       int
	UserName string
	PassWord string
	Email    string
}

// 发送 JSON 报文
func testJSONRes(w http.ResponseWriter, r *http.Request) {
	// 设置响应类型
	w.Header().Set("Content-Type", "application/json")
	// 创建User
	user := User{
		ID:       123,
		UserName: "glw",
		PassWord: "123456",
		Email:    "1821414u@qq.com",
	}
	// 将 User 转为 JSON
	json, _ := json.Marshal(user)
	// 将 json 数据响应给客户端
	w.Write(json)
}

// 302 重定向
func reHandler(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Location", "https://www.google.com")
	w.WriteHeader(302)
}

// 客户端响应
func main() {
	http.HandleFunc("/testJSON", testJSONRes)
	http.HandleFunc("/toGoogle", reHandler)
	http.ListenAndServe(":8080", nil)
}
