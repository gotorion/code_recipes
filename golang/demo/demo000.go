package main

import "fmt"

// global varibles
var g_num = 100

var (
	g_name = "g_name"
	g_number = 200
)

func main() {
	/*print global varibles*/
	fmt.Println("g_name = ", g_name)
	fmt.Println("g_number = ", g_number)
	// local varibles
	var num int = 10
	fmt.Println("num = ", num)

	var fnum float64 // will use default, fnum = 0
	fmt.Println(fnum)

	var name = "john li" // go will automatically deduce type if no specific type
	fmt.Println(name)

	sex := "male" // := equals var sex = "male"
	fmt.Println(sex)

	var n1, n2, n3 int
	fmt.Println(n1)
	fmt.Println(n2)
	fmt.Println(n3)

	var n4, str = 10, "test string"
	fmt.Println(n4)
	fmt.Println(str)

	n5, n6 := 20, 20.999
	fmt.Println(n5)
	fmt.Println(n6)
}