## 安装
`zsh ./install`时候出错，如下
```
src/model/dao.go:13:2: import "github.com/go-sql-driver/mysql": cannot find package
src/filter/login.go:11:2: import "github.com/gorilla/context": cannot find package
src/filter/login.go:12:2: import "github.com/gorilla/sessions": cannot find package
src/filter/admin.go:10:2: import "github.com/studygolang/mux": cannot find package
src/controller/websocket.go:10:2: import "go.net/websocket": cannot find package
```
解决github上的包：
```
go get github.com/go-sqm-driver/mysql
....
```

解决code.google上的包:
```
go get code.google.com/p/go.net/websocket
```
修改`src/controller/websocket.go`中`go.net/websocket`为`code.google.com/p/go.net/websocket`。

finished
