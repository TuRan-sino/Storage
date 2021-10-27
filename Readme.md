# 内容
1. C/C++ source code
2. Assembly source code  
3. java source code
4. Matlabe source code
5. python source code
6. bash source code

# 简介
&emsp;这里面存放的基本上都是我用各种语言写过的代码, 一般情况下都是一些*做题&练习&demo*代码. 不存在Project
&emsp;Repo => 代码仓库(非混合代码), 存放的自己写过的代码<br>
&emsp;Lib => 对应语言的个人库<br>

## 子文件夹说明
### C
0. Repo/DS_Demo: 数据结构示例代码
1. Repo/Item: 小型的混合程序
2. Repo/LeetCode: LeetCode做题代码
3. Repo/Matter: 平日里遇到的小问题


# git 使用说明
## git 在不同平台协作使得回车转化
&emsp;git自带的有crlf和lf的转化.<br>
管他妈的!, 我只要知道, 在linux上面使用dos2unix命令可以转化

```
dos2unix的一些命令
0.   -k日期不变
1.   -n 源文件不变转化到另一个文件
```

---

## autocrlf的工作原理
0. true<br>
&emsp;*.   push: ??? -> lf<br>
&emsp;*.   pull : ???->crlf<br>
1. false<br>
&emsp;*.   push: none<br>
&emsp;*.   pull: none<br>
2. input<br>
&emsp;*.   push: ??? -> lf<br>
&emsp;*.   pull: none<br>
