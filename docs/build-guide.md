# 构建与部署准备

项目包含 C++ 源文件、Tars 协议和 `makefile`。由于不同环境的 Tars 及第三方库路径可能不同，构建前需要先检查 Makefile。

## 检查清单

- Linux 发行版及 CPU 架构
- GCC/G++ 与 C++ 标准版本
- Tars 编译器、头文件和运行库版本
- Makefile 中的包含目录与链接目录
- 服务配置、日志和运行用户权限

## 获取源码

```bash
git clone https://github.com/masterai-top/Texas-Holdem-Poker-Game-Source-Code.git
cd Texas-Holdem-Poker-Game-Source-Code
make
```

如果构建失败，请记录系统、编译器、依赖版本、完整命令及第一处错误。不要把生产服务器密码、数据库凭据或密钥提交到仓库。

