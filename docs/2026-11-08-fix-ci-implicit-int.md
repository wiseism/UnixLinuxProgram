# 修复记录：CI 隐式 int 编译失败（2026-11-08）

## 失败信息
- 仓库：wiseism/UnixLinuxProgram
- Workflow：CMake on a single platform
- 失败 run：[42440566747](https://github.com/wiseism/UnixLinuxProgram/actions/runs/42440566747)、[42429571890](https://github.com/wiseism/UnixLinuxProgram/actions/runs/42429571890)

## 错误日志摘录
```
CH02/cp1.c:16:1: error: return type defaults to 'int' [-Wimplicit-int]
CH02/who0.c:19:1: error: return type defaults to 'int' [-Wimplicit-int]
gmake[2]: *** [CMakeFiles/CH02_who0.dir/build.make:79: ...] Error 1
##[error]Process completed with exit code 2.
```

## 原因分析
GitHub ubuntu-latest 迁移到 Ubuntu 26.04 后默认 GCC 为 14+，`-Wimplicit-int`
从警告升级为错误。本项目是 K&R/C89 风格的 UNIX 教材代码，大量源文件未写
函数返回类型（`main(...)`、`show_info(...)`），在新编译器下无法通过编译。

## 修复内容
1. `CMakeLists.txt`：新增 `set(CMAKE_C_STANDARD 90)` + `CMAKE_C_STANDARD_REQUIRED`，
   全项目统一按 C89(gnu90) 标准，兼容教材原代码风格。
2. `CH02/who0.c`：`show_info(...)` 显式声明为 `void show_info(...)`。
3. `CH02/cp1.c`：`main(...)` 显式声明为 `int main(...)`（提交 8e3f020）。

## 验证
| run id | 结果 |
| --- | --- |
| 42440566747 (仅 cp1.c 修复) | failure（who0.c 等其余文件同问题） |
| 本次推送触发 | 待填 |

## 补充记录

- 42440878827 复测失败新原因: `CH01/more01.c:16 for` 循环内初始声明需 C99+。C89 方案与 C99 特性冲突, 最终改为 C11 (CMAKE_C_STANDARD 11): 隐式 int 在 C11 下仅为警告, for 初始声明合法。

### 第3次复测(42442417022)失败原因
- 原型此前被 append 到文件尾, 移动到 include 之后(bounce1d/bounce_async/bounce_aio)。

## 最终结论

- run 42476715292: ✅ **success**。C11 标准 + 全仓 K&R 显式化 + POSIX 头文件补齐。
