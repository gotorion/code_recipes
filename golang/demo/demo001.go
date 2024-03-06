package main

import (
	"fmt"
	"unsafe"
)

func main() {
	var num_1 int8 = 32
	fmt.Println(num_1)

	// var num_2 int8 = 394234235 //error scope
	// fmt.Println(num_2)

	// var num_2 uint8 = -2 // error negetive number
	// fmt.Println(num_2)
	num := 23423525234523525
	fmt.Println(unsafe.Sizeof(num))

	name := "this is test name blah blah"
	fmt	.Println(unsafe.Sizeof(name))
}
