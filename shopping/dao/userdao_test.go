package dao

import (
	"fmt"
	"testing"
)

func TestUser(t *testing.T) {
	//fmt.Println("开始测试UserDao中的函数:")
	//t.Run("保存用户:", testRegist)
	//t.Run("验证用户:", testLogin)
	//t.Run("验证用户名:", testSave)
}

func testLogin(t *testing.T) {
	user, err := CheckUser("admin", "123456")
	if err != nil {
		panic(err.Error())
	}
	fmt.Println("获取用户信息:", user)
}

func testSave(t *testing.T) {
	is, err := CheckUserName("admin")
	if err != nil {
		panic(err.Error())
	}
	if is {
		fmt.Println("查询到用户了")
	} else {
		fmt.Println("未查询指定用户")
	}
}

func testRegist(t *testing.T) {
	SaveUser("admin", "123456", "admin@gmail.com")
}
