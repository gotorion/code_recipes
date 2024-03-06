package main

import (
	"fmt"
	"unsafe"
)

func main() {
	var fnum float64 = 78.23
	fmt.Println(unsafe.Sizeof(fnum))

	var fnum_1 float32 = 23.34
	fmt.Println(unsafe.Sizeof(fnum_1))

	var fnum_2 float64 = 2.234e+19
	fmt.Println(fnum_2)
}
