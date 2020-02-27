package utils

import (
	"database/sql"
	"fmt"
)

/*
	dev - 暂时不考虑日志文件，简单抛置后台
*/

// ErrorHandle 抛出错误，在控制台显示
func ErrorHandle(err error) {
	if err != nil {
		fmt.Println("程序bug:")
		fmt.Println(err)
	}
}

// ErrorFree 释放错误，不需要在控制台显示
func ErrorFree(err error) {
	err = nil
}

// SQLAffected SQL执行影响处理
func SQLAffected(r sql.Result, e error) int64 {
	if err != nil {
		ErrorHandle(err)
		return -1
	}
	affect, err := r.RowsAffected()
	ErrorFree(err)
	return affect
}
