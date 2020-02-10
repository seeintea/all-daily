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
	sqlStr := "insert into users(user_name, pass_word, email) values (?,?,?)"
	// 预处理
	inStmt, err := utils.Db.Prepare(sqlStr)
	if err != nil {
		fmt.Println("预编译异常。", err)
		return err
	}
	// 执行
	_, err = inStmt.Exec("admin", "123456", "admin@zip.com")
	if err != nil {
		fmt.Println("执行异常", err)
		return err
	}
	return nil
}

// AddUser2 添加User方法 方法 2
func (user *User) AddUser1() error {
	// SQL语句
	sqlStr := "insert into users(user_name, pass_word, email) values (?,?,?)"
	// 执行
	_, err := utils.Db.Exec(sqlStr, "admin1", "654321", "admin1@zip.com")
	if err != nil {
		fmt.Println("执行异常", err)
		return err
	}
	return nil
}

// GetUserByID
func (user *User) GetUserByID() (*User, error) {
	sqlStr := "select id, user_name, pass_word, email from users where id = ? "
	// 返回一行结果
	row := utils.Db.QueryRow(sqlStr, user.ID)
	// 声明
	var id int
	var username string
	var password string
	var email string
	err := row.Scan(&id, &username, &password, &email)
	if err != nil {
		return nil, err
	}
	u := &User{
		ID:       id,
		UserName: username,
		PassWord: password,
		Email:    email,
	}
	return u, nil
}

// GetUsers 获取数据表的所有的记录
func (user *User) GetUsers() ([]*User, error) {
	sqlStr := "select id, user_name, pass_word, email from users"
	rows, err := utils.Db.Query(sqlStr)
	if err != nil {
		return nil, err
	}
	// 创建 User 切片
	var users []*User
	var id int
	var username string
	var password string
	var email string
	for rows.Next() {
		rows.Scan(&id, &username, &password, &email)
		u := &User{
			ID:       id,
			UserName: username,
			PassWord: password,
			Email:    email,
		}
		users = append(users, u)
	}
	return users, nil
}
