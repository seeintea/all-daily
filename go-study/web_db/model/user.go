package model

import (
	"fmt"
	"web_db/utils"
)

// User 结构体
type User struct {
	ID       int
	UserName string
	PassWord string
	Email    string
}

// AddUser 添加User方法 方法 1
func (user *User) AddUser() error {
	// SQL语句
	sqlStr := "insert into users(user_name, passw_wprd, email) values (?,?,?)"
	// 预处理
	inStmt, err := utils.Db.Prepare(sqlStr)
	if err != nil {
		fmt.Println("预编译异常。", err)
		return err
	}
	// 执行
	_, err := inStmt.Exec("admin", "123456", "admin@zip.com")
	if err != nil {
		fmt.Println("执行异常", err)
		return err
	}
	return nil
}

// AddUser2 添加User方法 方法 2
func (user *User) AddUser2() error {
	// SQL语句
	sqlStr := "insert into users(user_name, passw_wprd, email) values (?,?,?)"
	// 执行
	_, err := utils.Db.Exec(sqlStr, "admin1", "654321", "admin1@zip.com")
	if err != nil {
		fmt.Println("执行异常", err)
		return err
	}
	return nil
}
