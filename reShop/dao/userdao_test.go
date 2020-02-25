package dao

import (
	"fmt"
	"shopping/model"
	"testing"
)

func TestUserDao(t *testing.T) {
	fmt.Println("userDao测试: ")
	t.Run("新增测试:", testAddNewUser)
	t.Run("重名测试:", testCheckUserName)
	t.Run("登陆测试:", testCheckUserInfo)
}

// 测试新增用户
func testAddNewUser(t *testing.T) {
	user := &model.User{
		UserName: "user5",
		PassWord: "654321",
		Email:    "user5@gmial.com",
	}
	result := AddNewUser(user)
	if result {
		fmt.Println("添加新用户成功")
	}
}

// 测试用户是否重复
func testCheckUserName(t *testing.T) {
	u := "admin"
	result := CheckUserName(u)
	if result {
		fmt.Println("test: 1.用户无重复")
	} else {
		fmt.Println("test: 1.用户重复")
	}
	u = "user8"
	result = CheckUserName(u)
	if result {
		fmt.Println("test: 2.用户无重复")
	} else {
		fmt.Println("test: 2.用户重复")
	}
}

// 测试用户密码验证
func testCheckUserInfo(t *testing.T) {
	u := "admin"
	p := "123456"
	result, _ := CheckUserInfo(u, p)
	if result {
		fmt.Println("test: 1.用户通过")
	} else {
		fmt.Println("test: 1.用户不通过")
	}
	p = "654321"
	result, _ = CheckUserInfo(u, p)
	if result {
		fmt.Println("test: 2.用户通过")
	} else {
		fmt.Println("test: 2.用户不通过")
	}
}
