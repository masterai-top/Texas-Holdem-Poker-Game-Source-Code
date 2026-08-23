# 德州扑克源码 GitHub 与 Google 优化方案

## 一、当前最需要修复的问题

1. README 标题和 About 重复堆叠“德州源码”等关键词，应改为一个清晰标题和自然描述。
2. README 声称支持客户端、后台、Docker、Kubernetes、数据库初始化和 `docs/Server_Deployment.md`，但仓库首页未显示对应目录。
3. “万级并发”“50-80ms”“防作弊强”等性能或安全结论缺少公开测试方法和报告。
4. 快速开始使用多个 H1，Markdown 标题层级错误。
5. 图片名称和 alt 文本不具备描述性，部分图片使用会过期的 GitHub 临时链接。
6. Topics 中存在大量重复词，且 `poker-ai` 与当前可见文件不一致。

先修复真实性和可运行性，再增加关键词页面。内容可信度会直接影响访问者是否愿意下载。

## 二、建议目录

```text
.
|-- README.md
|-- LICENSE
|-- CONTRIBUTING.md
|-- SECURITY.md
|-- CHANGELOG.md
|-- docs/
|   |-- README.md
|   |-- texas-holdem-source-code.md
|   |-- server-architecture.md
|   |-- build-guide.md
|   |-- protocol-guide.md
|   |-- game-flow.md
|   |-- security-compliance.md
|   `-- faq.md
|-- examples/                # 最小调用或协议示例
|-- tests/                   # 牌型、状态机和边界测试
|-- config/                  # 去除密钥后的配置示例
|-- scripts/                 # 构建和检查脚本
|-- Screenshots/
`-- Video/
```

## 三、必须补充的源码配套内容

### 构建说明

明确 Linux 发行版、编译器版本、Tars 版本、依赖库、环境变量、编译命令和预期产物。现有 `makefile` 中的本机路径应改成可配置变量。

### 配置样例

增加不包含密码的 `config/example.conf` 或 `.env.example`。任何数据库密码、邮件凭据、服务器 IP 和密钥都不应提交。

### 测试

优先增加：

- 牌型比较测试
- 洗牌与发牌边界测试
- 玩家坐下、站起和断线状态测试
- 重复请求与非法状态转换测试
- 协议字段兼容测试

### Release

创建语义化版本，例如 `v0.1.0`。Release 中写清公开源码范围、支持的平台、构建状态和校验值。Release ZIP 的真实下载次数比 README 点击更有参考价值。

### 安全说明

增加 `SECURITY.md`，说明漏洞报告方式。随机数、公平性、支付和账号安全若未审计，不要使用“安全”“防作弊强”等绝对表述。

## 四、Google 搜索内容布局

主关键词：`德州源码`、`德州扑克源码`。

辅助关键词：`C++ 德州扑克服务端`、`扑克游戏服务器源码`、`Texas Hold'em source code`、`poker server source code`。

每个页面解决一个明确问题，不要复制 README 后只替换标题。推荐文档：

- `texas-holdem-source-code.md`：源码范围和模块入口
- `server-architecture.md`：服务、协议和状态流转
- `build-guide.md`：可复现的构建步骤
- `protocol-guide.md`：Tars 文件和调用关系
- `game-flow.md`：坐下、开始、行动、结算、站起
- `security-compliance.md`：随机数、安全和地区合规
- `faq.md`：是否完整、如何编译、是否包含客户端

## 五、增加下载转化

1. README 首屏在 10 秒内回答“是什么、包含什么、如何下载”。
2. 提供可验证的构建状态，不要只展示营销文案。
3. 用固定仓库路径引用 3 至 5 张真实截图。
4. 提供一个最小可运行示例或测试程序。
5. 创建带说明和校验值的 GitHub Release。
6. 为 Issue 添加 bug、build、documentation 标签和模板。
7. 在技术文章中链接到对应文档页，而非到处投放相同广告文本。

## 六、外部收录

GitHub 页面已经能被 Google 抓取，但不能像自有网站一样完整控制 SEO。建议使用 GitHub Pages 或独立域名建立文档站，并配置标题、description、canonical、sitemap、robots.txt 和 `SoftwareSourceCode` 结构化数据，然后通过 Google Search Console 提交 sitemap。

## 七、执行顺序

1. 替换 README 与 About，精简 Topics。
2. 删除或修正文档中仓库不存在的目录和功能声明。
3. 补齐可复现构建说明、配置样例和最小测试。
4. 增加 docs 专题页面并从 README 互链。
5. 创建第一个规范 Release。
6. 部署文档站并提交 Google Search Console。
7. 持续发布真实技术内容和版本更新。

