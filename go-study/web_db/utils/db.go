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
	Db, err := sql.Open("mysql", "root:root@tcp(localhost:3360)/go")
	if err != nil {
		panic(err.Error())
	}
}
