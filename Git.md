版本控制的意义：自动记录每次文件的改动，便于管理

工作区：电脑里能看到的目录

其中有一个隐藏目录.git，是Git的版本库，这里存的之一为名为stage的暂存区，以及一个自动创建的分支master，和指向master的指针HEAD



常用命令：

克隆与同步：

git clone	远程仓库地址	用远程库克隆一个本地库

git push -u 远程库名 master	第一次把本地库的当前分支master推送到远程，-u的作用是把本地的master分支和远程的master分支关联起来（也可以是其他分支）

<font style="color:#8A8F8D;">之后使用git push 远程库名 master 即可将本地库的master分支的新修改推送至GitHub（也可以是其他分支）</font>

<font style="color:rgba(0, 0, 0, 0.85);">git pull 远程库名 分支名 	从远程库获取最新的代码到本地，并</font><font style="color:rgba(0, 0, 0, 0.85);background-color:#FBDE28;">会</font><font style="color:rgba(0, 0, 0, 0.85);">与本地的当前分支进行合并，用于同步远程仓库的修改</font>

<font style="color:rgba(0, 0, 0, 0.85);">git fetch 远程库名 [远程分支名：本地分支名]	从远程库获取最新的代码到本地，但</font><font style="color:rgba(0, 0, 0, 0.85);background-color:#FBDE28;">不会</font><font style="color:rgba(0, 0, 0, 0.85);">自动合并到本地的当前工作分支</font>

日常操作：

git add 文件名 		将工作区文件修改添加到暂存区中，可以反复使用git add将多个文件添加到暂存区

git commit		将暂存区的修改提交到仓库中，可以一次性提交多个文件

<font style="color:#8A8F8D;">git commit -m “说明”	将暂存区的修改提交到仓库中，且提供说明</font>

git status			查看当前仓库状态

git rm 文件名		<font style="color:rgba(0, 0, 0, 0.85);">从工作区删除文件，还会将删除操作添加到暂存区，通常和git commit 配合使用，将暂存区的删除操作提交到版本库，彻底从版本库里删文件（不配合git commit 是无法在版本库里也完全删掉文件的）</font>

<font style="color:#8A8F8D;">rm 文件名		直接在文件管理器中删文件，但是删不掉版本库中的文件</font>



查看历史：

git diff 文件名		查看上次是如何修改文件的

git log 			显示从最近到最远的提交日志

<font style="color:#8A8F8D;">git log --pretty=oneline	显示从最近到最远的提交的版本号（commit id）</font>



分支管理：

git branch	查看本地分支，*显示当前分支

git branch 分支名		创建分支，但不切换到新分支

git branch -d 分支名	删除指定分支

git merge 分支名		把指定分支合并到当前分支上

git switch 分支名	切换分支

git checkout 分支名	切换到已有分支

git checkout -b 分支名	创建分支并切换到新创建的分支

<font style="color:#8A8F8D;">无法自动合并时，解决冲突：手动打开冲突文件，查看冲突标记（<<<<<<<,=======,>>>>>>>)，修改文件内容并提交修改（git add，git commit）来完成合并</font>



远程仓库管理：

git remote add origin git@github.com:GitHub账户名/仓库名.git	关联本地仓库与远程仓库,仓库名一般用同一个，origin是默认的远程仓库名，可以改

git remote -v	查看远程库信息

git remote rm 远程库名	删除远程库，本质上是接触本地库与远程库的连接关系，GitHub上的库并没有消失



撤销：

git reset			1.回退到指定版本（本质是指针HEAD的移动）2.把暂存区的修改撤销，重新放回工作区

<font style="color:#8A8F8D;">1.git reset 具体使用：git reset 参数  版本</font>

<font style="color:#8A8F8D;">版本：</font>

<font style="color:#8A8F8D;">HEAD	表示当前版本，即最新版的提交</font>

<font style="color:#8A8F8D;">HEAD^	表示上一版本</font>

<font style="color:#8A8F8D;">HEAD~n	表示往上n个版本</font>

<font style="color:#8A8F8D;">版本号</font>

<font style="color:#8A8F8D;">参数：</font>

<font style="color:#8A8F8D;">--hard	回退到上个版本的已提交状态</font>

<font style="color:#8A8F8D;">--soft	回退到上个版本的未提交状态</font>

<font style="color:#8A8F8D;">--mixed	回退到上个版本已添加但未提交状态</font>

<font style="color:#8A8F8D;">2.git reset 具体使用：git reset HEAD 文件名</font>

git reflog			记录每一次命令，可以在回退错版本之后通过git reflog找到需要的版本号（接着用git reset回到未来）

git checkout		撤销修改 ，误删后还原（如果已经完成了git rm且完成了git commit，则无法还原，因为文件已经彻底从版本库里删掉了）

<font style="color:#8A8F8D;">git checkout -- 文件名	把文件在工作区的修改全部撤销（如果修改已添加到暂存区，则修改撤销至和版本库一模一样的状态：如果文件是已经添加到暂存区后，又做了修改，则撤销修改会回到添加到暂存区后的状态）</font>

git revert 版本号	通过创建一个新的提交来撤销指定提交的修改（适合已经推到远程仓库的提交的撤销）

git stash	将当前工作区中未提交的修改保存起来（暂存区的也保存），以便在其他分支工作或进行其他操作，之后可以用git stash pop恢复之前保存的修改



Rebasing工作流：将本地未push的分叉提交历史整合在一条直线（git rebase）



Pull Request（PR）提交流程：（一种协作机制）

1. Fork 仓库：开发者将原始仓库复制到自己的 GitHub 账户中
2. Clone 仓库：将 Fork 的仓库克隆到本地
3. 修改代码：在本地对代码进行修改
4. Push 修改：将修改后的代码推送到自己的远程仓库
5. 发起 Pull Request：向原始仓库提交合并请求（GitHub界面完成）
6. 代码审查：原始仓库的维护者审查代码并决定是否合并

  
 









