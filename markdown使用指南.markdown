1.
在线markdown工具推荐：https://dillinger.io/

###2.标题###
标题通过#的个数进行区分，Markdown共支持6级标题。

3.字体设置
3.1***粗体***
文字前后加**来表示粗体。

**粗体**
粗体

3.2斜体
文字前后加*来表示斜体。

*斜体*
斜体

3.3粗斜体
文字前后加***来表示粗斜体。

***粗斜体***
粗斜体

3.4下划线
文字前后加<u> </u>来表示下划线。

<u>下滑线</u>
下划线

3.5删除线
文字前后加~~来表示删除线。

~~删除线~~
~~删除线~~

3.6标记
文字前后加`来表示标记，该符号位于Esc键下面。

`标记`
标记

3.7Html标签
<font face="微软雅黑" color="red" size="6">字体及字体颜色和大小</font>
字体及字体颜色和大小

4.列表
4.1有序列表
采用1. 后加空格形式表示有序列表。

1. 有序列表1
2. 有序列表2
3. 有序列表3
有序列表1
有序列表2
有序列表3
4.2无序列表
采用+ - * =符号表示无序列表，支持多级嵌套。

+ 有序列表1
+ + 有序列表1.1
+ + 有序列表1.2
+ 有序列表2
+ 有序列表3
无序列表1
无序列表1.1
无序列表1.2
无序列表2
无序列表3
4.3未完成列表
采用- []表示未完成任务，各符号间均有空格。

- [ ] 未完成任务1
- [ ] 未完成任务2
- [ ] 未完成任务3
[ ] 未完成任务1
[ ] 未完成任务2
[ ] 未完成任务3
4.4已完成任务
采用- [x]表示已完成任务，各符号间均有空格。同时可直接在未完成任务间打勾来转换成已完成任务。

- [x] 已完成任务1
- [x] 已完成任务2
- [x] 已完成任务3
[x] 已完成任务1
[x] 已完成任务2
[x] 已完成任务3
5.表格
表格对齐方式

居左：:----
居中：:----:或-----
居由：----:
| 标题1           |      标题2      |           标题3 |
| :-------------- | :-------------: | --------------: |
| 居左测试文本1.1 | 居中测试文本2.1 | 居右测试文本3.1 |
| 居左测试文本1.2 | 居中测试文本2.2 | 居右测试文本3.2 |
| 标题1 | 标题2 | 标题3 |
| :-------------- | :-------------: | --------------: |
| 居左测试文本1.1 | 居中测试文本2.1 | 居右测试文本3.1 |
| 居左测试文本1.2 | 居中测试文本2.2 | 居右测试文本3.2 |

6.段落和换行
6.1首行缩进方式
&emsp;中文空格
&ensp;半中文空格
&nbsp;英文空格
输入法切换到全角双击空格
6.2换行
换行处连续打两个空格
换行处使用<br>进行换行
6.3空行
空行处连续打两个空格
换行处使用<br>进行空行
6.引用和代码块
6.1引用
若在文章中需要引入一段话等，可以采用引用的方式呈现，支持多级引用。

> 引用1
> > 引用1.1
> > 引用1.2
> 引用2
引用1
引用1.1
引用1.2

引用2
6.2代码块
代码前后添加```表示代码块。

```Python
print('代码块')
```
print（'代码块'）
7.链接
7.1图片链接
采用![]()来表示图片链接。

![图片名称](链接地址)



7.2文字链接
采用[]()表示文字链接。

[链接名称](链接地址)
文字链接

7.3参考链接
采用[ ]:表示参考链接，注意符号后有空格。

[ ]: url title
8.分割线
上下文无关时可使用分割符进行分开。

连续多个- (>=3)
连续多个* （>=3）
连续多个下划线_ （>=3）
---分割线
***分割线
___分割线
9.脚注和注释
9.1脚注
采用`[^]:表示脚注，注意空格。

[^]: 脚注
9.2注释
采用<!---->表示注释.

<!--注释-->
11.转义
Markdown通过反斜杠\来插入在语法中有其他意义的符号，Markdown支持以下符号来进行转义。

\\反斜线
\`反引号
\*星号
\_下划线
\{}花括号
\[]方括号
\()括弧
\#井字号
\+加号
\-减号
\.英文句点
\!感叹号
反斜线
`反引号
*星号
_下划线
{}花括号
[]方括号
()括弧
#井字号
+加号
-减号
.英文句点
!感叹号

12.目录
采用[TOC]来生成文章目录。

[TOC]

Markdown 编辑器语法指南
基本技巧
代码
如果你只想高亮语句中的某个函数名或关键字，可以使用 `function_name()` 实现

