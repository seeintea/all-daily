package main

import (
	"fmt"
)

func main() {

	fmt.Println("Golang 42_13 map")
	mapDome := make(map[string]float32, 100)
	mapDome["one"] = 1
	mapDome["two"] = 2
	mapDome["thr"] = 3
	fmt.Println(mapDome)
	/*
		var mapDome map[string] float32
		mapDome["one"] = 1 worry
	*/
	// ensure key
	if _, val := mapDome["fou"]; !val {
		fmt.Println("no entry")
	}
	//delete
	delete(mapDome, "thr")
	fmt.Println(mapDome)

	//range
	data := []int{1, 2, 3}
	fmt.Println(data)
	for _, v := range data {
		v *= 10
		fmt.Println(v)
	}
	fmt.Println(data)
	for i, _ := range data {
		data[i] *= 10
	}
	fmt.Println(data)

}
