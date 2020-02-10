package utils

import (
	"database/sql"

	// mysql 连接包
	_ "github.com/go-sql-driver/mysql"
)

var (
	Db  *sql.DB
	err error
)

func init() {
	Db, err = sql.Open("mysql", "root:12345678@tcp(localhost:3306)/go")
	if err != nil {
		panic(err.Error())
	}
}
