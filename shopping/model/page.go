package model

//Page 分页
type Page struct {
	Books       []*Book //存放图书切片
	PageNo      int64   //当前页
	PageSize    int64   //每页条数
	TotalPageNo int64   //总页数
	TotalRecord int64   //总记录数
}
