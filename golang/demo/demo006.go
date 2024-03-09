package main
import (
	"fmt"
	"unsafe"
)
func main() {
	var num int8 = 10;
	fmt.Println(unsafe.Sizeof(num))	
	// force trans type
	var fnum float64 = float64(num)
	fmt.Println(unsafe.Sizeof(fnum))

	var n1 int32 = 10
	var n2 int64 = 10
	// var n3 = n1 + n2 // mismatch type
	var n3 = int64(n1) + n2
	fmt.Println(n3)
}