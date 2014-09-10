package main

import (
	"fmt"
	"encoding/json"
)

type St struct {
	Ref string    // `json:"ref"`
}

func main() {
	var s St
	str := `{"ref":"dddr"}`
	json.Unmarshal([]byte(str),&s)
	fmt.Printf("aaaa:%s\n",s.Ref)
	str2 := "abcdefg"
	cc  := str2[0:1]
	str2[0] = "g"
	cc = "e"
	fmt.Printf(str2[0:1]+"\n")
	fmt.Printf(cc)
}



