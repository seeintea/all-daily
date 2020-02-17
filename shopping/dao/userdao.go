package dao

import (
	"shopping/model"
	"shopping/utils"
)

// CheckUser 验证用户名和密码
func CheckUser(username string, password string) (*model.User, error) {
	// sql 语句
	sqlStr := "select id, username, password, email from users where username = ? and password = ?"
	// 执行
	row := utils.Db.QueryRow(sqlStr, username, password)
	user := &model.User{}
	err := row.Scan(&user.ID, &user.UserName, &user.PassWord, &user.Email)
	return user, err
}

// CheckUserName 验证用户名
func CheckUserName(username string) (bool, error) {
	// sql 语句
	sqlStr := "select id from users where username = ?"
	// 执行
	idExist := false
	id := -1
	row := utils.Db.QueryRow(sqlStr, username)
	err := row.Scan(&id)
	if id > 0 {
		idExist = true
	}
	return idExist, err
}

// SaveUser 保存用户
func SaveUser(username string, password string, email string) error {
	// sql 语句
	sqlStr := "insert into users(username,password,email) values(?,?,?)"
	// 执行
	_, err := utils.Db.Exec(sqlStr, username, password, email)
	if err != nil {
		return err
	}
	return nil
}
