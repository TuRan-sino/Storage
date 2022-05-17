# 简介
&emsp;&emsp;各种语言学习时期的练习代码, 以及部分和学习有关的小项目<br>

# 内容
1. C/C++ 
0. Assembly 
0. java 
0. python 
0. bash 


---

# git 使用说明
## git 在不同平台协作使得回车转化
&emsp;&emsp;git自带的有crlf和lf的转化.<br>
&emsp;&emsp;管他妈的!, 我只要知道, 在linux上面使用dos2unix命令可以转化
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
