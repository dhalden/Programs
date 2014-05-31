package main

import (
        "fmt"
        "time"
)

func greeting() string {
    return "Hello world, the time is "+ time.Now().String()
}

func main(){
    fmt.Println(greeting())
}