通常编辑器根据代码片段适配合适的高亮方法，但你也可以用 ``` 包裹一段代码，并指定一种语言

```javascript
$(document).ready(function () {
    alert('hello world');
});
```
支持的语言：1c, abnf, accesslog, actionscript, ada, apache, applescript, arduino, armasm, asciidoc, aspectj, autohotkey, autoit, avrasm, awk, axapta, bash, basic, bnf, brainfuck, cal, capnproto, ceylon, clean, clojure, clojure-repl, cmake, coffeescript, coq, cos, cpp, crmsh, crystal, cs, csp, css, d, dart, delphi, diff, django, dns, dockerfile, dos, dsconfig, dts, dust, ebnf, elixir, elm, erb, erlang, erlang-repl, excel, fix, flix, fortran, fsharp, gams, gauss, gcode, gherkin, glsl, go, golo, gradle, groovy, haml, handlebars, haskell, haxe, hsp, htmlbars, http, hy, inform7, ini, irpf90, java, javascript, json, julia, kotlin, lasso, ldif, leaf, less, lisp, livecodeserver, livescript, llvm, lsl, lua, makefile, markdown, mathematica, matlab, maxima, mel, mercury, mipsasm, mizar, mojolicious, monkey, moonscript, n1ql, nginx, nimrod, nix, nsis, objectivec, ocaml, openscad, oxygene, parser3, perl, pf, php, pony, powershell, processing, profile, prolog, protobuf, puppet, purebasic, python, q, qml, r, rib, roboconf, rsl, ruby, ruleslanguage, rust, scala, scheme, scilab, scss, smali, smalltalk, sml, sqf, sql, stan, stata, step21, stylus, subunit, swift, taggerscript, tap, tcl, tex, thrift, tp, twig, typescript, vala, vbnet, vbscript, vbscript-html, verilog, vhdl, vim, x86asm, xl, xml, xquery, yaml, zephir

也可以使用 4 空格缩进，再贴上代码，实现相同的的效果

    def g(x):
        yield from range(x, 0, -1)
    yield from range(x)
如你不需要代码高亮，可以用下面的方法禁用：

```nohighlight
```
标题
文章内容较多时，可以用标题分段：

标题1
======

标题2
-----

## 大标题 ##
### 小标题 ###
粗斜体
*斜体文本*    _斜体文本_
**粗体文本**    __粗体文本__
***粗斜体文本***    ___粗斜体文本___
链接
常用链接方法

文字链接 [链接名称](http://链接网址)
网址链接 <http://链接网址>
高级链接技巧

这个链接用 1 作为网址变量 [Google][1].
这个链接用 yahoo 作为网址变量 [Yahoo!][yahoo].
然后在文档的结尾为变量赋值（网址）

  [1]: http://www.google.com/
  [yahoo]: http://www.yahoo.com/
列表
普通无序列表

- 列表文本前使用 [减号+空格]
+ 列表文本前使用 [加号+空格]
* 列表文本前使用 [星号+空格]
普通有序列表

1. 列表前使用 [数字+空格]
2. 我们会自动帮你添加数字
7. 不用担心数字不对，显示的时候我们会自动把这行的 7 纠正为 3
列表嵌套

1. 列出所有元素：
    - 无序列表元素 A
        1. 元素 A 的有序子列表
    - 前面加四个空格
2. 列表里的多段换行：
    前面必须加四个空格，
    这样换行，整体的格式不会乱
3. 列表里引用：

    > 前面空一行
    > 仍然需要在 >  前面加四个空格

4. 列表里代码段：

    ```
    前面四个空格，之后按代码语法 ``` 书写
    ```

        或者直接空八个，引入代码块
引用
普通引用

> 引用文本前使用 [大于号+空格]
> 折行可以不加，新起一行都要加上哦
引用里嵌套引用

> 最外层引用
> > 多一个 > 嵌套一层引用
> > > 可以嵌套很多层
引用里嵌套列表

> - 这是引用里嵌套的一个列表
> - 还可以有子列表
>     * 子列表需要从 - 之后延后四个空格开始
引用里嵌套代码块

