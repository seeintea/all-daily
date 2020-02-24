package utils

import "fmt"

/*
	dev - 暂时不考虑日志文件，简单抛置后台
*/

// ErrorHandle 抛出错误，在控制台显示
func ErrorHandle(err error) {
	if err != nil {
		fmt.Println(err)
	}
}

// ErrorFree 释放错误，不需要在控制台显示
func ErrorFree(err error) {
	err = nil
}
