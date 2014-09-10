package main

import (
	"github.com/codegangsta/cli"
	"os"
)

func main(){
	app := cli.NewApp()
	app.Name = "fireyang"
	app.Usage = "make an explosive entrance"
	app.Action = func(c *cli.Context){
		println("hello world")
	}
	app.Run(os.Args)
}

