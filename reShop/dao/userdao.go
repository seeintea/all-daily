package dao

import (
	"shopping/model"
	"shopping/utils"
)

// CheckUserInfo 核查用户信息，验证账号密码 - true 成功
func CheckUserInfo(u string, p string) (bool, *model.User) {
	// SQL 语句
	sqlStr := "select id, username, password, email from users where username = ? and password = ?"
	// SQL 查询 Query() 返回一条信息
	row := utils.Db.QueryRow(sqlStr, u, p)
	user := &model.User{
		ID: 0,
	}
	// 获取查询到的记录
	err := row.Scan(&user.ID, &user.UserName, &user.PassWord, &user.Email)
	utils.ErrorFree(err)
	// 判断是否为正常用户
	if user.ID > 0 {
		return true, user
	}
	return false, nil
}

// CheckUserName 检查用户名，放置重复注册 - true 无重复
func CheckUserName(u string) bool {
	sqlStr := "select id from users where username = ?"
	row := utils.Db.QueryRow(sqlStr, u)
	// 通过 id 判断是否重复
	id := 0
	err := row.Scan(&id)
	utils.ErrorFree(err)
	if id > 0 {
		return false
	}
	return true
}

// AddNewUser 新增用户 - true 新增成功
func AddNewUser(u *model.User) bool {
	sqlStr := "insert into users(username,password,email) values(?,?,?)"
	// 执行 SQL 语句
	result, err := utils.Db.Exec(sqlStr, &u.UserName, &u.PassWord, &u.Email)
	state := utils.SQLAffected(result, err)
	if state > 0 {
		return false
	}
	return true
}
