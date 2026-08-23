# 德州扑克源码说明

本仓库公开内容以 C++ 德州扑克服务端代码为主，包括登录、订单、用户、坐下、站起、牌局状态、业务处理和 Tars 协议等模块。它适合用于阅读多人扑克游戏的后端结构与业务流程。

## 阅读顺序

1. 查看 `LoginProto.tars`、`LoginServant.tars` 和 `OrderServant.tars` 理解接口。
2. 阅读 `LoginServer.cpp`、`OrderServer.cpp` 等服务入口。
3. 从 `Processor.cpp`、`gamestation.cpp` 梳理牌局状态。
4. 结合 `sitdown.cpp`、`standup.cpp` 和 `userinfo.cpp` 查看用户流程。
5. 检查 `makefile` 中的依赖和构建目标。

## 下载

[前往 GitHub 下载德州扑克源码](https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code)

当前公开范围以仓库实际文件为准。客户端、数据库、后台或商业组件若不在仓库中，不应默认视为开源内容。

