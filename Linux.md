(一）Linux目录结构

1.目录介绍

Linux的文件系统采用级层式树状目录结构，最上层为根目录“/ ”，在此目录下在创建其他目录

<font style="background-color:#FBDE28;">/bin （/usr/bin,/usr/local/bin)  存放常用指令</font>

/sbin （/usr/sbin,/usr/local/sbin)  存放系统管理员用的系统管理程序

<font style="background-color:#FBDE28;">/home 存放普通用户的主目录，每个用户有自己的目录，一般以用户的账号名命名</font>

<font style="background-color:#FBDE28;">/root  系统管理员的用户主目录</font>

/lib 系统开机所需的最基本的动态连接共享库。几乎所有应用程序都需要用到这些共享库（删了之后很多应用程序无法启动）

/lost+found 一般为空，当系统非法关机后，里面就存放一些文件

<font style="background-color:#FBDE28;">/etc 所有系统管理所需要的配置文件和子目录</font>

<font style="background-color:#FBDE28;">/usr  存放用户的应用程序和文件</font>

<font style="background-color:#FBDE28;">/boot 存放Linux启动时使用的核心文件，包括连接文件和镜像文件（动了则无法启动Linux）</font>

/proc 虚拟目录，是系统内存的映射，访问可得系统信息（不能动）

/srv  存放服务器启动后需要提取的数据（不能动）

 /sys 安装了Linux2.6内核中新出现的文件系统sysfs（不能动）

/tmp 存放临时文件

/dev 把硬件以文件形式存储（一切皆文件）

<font style="background-color:#FBDE28;">/media Linux自动识别u盘、光驱等设备后挂载到该目录下</font>

<font style="background-color:#FBDE28;">/mnt 让用户临时挂载别的文件系统，例如可以将外部存储挂载在/mnt/上，进入该目录即可查看里面的内容</font>

/opt 主机额外安装软件所存放的目录，默认为空（一般把安装文件放在/opt下）

<font style="color:#262626;background-color:#FBDE28;">/usr/local主机额外安装软件所安装的目录，一般是通过编译源码方式安装的程序（软件安好了后存放的位置）</font>

<font style="background-color:#FBDE28;">/var存放着在不断扩充的东西，习惯将经常被修改的目录放在此目录下，包括各种日志文件</font>

/selinux SE Linux是一种安全子系统，控制程序只能访问特定文件，有三种工作模式，可以自行设置

<font style="background-color:#74B602;"></font>

<font style="background-color:#74B602;">一切皆文件：硬件，网络等都被映射成文件进行管理</font>

2.绝对路径：始终以根目录（/）为起点，到目标文件的路径

查看当前路径的绝对路径“pwd”

3.相对路径：以当前文件为起点，到目标文件的路径

.\文件  在当前文件下找指定文件

..\文件  在当前文件的上一级文件下找指定文件



（二）Vim编辑器

正常模式:（默认）”上下左右“移光标，“删除字符”“删除整行”处理档案内容，“复制粘贴”处理文件数据

插入模式：可以写内容

命令行模式

<font style="background-color:#FBDE28;">三种模式相互切换</font>

![画板](https://cdn.nlark.com/yuque/0/2025/jpeg/61471817/1760328418913-0efe8dea-f58d-43c3-abab-9d672c011533.jpeg)

<font style="background-color:#FBDE28;">vim快捷键</font>

（正常模式）1.拷贝当前行“yy”,拷贝当前向下n行“nyy”，粘贴“p“

2.删除当前行”dd“，删除当前向下n行”ndd“

3.编辑文件，使用”G“到该文档最末行，”gg“到最首行

4.撤销动作 ”u“

5.编辑文件，快速将光标定位到第n行”输入n，再按shift+g“



（命令行模式）1.在文件中查找某个单词  ”关键字+回车“ （查找前需要”/“从正常模式切换成命令行模式），再输入n可以查找下一个

    2.打开文件的行号 ”set nu“ 关闭文件行号”set nonu“

    3.保存 ”w“

    4.退出 ”q“

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760328221720-3c8f4a38-5a6c-4778-9d27-0bbf20500fa5.png)



（三）终端命令

文件管理：

