1.[github-markdown-syntax](https://github.com/cdoco/markdown-syntax)
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

目录
分级标题
分隔线
超链接
行内式
参考式
自动链接
区块引用
引用的多层嵌套
引用其它要素
锚点
强调
斜体
粗体
删除线
列表
无序列表
有序列表
包含引用的列表
插入图片
图片行内式
图片参考式
表格
代码
代码行内式
缩进式多行代码
用六个`包裹多行代码
HTML 原始码
内容目录
注脚
LaTeX 公式
$ 表示行内公式
$$ 表示整行公式
流程图
时序图
待办事宜列表
分级标题
第一种写法:

这是一个一级标题
============================

这是一个二级标题
--------------------------------------------------
这是一个一级标题
这是一个二级标题
第二种写法:

# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题
一级标题
二级标题
三级标题
四级标题
五级标题
六级标题
分隔线
你可以在一行中用三个以上的星号、减号、底线来建立一个分隔线, 行内不能有其他东西。你也可以在星号或是减号中间插入空格。下面每种写法都可以建立分隔线:

* * *

***

*****

- - -

---------------------------------------
超链接
Markdown 支持两种形式的链接语法: 行内式和参考式两种形式, 行内式一般使用较多。

行内式
[]里写链接文字，()里写链接地址, ()中的 "" 中可以为链接指定title属性, title属性可加可不加。title属性的效果是鼠标悬停在链接上会出现指定的 title文字。[链接文字](链接地址 "链接标题") 这样的形式。链接地址与链接标题前有一个空格。

[Markdown Syntax](https://github.com/cdoco/markdown-syntax)
[Markdown Syntax](https://github.com/cdoco/markdown-syntax "Markdown Syntax")
Markdown Syntax 

Markdown Syntax

参考式
参考式超链接一般用在学术论文上面, 或者另一种情况, 如果某一个链接在文章中多处使用, 那么使用引用的方式创建链接将非常好, 它可以让你对链接进行统一的管理。

参考式链接分为两部分, 文中的写法 [链接文字][链接标记]，在文本的任意位置添加 [链接标记]:链接地址 "链接标题", 链接地址与链接标题前有一个空格。

全球最大的搜索引擎网站是[Google][1]。

[1]:http://www.google.com "Google"
全球最大的搜索引擎网站是 Google。 

自动链接
Markdown 支持以比较简短的自动链接形式来处理网址和电子邮件信箱, 只要是用 <> 包起来， Markdown 就会自动把它转成链接。一般网址的链接文字就和链接地址一样, 例如:

<https://google.com/>

<ocdoco@gmail.com>
https://google.com/ 

ocdoco@gmail.com

区块引用
区块引用需要在被引用的文本前加上 > 符号。

> 这是一个区块引用实例,

> Markdown.
这是一个区块引用实例,

Markdown.

Markdown 也允许你偷懒只在整个段落的第一行最前面加上 > :

> 平生不会相思,
才会相思,
便害相思。

> 空一缕余香在此,
盼千金游子何之。
平生不会相思, 才会相思, 便害相思。

空一缕余香在此, 盼千金游子何之。

引用的多层嵌套
区块引用可以嵌套（例如：引用内的引用）, 只要根据层次加上不同数量的 > :

>>> 锄禾日当午, 汗滴禾下土。 - 李绅

>> 山有木兮木有枝, 心悦君兮君不知。 - 越人歌

> 去年今日此门中, 人面桃花相映红。 - 崔护
锄禾日当午, 汗滴禾下土。 - 李绅

山有木兮木有枝, 心悦君兮君不知。 - 越人歌

去年今日此门中, 人面桃花相映红。 - 题都城南庄

引用其它要素
引用的区块内也可以使用其他的 Markdown 语法，包括标题、列表、代码区块等:

> - 入我相思门, 知我相思苦。
>
> - 长相思兮长相忆, 短相思兮无穷极。
>
> - 给出一些例子代码:
> ```markdown
>   return debug_backtrace();
> ```
入我相思门, 知我相思苦。

长相思兮长相忆, 短相思兮无穷极。

给出一些例子代码:

  return debug_backtrace();
锚点
网页中, 锚点其实就是页内超链接, 也就是链接本文档内部的某些元素, 实现当前页面中的跳转。比如我这里写下一个锚点, 点击回到目录, 就能跳转到目录。 在目录中点击这一节, 就能跳过来。还有下一节的注脚。这些根本上都是用锚点来实现的。

**[⬆ top](#什么是-markdown-)**
⬆ top

强调
Markdown 使用星号*和底线_作为标记强调字词的符号。

斜体
*花自飘零水自流*
花自飘零水自流

粗体
**花自飘零水自流**
花自飘零水自流

删除线
~~花自飘零水自流~~
花自飘零水自流

列表
使用 *，+，- 表示无序列表。

无序列表
- 白头吟
- 击鼓
- 断句
白头吟

击鼓

断句

有序列表
有序列表则使用数字接着一个英文句点。

1. 白头吟
2. 击鼓
3. 断句
白头吟

击鼓

断句

包含引用的列表
如果要在列表项目内放进引用，那 > 就需要缩进:

* 菩提偈:

  > 菩提本无树，明镜亦非台。
  > 本来无一物，何处惹尘埃！
菩提偈:

菩提本无树，明镜亦非台。 本来无一物，何处惹尘埃！

插入图片
图片的创建方式与超链接相似, 而且和超链接一样也有两种写法, 行内式和参考式写法。

语法中图片Alt的意思是如果图片因为某些原因不能显示, 就用定义的图片Alt文字来代替图片。 图片Title则和链接中的Title一样, 表示鼠标悬停与图片上时出现的文字。 Alt 和 Title 都不是必须的, 可以省略, 但建议写上。

图片行内式
![图片Alt](图片地址 "图片Title")

![哆啦A梦](https://cdoco.com/images/duolaameng.jpeg "哆啦A梦")
哆啦A梦

图片参考式
在文档要插入图片的地方写 ![图片Alt][标记]。

在文档的最后写上 [标记]:图片地址 "Title"。

![哆啦A梦][duolaameng]

[duolaameng]:https://cdoco.com/images/duolaameng.jpeg "哆啦A梦"
哆啦A梦

表格
不管是哪种方式, 第一行为表头, 第二行分隔表头和主体部分, 第三行开始每一行为一个表格行。
列于列之间用管道符|隔开。原生方式的表格每一行的两边也要有管道符。
第二行还可以为不同的列指定对齐方向。默认为左对齐, 在-右边加上:就右对齐。
简单方式:

诗名|作者|朝代
-|-|-
白头吟|卓文君|两汉
锦瑟|李商隐|唐代
登科后|孟郊|唐代
诗名	作者	朝代
白头吟	卓文君	两汉
锦瑟	李商隐	唐代
登科后	孟郊	唐代
原生方式:

|诗名|作者|朝代|
|-|-|-|
|白头吟|卓文君|两汉|
|锦瑟|李商隐|唐代|
|登科后|孟郊|唐代|
诗名	作者	朝代
白头吟	卓文君	两汉
锦瑟	李商隐	唐代
登科后	孟郊	唐代
为表格第二列指定方向:

诗名|名句
-|-:
梦微之|君埋泉下泥销骨。
上邪|上邪，我欲与君相知，长命无绝衰。
诗名	名句
梦微之	君埋泉下泥销骨。
上邪	上邪，我欲与君相知，长命无绝衰。
代码
对于程序员来说这个功能是必不可少的, 插入程序代码的方式有两种, 一种是利用缩进(Tab), 另一种是利用 "`" 符号(一般在ESC键下方)包裹代码。

插入行内代码, 即插入一个单词或者一句代码的情况，使用 `code` 这样的形式插入。
插入多行代码, 可以使用缩进或者 ``` code ```, 具体看示例。
代码行内式
PHP打印堆栈信息 `debug_backtrace()`。
PHP打印堆栈信息 debug_backtrace()。

缩进式多行代码
缩进 4 个空格或是 1 个制表符。

一个代码区块会一直持续到没有缩进的那一行(或是文件结尾)。

    $closure = function () use($name) {
      return $name;
    }
$closure = function () use($name) {
  return $name;
}
用六个 ` 包裹多行代码
```php
$closure = function () use($name) {
  return $name;
}
` ``
$closure = function () use($name) {
  return $name;
}
HTML 原始码
在代码区块里面, & 、 < 和 > 会自动转成 HTML 实体, 这样的方式让你非常容易使用 Markdown 插入范例用的 HTML 原始码, 只需要复制贴上, 剩下的 Markdown 都会帮你处理，例如:

<table>
    <tr>
        <th rowspan="2">值班人员</th>
        <th>星期一</th>
        <th>星期二</th>
        <th>星期三</th>
    </tr>
    <tr>
        <td>李强</td>
        <td>张明</td>
        <td>王平</td>
    </tr>
</table>
值班人员	星期一	星期二	星期三
李强	张明	王平
内容目录
在段落中填写 [TOC] 以显示全文内容的目录结构。

注脚
在需要添加注脚的文字后加上脚注名字[^注脚名字], 称为加注。 然后在文本的任意位置(一般在最后)添加脚注, 脚注前必须有对应的脚注名字。

使用 Markdown[^1]可以效率的书写文档, 直接转换成 HTML[^2]。

[^1]: Markdown 是一种纯文本标记语言

[^2]: HyperText Markup Language 超文本标记语言
PS: github 不支持注脚 😂

LaTeX 公式
$ 表示行内公式
质能守恒方程可以用一个很简洁的方程式 $E=mc^2$ 来表达。
质能守恒方程可以用一个很简洁的方程式  来表达。

$$ 表示整行公式
$$\sum_{i=1}^n a_i=0$$
$$f(x_1,x_x,\ldots,x_n) = x_1^2 + x_2^2 + \cdots + x_n^2 $$
$$\sum^{j-1}_{k=0}{\widehat{\gamma}_{kj} z_k}$$
PS: github 不支持 LaTeX 公式, 但是有个折中的解决方案, 使用 codecogs, 例如:

![](https://latex.codecogs.com/gif.latex?sum_{i=1}^n%20a_i=0)
![](https://latex.codecogs.com/gif.latex?f\(x_1,x_x,\ldots,x_n\)%20=%20x_1^2%20+%20x_2^2%20+%20\cdots%20+%20x_n^2%20)




流程图
流程图大致分为两段, 第一段是定义元素, 第二段是定义元素之间的走向。

定义元素的语法 tag=>type: content:>url。

tag就是元素名字。
type是这个元素的类型, 有6中类型,分别为:
type	含义
start	开始
end	结束
operation	操作
subroutine	子程序
condition	条件
inputoutput	输入或产出
content 就是在框框中要写的内容, 注意type后的冒号与文本之间一定要有个空格。

用->来连接两个元素, 需要注意的是condition类型, 因为他有yes和no两个分支, 所以要写成:

c2(yes)->io->e
c2(no)->op2->e
```flow
st=>start: Start:>https://www.markdown-syntax.com
io=>inputoutput: verification
op=>operation: Your Operation
cond=>condition: Yes or No?
sub=>subroutine: Your Subroutine
e=>end
st->io->op->cond
cond(yes)->e
cond(no)->sub->io
` ``


PS: github 不支持流程图 😂

时序图
```sequence
Alice->Bob: Hello Bob, how are you ?
Note right of Bob: Bob thinks
Bob-->Alice: I am good thanks!
` ``


PS: github 不支持时序图 😂

待办事宜列表
使用带有 [ ] 或 [x] (未完成或已完成)项的列表语法撰写一个待办事宜列表, 例如:

* [ ] 早起跑步
* [x] 看书
 早起跑步
 看书
⬆ top
参考链接：https://github.com/cdoco/markdown-syntax
https://guides.github.com/features/mastering-markdown/