>     同样的，在前面加四个空格形成代码块
>  
> ```
> 或者使用 ``` 形成代码块
> ```
图片
跟链接的方法区别在于前面加了个感叹号 !，这样是不是觉得好记多了呢？

![图片名称](http://图片网址)
当然，你也可以像网址那样对图片网址使用变量

这个链接用 1 作为网址变量 [Google][1].
然后在文档的结尾位变量赋值（网址）

 [1]: http://www.google.com/logo.png
换行
如果另起一行，只需在当前行结尾加 2 个空格

在当前行的结尾加 2 个空格  
这行就会新起一行
如果是要起一个新段落，只需要空出一行即可。

分隔符
如果你有写分割线的习惯，可以新起一行输入三个减号-。当前后都有段落时，请空出一行：

前面的段落

---

后面的段落

高级技巧
行内 HTML 元素
目前只支持部分段内 HTML 元素效果，包括 <kdb> <b> <i> <em> <sup> <sub> <br> ，如

键位显示

使用 <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>Del</kbd> 重启电脑
代码块

使用 <pre></pre> 元素同样可以形成代码块
粗斜体

<b> Markdown 在此处同样适用，如 *加粗* </b>
符号转义
如果你的描述中需要用到 markdown 的符号，比如 _ # * 等，但又不想它被转义，这时候可以在这些符号前加反斜杠，如 \_ \# \* 进行避免。

\_不想这里的文本变斜体\_
\*\*不想这里的文本被加粗\*\*
扩展
支持 jsfiddle、gist、runjs、优酷视频，直接填写 url，在其之后会自动添加预览点击会展开相关内容。

http://{url_of_the_fiddle}/embedded/[{tabs}/[{style}]]/
https://gist.github.com/{gist_id}
http://runjs.cn/detail/{id}
http://v.youku.com/v_show/id_{video_id}.html
公式
当你需要在编辑器中插入数学公式时，可以使用两个美元符 $$ 包裹 TeX 或 LaTeX 格式的数学公式来实现。提交后，问答和文章页会根据需要加载 Mathjax 对数学公式进行渲染。如：

$$ x = {-b \pm \sqrt{b^2-4ac} \over 2a}. $$

$$
x \href{why-equal.html}{=} y^2 + 1
$$
同时也支持 HTML 属性，如：

$$ (x+1)^2 = \class{hidden}{(x+1)(x+1)} $$

$$
(x+1)^2 = \cssId{step1}{\style{visibility:hidden}{(x+1)(x+1)}}
$$


语法指南
以下是Markdown语法的概述，您可以在GitHub.com或您自己的文本文件中的任何位置使用它。

头
# This is an <h1> tag
## This is an <h2> tag
###### This is an <h6> tag
重点
*This text will be italic*
_This will also be italic_

**This text will be bold**
__This will also be bold__

_You **can** combine them_
清单
无序
* Item 1
* Item 2
  * Item 2a
  * Item 2b
有序
1. Item 1
1. Item 2
1. Item 3
   1. Item 3a
   1. Item 3b
图片
![GitHub Logo](/images/logo.png)
Format: ![Alt Text](url)
链接
http://github.com - automatic!
[GitHub](http://github.com)
引用文字
As Kanye West said:

> We're living the future so
> the present is our past.
内联代码
I think you should use an
`<addr>` element here instead.

GitHub调味降价
GitHub.com使用自己版本的Markdown语法，该语法提供了一组额外的有用功能，其中许多功能可以更轻松地使用GitHub.com上的内容。

请注意，GitHub Flavored Markdown的某些功能仅在“问题和请求”的说明和注释中提供。这些包括@mentions以及对SHA-1哈希，问题和请求的引用。任务列表也可以在Gist注释和Gist Markdown文件中找到。

语法突出显示
以下是如何使用GitHub Flavored Markdown进行语法高亮显示的示例：

```javascript
function fancyAlert(arg) {
  if(arg) {
    $.facebox({div:'#foo'})
  }
}
```
您还可以简单地将代码缩进四个空格：

    function fancyAlert(arg) {
      if(arg) {
        $.facebox({div:'#foo'})
      }
    }
以下是没有语法突出显示的Python代码示例：

def foo():
    if not bar:
        return True
任务列表
- [x] @mentions, #refs, [links](), **formatting**, and <del>tags</del> supported
- [x] list syntax required (any unordered or ordered list supported)
- [x] this is a complete item
- [ ] this is an incomplete item
如果您在问题的第一条评论中包含任务列表，您将在问题列表中获得一个方便的进度指示器。它也适用于Pull Requests！

表
您可以通过组合单词列表​​并用连字符-（对于第一行）分隔它们，然后用管道分隔每个列来创建表格|：

First Header | Second Header
------------ | -------------
Content from cell 1 | Content from cell 2
Content in the first column | Content in the second column
会成为：

第一个标题	第二个标题
来自单元格1的内容	来自单元格2的内容
第一列中的内容	第二列中的内容
SHA引用
对提交的SHA-1哈希的任何引用都将自动转换为GitHub上该提交的链接。

16c999e8c71134401a78d4d46435517b2271d6ac
mojombo@16c999e8c71134401a78d4d46435517b2271d6ac
mojombo/github-flavored-markdown@16c999e8c71134401a78d4d46435517b2271d6ac
在存储库中发出引用
任何引用Issue或Pull Request的数字都将自动转换为链接。

#1
mojombo#1
mojombo/github-flavored-markdown#1
用户名@mentions
键入@符号，后跟用户名，将通知该人来查看评论。这被称为“@mention”，因为你提到的是个人。您还可以在组织内@mention团队。

自动链接URL
任何URL（如http://www.github.com/）都将自动转换为可点击的链接。

删除线
任何包含两个波浪形（如~~this~~）的单词都会显示为划掉。

表情符号
GitHub支持表情符号！

要查看我们支持的每张图片的列表，请查看表情符号备忘单。
