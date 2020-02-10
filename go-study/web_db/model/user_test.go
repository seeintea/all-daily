package model

import (
	"fmt"
	"testing"
)

// 在测试之前，执行一些其他操作
func TestMain(m *testing.M) {
	fmt.Println("测试开始")
	// 通过 m.Run() 开始测试程序
	m.Run()
}

// 函数名不是以 Test- 开头，那么函数默认不执行。但是可以将其作为子测试程序
func testAddUser(t *testing.T) {
	fmt.Println("测试添加用户：")
	user := User{}
	// 点用添加用户方法
	user.AddUser()
	user.AddUser1()
}

func testGetUserByID(t *testing.T) {
	fmt.Println("测试ID查询User")
	user := User{
		ID: 1,
	}
	// 获取User方法
	u, _ := user.GetUserByID()
	fmt.Println("得到的User信息", u)
}

func testGetUser(t *testing.T) {
	fmt.Println("测试获取所有User:")
	user := &User{}
	us, _ := user.GetUsers()
	// 遍历切片
	for k, v := range us {
		fmt.Printf("第%v个用户是%v:", k+1, v)
	}
}

func TestUser(t *testing.T) {
	fmt.Println("开始测试User中的相关方法-")
	//t.Run("测试添加用户:", testAddUser)
	//t.Run("获取User:", testGetUserByID)
	t.Run("获取所有User:", testGetUser)
}