cp：复制文件或目录 用法：cp source_file destination_file（复制文件）cp -r source_dir destination_dir(复制目录）

mv:移动文件或目录，重命名文件或目录 用法：mv old_filename new_fliename(重命名文件）mv file new_location（移动文件到新位置）

rm: 删除文件或目录 用法：rm file（删除文件）rm -r dir（删除目录）

ls：列出目录下的内容 用法：ls （列出当前目录下的内容）  ls -l （以长格式显示当前目录下的内容，包含大小，权限，作者）  ls -a （<font style="color:rgba(0, 0, 0, 0.85);">当前目录文件和目录，包括隐藏文件）</font>

<font style="color:rgba(0, 0, 0, 0.85);">touch：创建空文件或更新已有文件的访问和修改时间 用法：touch file（原先不存在filejiu生成空文件，存在就更新访问）</font>

<font style="color:rgba(0, 0, 0, 0.85);"></font>

软件安装：

apt：安装，更新，卸载软件包 用法：apt install 软件包名（ 安装软件包）apt update（更新软件包列表）apt upgrade（升级已安装的软件包）apt remove 软件包名（卸载）

snap：对新型软件包格式snap进行操作，该格式的软件在不同linux版本一致运行 用法：snap install snap软件包名（安装）snap remove snap软件包名（卸载）



权限管理：

chmod：改变文件或目录的权限 用法：chmod 权限 文件名

<font style="color:#8A8F8D;">权限：rwx（读，写，执行），rw-（读写），r-x，r--，-wx，-w-，--x，---（无权限）</font>

进程控制：

ps：查看当前系统的进程状态，ps aux可查看所有用户的进程信息

kill：终止进程 用法：kill 进程名(终止特定进程）

top：实时显示系统中各个进程的资源占用情况

systemctl：用于管理系统服务

操作：systemctl start 服务名 启动服务

    systemctl stop 服务名 停止服务

    systemctl restart 服务名 重启服务

    systemctl enable 服务名 设置服务开机自启

    systemctl disable 服务名 关闭开机自启

    systemctl status 服务名 查看服务状态

其他：

vim：文本编辑器，”vim 文件名“可以打开指定文本文件或新创建文本文件并进入Vim编辑器中进行操作

tmux：使单个终端中可以创建多个会话，互不打扰

tmux new -s 会话名（新建会话）

tmux ls （查看所有会话）

tmux kill -s 会话名（关闭会话）

grep：搜索特定文本

grep <可选操作> 关键字 文件名（在指定文件中搜索关键字）

可选操作：-i（忽略大小写查找），-r（通过递归方式搜索目录下的所有文件，找到关键字，此时文件名的位置应输入目录名），-n（搜索完成后显示关键字所在行的行号），-v(搜索完成后显示不包含关键字的行）

awk：对文本进行处理。读入文本后先按指定分隔符（默认空格和tab）将每行文本拆成字段，然后根据特定模式和动作对字段做处理。

awk ‘模式 { 动作 }’文件名

<font style="color:#8A8F8D;">模式：指定awk对输入的文本进行处理的条件，如行号，关系表达式等，如果模式省略不写，则默认对输入的文本的每一行都执行“动作”</font>

<font style="color:#8A8F8D;">常见模式：1.模式省略不写，则默认对输入的文本的每一行都执行“动作”</font>

<font style="color:#8A8F8D;">    	2.NR == n（n为行号）（可以改成其他关系表达式>,<等，可结合	&&，||，！使用）</font>

<font style="color:#8A8F8D;">    	3.正则表达式“/文本/”（当某行含有和正则表达式匹配的文本时，对该行做”动作“）</font>

<font style="color:#8A8F8D;">    	4.$n(表示每行的第n个字段，可以结合条件表达式和&&，||，！等使用）（$0表示一整行）</font>

<font style="color:#8A8F8D;">   	5.BEGIN	</font><font style="color:#8A8F8D;">在处理输入文件之前，先执行</font>`<font style="color:#8A8F8D;">BEGIN</font>`<font style="color:#8A8F8D;">模式对应的动作块。可以初始化awk内置变量、设置字段分隔符</font>

<font style="color:#8A8F8D;">   	6.END 	在处理完输入文件的所有行之后，执行</font>`<font style="color:#8A8F8D;">END</font>`<font style="color:#8A8F8D;">模式对应的动作块</font>

<font style="color:#8A8F8D;">动作：print $n/$0/变量	(打印）</font>

<font style="color:#8A8F8D;">    printf ”...%d...%s...\n",$1,$2	（格式化打印，同C）</font>

<font style="color:#8A8F8D;">    变量赋值和运算</font>

<font style="color:#8A8F8D;">    条件判断</font>

<font style="color:#8A8F8D;">    循环</font>

<font style="color:#8A8F8D;">    数组操作</font>

<font style="color:#8A8F8D;">    函数操作</font>

<font style="color:#8A8F8D;">    文件操作（比如将特定字段打印到特定文件中）</font>

sed：以行为单位处理文本

sed ‘命令‘ 文件名

<font style="color:#8A8F8D;">常见命令：</font>

<font style="color:#8A8F8D;">s：替换	‘s/关键字1/关键字2/（g）’把关键字1替换成关键字2，g表示全局替换，没有g就只对每行的第一个关键字1做替换</font>

<font style="color:#8A8F8D;">d:删除	‘nd’删除第n行</font>

<font style="color:#8A8F8D;">‘/关键字/d' 删除含关键字的行</font>

<font style="color:#8A8F8D;">i:插入	’ni\特定内容‘ 在第n行前插入一行特定内容</font>



（四）基于systemd服务管理与网络配置

<font style="color:#8A8F8D;">systemd：Linux的服务管理器，可以管理服务的开启，关闭，重启等</font>

服务管理：基础操作见（三）中systemctl系列指令

网络配置：systemd通过systemd-network组件管理网络

1.网络接口配置

网络接口文件创建于/etc/system/network/下

启动system-network：systemctl start systemd-network

    systemctl enable systemd-network（开机自启）

启动后自动管理网络接口

查看网络配置：ifconfig

2.网络接口管理

查看网络接口状态：ip addr show（查看所有网络接口的ip地址）

     ip link show （查看网络接口连接状态）

启用网络接口：ip link set 接口名 up

关闭网络接口：ip link set 接口名 down

















<font style="color:rgba(0, 0, 0, 0.85);"></font>

<font style="color:rgba(0, 0, 0, 0.85);"></font>



 





