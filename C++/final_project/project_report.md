##                                                                                          C++实训报告

* #### **设计题目：植此青绿**

  姓名：刘胜杰               学号： 202330551041

  班级： 软件工程1班     指导教师：杜卿

* #### **设计报告**

  **1.作品描述**

  ​       本作品为基于最强大脑第十一季第三期的比赛项目“植此青绿”进行复刻并扩展的项目。主要玩法为将题目所给出的若干不同大小的矩阵全部放置到地图的对应位置上，使得地图的每一个格子上的树木数量正确。本项目在实现了原本的能够和地图进行交互、提交答案并上传用户数据、观看用户排行榜的功能的基础上，增添了随机生成地图、用户排行榜多元化、关卡提示、生成题目时写入题库并从题库随机选取题目、基于socket的同一局域网下的单一客户端与服务端进行连接并聊天的聊天室等功能。本作品完全基于Qt6.5.3进行开发。

  

  **2.系统设计说明**

  本项目主要分为四个大模块，分别是练习模式、比赛模式、排行榜、基于socket的联网聊天室。

  对于项目架构：

  ![image-20240526230450600](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240526230450600.png)

  一共定义了十个类，其中，qlwindow为主页面，exermode为练习模式选择关卡页面，level1为练习模式游戏页面，rank_show为排行榜页面，sever_widget和client_widget为聊天室的服务端与客户端，helpword为帮助说明，userbase为用户基类，用于用户字段创建，usertool为游戏交互逻辑会用到的类，contest为比赛模式游戏页面。

  在进入主页面后可选择进入练习模式、比赛模式、排行榜、帮助文档、打开聊天室的服务端与客户端。

  对于游戏交互的核心逻辑，本项目没有使用拖拽，而是采用了通过鼠标点击确定需要放置的矩阵的左上角坐标，然后在点击需要放置的矩阵的按键来实现区间内种树的功能。而对于提交答案判断正误和用户数据的建立逻辑，在这里的设计是在当前关卡提交并判断正确后，跳出QMessageBox供玩家写入用户昵称，根据本关数据创建用户字段。

  

  * **2.1 练习模式**

    练习模式主要由五个基础关卡和一个随机从题库选取题目的关卡组成，游戏关卡的核心生成逻辑均为读取存储地图的txt文件，前五个基础关卡的地图均为加入qrc的txt文件，最后一个关卡随机从题库进行读取的关卡从专门的排行榜文件中进行读取文件并随机选取。

    练习模式是整个游戏模式的基础框架，主要模块包括：关卡矩阵放置功能、撤回功能、重置功能、计时器模块、提交答案并判断正误、创建用户字段并将用户数据写入排行榜。

    关于游戏页面的UI设计，在这里使用了Qt封装好的控件类：QLabel、QPushButton、Qpalette、QMessageBox、QStack、Qvector、QPixmap、QVariant。此外，为了方便实现撤销功能和创建用户字段，使用了自定义类：userbase、cancelbox。

    下面是关键变量：![image-20240527142656728](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527142656728.png)

    页面逻辑的具体实现在设计实现与分析中展开。

  * **2.2 比赛模式**

    比赛模式在套用练习模式的界面UI的基础上（QWidget类：contest），除去了读取地图文件进行游戏地图加载的逻辑，设计了一套随机生成算法进行地图的 生成，并将随机生成的地图写入题库文件夹。此外，考虑到比赛模式可能过于困难，不易做出，在比赛模式中加入了关卡提示功能， 可提示玩家部分矩阵的正确放置位置，降低游玩难度。

    比赛模式的关键变量在练习模式的基础上增添了供随机生成算法使用的部分：

    ![image-20240527142945261](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527142945261.png)

    随机算法的实现在设计实现与分析中展开。

  * **2.3 排行榜**

    在原有的排行榜基础上，本项目的排行榜实现了支持练习模式、比赛模式的两种模式，并且同时在单一模式下可按照id昵称、通关次数、最短通关时间三种排序方式进行排行榜显示的多元化排行榜功能。整体排行榜采用QTableView进行设置，以QStandardItemModel进行用户数据的存放。

    关键变量：

    ![image-20240527143318999](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527143318999.png)

    

  * **2.4 聊天室**

    该聊天室基于QTcpSocket建立,服务端和客户端各占用一个页面，在同一局域网下，服务端开始监听后，在客户端页面输入服务端的IP地址并请求连接。完成链接后客户端和服务端即可在聊天页面进行对话。
    
    关键变量：
    
    客户端：
    
    ![image-20240527222611931](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527222611931.png)
    
    服务端：
    
    ![image-20240527222634173](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527222634173.png)
    
    
    
    

  **3.实现环境**

  本项目完全基于Qt6.5.3进行开发，开发平台为Qt Creator，Kit：Desktop Qt6.5.3 MinGW 64-bit，项目使用CMake进行部署。运行版本需使用Qt自带链接终端运行windeployqt命令将环境依赖装进补全。

  ![image-20240527145235680](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527145235680.png)

  补全环境依赖后exe文件即可运行，打包发送。

  

  **4.设计实现及分析**

  首先是基本页面的切换和背景、大小设置，在本项目中，所有可通过QpushBUtton进行切换的页面都是上一个页面的子成员，在父页面点击后，父页面调用close函数关闭，子页面调用show函数显示，在子页面点击返回后，子页面释放信号back（），父页面接收到信号触发槽函数关闭子页面，显示主页面。

  例如主页面前往练习模式：

  ![image-20240527145854716](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527145854716.png)

  ![image-20240527145915324](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527145915324.png)‘

  ![image-20240527145947892](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527145947892.png)

  ![image-20240527150032459](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527150032459.png)

  对于每个页面的背景和大小设置，以及QWidget的窗口标题和窗口图标：在构造函数中，窗口大小使用setfixedsize进行大小固定，使其不会随鼠标拖动而改变，窗口标题用setIcon传入图片路径，背景使用QPalette调色板进行设置，以练习模式为例：

  ![image-20240527150539137](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527150539137.png)

  呈现的效果如下：

  ![image-20240527150941133](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527150941133.png)

  

  * **4.1 练习模式**

    1.对于矩阵在地图上的放置功能，这里采用的是鼠标点击需放置矩阵的左上角坐标来进行放置位置确认，然后选择矩阵进行放置，这也是游戏交互的核心逻辑，首先定义鼠标事件，在点击后设置selectedlabel并存储坐标：

    ![image-20240527152235130](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527152235130.png)

    然后是点击选择需要放置的矩阵，以4 * 4的矩阵为例，在点击后触发槽函数，先判断selectedlabel是否为空，不为空则判断起点坐标加上矩阵大小是否会越界，不会越界则以selectedlabel为起点进行遍历区间加一，同时设置selectedlabel为空，并将该操作存储进cancelboxer，矩阵剩余数量减一，若selectedlabel为空或者会越界，则跳出QMesageBox提示：

    ![image-20240527153130146](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527153130146.png)

    

    2.对于撤回功能，在点击pushbutton触发槽函数后，先判断存储操作的QStack是否为空，为空则跳QMessageBox提示，不为空则上一次操作出栈，进行区间减一同时矩阵数量加一：

    ![image-20240527155311263](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527155311263.png)

    

    3.对于重置功能，遍历全图将label存储的值初始化为0，同时cancelbox清空，矩阵数量初始化。

    4.对于计时器，使用QTimer设置，当进入游戏子页面的时候，调用子页面的timer的start函数，并设置参数为1000ms，表示每1000ms触发一次timeout信号，当退出页面的时候停止计时，调用stop函数，当需要获取计时数据的时候，使用timer.interval来访问。在页面的显示计时上，先设置connect链接timer的timeout信号和显示时间的槽函数。当每秒触发槽函数时进行时间设置：

    ![image-20240527160133503](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527160133503.png)

    

    5.对于提交答案并判断正误，以及创建用户字段写入数据，点击提交pushbutotn触发槽函数后，先遍历全图进行答案判断，判断标准是用户放置完的每一个格子的数据是否和格子原本存储的数据一致，如果不一致则条跳QMessageBox提示，如果一致则清空cancelbox，停止计时器，跳出写入用户id的提示，在写入id后点击ok后，从Json格式的排行榜文件中读取数据，先使用QByteArray接受文件read读取的数据，然后转化为QJsonDocument变量docread，先判断是否为空，为空即代表文件为空，则创建一个空的QJsonArray，写入新用户数据，然后转化为QJsonDocument，再往文件中write进去；如果docread不为空并且无重名，则将docread转化为QjsonArray，然后往里append用户数据，然后转化为QjsonDocument写入文件；如果docread不为空但有重名，则更新最优数据，创建新的QjsonArray，写入所有用户数据再写入QJsonArray，转化为QJsonDocument再写入文件：

    ![image-20240527162049824](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527162049824.png)

    ![image-20240527162203159](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527162203159.png)

    ![image-20240527162246624](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527162246624.png)

    ![image-20240527162346908](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527162346908.png)

    ![image-20240527162404438](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527162404438.png)

    此外，由于练习模式中设置了六个关卡，五个基础关卡和一个随机题库关卡，为了提高代码复用性，减少冗余代码，练习模式的所有游戏页面均为level1，在点击选择关卡的时候，触发槽函数切换页面前会访问不同文件，根据文件地图数据初始化游戏页面：

    ![image-20240527163407248](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527163407248.png)

    

  * **4.2 比赛模式**

     比赛模式相较于练习模式只做了两点改动，一个是重置按键被设置成了随机生成新地图并写入图库文件夹，一个是增加了提示功能。
    
    1.对于随机生成算法，核心思想为在当前需要放置的矩阵放置之前，对地图进行遍历，枚举所有当前矩阵可放置的合法区域（即防止之后不会出现不合法的情况，如出现两个四或者出现大于四的情况），然后再所有合法区域内随机选取进行放置。这样子虽然单次生成地图的复杂度较高，但是因为不合法而重新生成的次数将大大减少，生成地图更为稳定。
    
    1.1首先设置地图的检查函数，判断地图合法的判断标准是，全图数字小于等于四，并且有且仅有一个四，且全局数字和为44：
    
    ![image-20240527190556776](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527190556776.png)
    
    
    
    1.2对区间进行+1的操作函数，在这里由于后续的地图生成逻辑需要分为已生成四和未生成四的情况，因此需要在出现四的时候进行布尔值更改：
    
    ![image-20240527190751400](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527190751400.png)
    
    
    
    1.3对区间进行检查是否合法的函数，在这里需要进行分类，由于需要保证矩阵放置后依旧是合法的情况，因此在没有出现四的时候，区间合法的判定标准为区间内最多只有一个三，已经出现四了之后，区间合法的判定标准为区间内没有三，这样才能保证放置了矩阵之后地图依旧合法：
    
    ![image-20240527190853715](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527190853715.png)
    
    
    
    1.4  在已给范围内遍历进行合法区间的寻找，首先需要特判区域是否能容纳当前矩阵的大小，不能就返回，然后根据将矩阵的大小的是否已经出现四进行区域遍历，寻找合法区间，然后将所有合法区间放进vector内，特别的，虽然这个区间判定可能出现将四的单位划定为一的合法区间的情况，但是考虑到1/36的概率，并且即便不合法也可重新生成，在这里不单独对一进行处理：
    
    ![image-20240527191145558](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527191145558.png)
    
    
    
    1.5  区间寻找范围的划定，对于还没出现四的时候，寻找范围即为全局，因为全局都可能出现四；对于已经出现四的情况，寻找范围为全局除开四的单位以外组成的“回”字的四条边，这样能保证不会出现数字大于四的情况，特别地，当四处于地图边界的时候，只有一个或两个区间或三个范围是有效的，不影响寻找范围的划定，因为不合法的范围在上一个函数开始部分return了：
    
    ![image-20240527191251235](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527191251235.png)
    
    
    
    1.6  地图生成函数，开头设置随机数种子，在生成时逐个取出需放置矩阵，并进行合法区间的寻找，如果没有合法区间，即当前地图生成已失效，则跳出循环重新开始。然后用rand函数进行随机选取并放置，每次操作完一个矩阵将存储当前矩阵的合法区间的vector给clear。生成完成后根据地图的单位数字进行图片粘贴，在比赛模式里，将0和2的图标统一为⭕：
    
    ![image-20240527191740868](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527191740868.png)
    
    ![image-20240527191830705](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527191830705.png)
    
    地图生成效果如下：
    
    ![image-20240527193329509](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527193329509.png)
    
    经验证地图合法有解。
    
    
    
    2.写入题库文件夹
    
    在随机生成算法生成新地图后，调用生成新地图文件的函数来写入地图文件：
    
    ![image-20240527192415328](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527192415328.png)
    
    然后是在练习模式设置题库题目的抽取并加载文件，首先获取文件夹路径，然后获取文件夹路径下的文件列表，并基于文件数量进行随机选取，然后调用游戏页面的loadfile函数进行地图加载：
    
    ![image-20240527192638910](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527192638910.png)
    
    题库文件夹效果如下：
    
    ![image-20240527192803787](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527192803787.png)
    
    
    
    3.提示功能设置
    
    由于在比赛模式中，难度可能过高，但考虑到每一步都进行提示不符合游戏逻辑，并且倘若玩家策略错误会导致实时提示逻辑过于复杂，因此只制作了对于当前地图的4*4的地图的位置提示，即提示4 * 4地图的左上角坐标。
    
    基本逻辑为，在上一周设计的随机生成算法里，当地图为4 *4时，记录下所选取的随机合法区间的左上角坐标，并使用QMessageBox提示：
    
    ![image-20240527193150249](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527193150249.png)
    
    效果如下：
    
    ![image-20240527193235029](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527193235029.png)
    
    

* **4.3 排行榜**

  排行榜显示的核心逻辑是，点击”普通模式“和“比赛模式”可以切换读取的Json排行榜文件，读取文件并将文件中存储的用户数据使用QVector存储：

  ![image-20240527195247839](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527195247839.png)

  

  然后点击不同的pushbutton进行不同的排序：

  ![image-20240527195357302](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527195357302.png)

  然后设置由QTableView管理的QStandardItemMode  ，在这里，每一个用户数据条目都是一个item，在usermodel中添加进去并设置相对位置即可显示出来。并且在这里对每个排行条目进行了样式设置，设置了字体和大小，并设置了文本居中。：

  ![image-20240527195603187](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527195603187.png)

  关于tableview的样式设置，在这里使用了setstylesheet函数进行CSS样式设置：

  ![image-20240527195823523](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527195823523.png)

  效果如下：

  ![image-20240527195848440](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527195848440.png)

  

* **4.4 基于socket的服务端与客户端单线连接的聊天室**

  本项目聊天室基于Tcp协议进行通信，核心模块为QTcpSocket。本项目在设计上支持单一客户端与服务端在同一局域网下进行通信。
  
  socket通信原理：socket是应用层与TCP/IP协议族通信的中间软件抽象层，它是一组接口。在设计模式中，socket其实就是一个门面模式，它把复杂的TCP/IP协议族隐藏在socket接口后面，对用户来说，一组简单的接口就是全部，让socket去组织数据，以符合指定的协议。
  
  Tcp通信建立连接的过程，被称为“三次握手”，即客户端向服务器发送一个SYN J，服务器向客户端响应一个SYN K，并对SYN J进行确认ACK J+1，客户端再向服务器发一个确认ACK K+1，完成三次握手之后，客户端和服务端建立起了链接。在QTcpSocket中，这个过程被封装为了客户端的connecttoHost函数和服务端的listen函数，在服务端开始listen后，客户端调用connecttoHost函数发起连接请求。
  
  而Tcp通信连接断开的过程被称为“四次挥手”，具体过程为：某个应用进程首先调用close主动关闭连接，这时TCP发送一个FIN M，
  另一端接收到FIN M之后，执行被动关闭，对这个FIN进行确认。它的接收也作为文件结束符传递给应用进程，因为FIN的接收意味着应用进程在相应的连接上再也接收不到额外数据。一段时间之后，接收到文件结束符的应用进程调用close关闭它的socket。这导致它的TCP也发送一个FIN N，接收到这个FIN的源发送端TCP对它进行确认。这样每个方向上都有一个FIN和ACK。对于QTcpSocket，对应的函数是disconnectFromHost，对于QTcpServer，对应的函数是close。
  
  对于建立连接后，聊天室的发送信息的过程，主要模块是write函数。当某一端使用了write函数发送信息后，该信息被写入了操作系统的写缓冲区，然后由系统内核读取了写缓冲区的数据后发送给另一端的读缓冲区，另一端调用read函数读取数据。
  
  
  
  1.客户端
  
  首先发起连接请求，在这里服务器地址需要手动输入：
  
  ![image-20240527225141469](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527225141469.png)
  
  在连接成功后会触发槽函数，进行控件权限的设置更改：
  
  ![image-20240527225237782](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527225237782.png)
  
  ![image-20240527225457637](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527225457637.png)
  
  断开连接同理，断开后会清空本机聊天框内容：
  
  ![image-20240527225529603](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527225529603.png)
  
  连接成功后，需要进行发送信息，在输入栏输入信息后，点击发送触发槽函数发送信息：
  
  ![image-20240527225735127](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527225735127.png)
  
  ![image-20240527225756584](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527225756584.png)
  
  在此基础上，添加了回车键的事件过滤器，在button_send的isenabled值为true的情况下按下回车即可发送信息：
  
  ![image-20240527225947331](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527225947331.png)
  
  对于接受到来自服务端的信息，当信息被传输到客户端的读缓冲区时，会触发readyRead信号，调用槽函数读取数据并显示在聊天框上：
  
  ![image-20240527231033559](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527231033559.png)
  
  
  
  2.服务端
  
  对于服务端，首先需要开始监听可能出现的连接请求：
  
  ![image-20240527232111398](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527232111398.png)
  
  其中，对于本机的ip获取，设置了专门的函数：首先需要获取系统上所有网络接口的IP地址列表，然后遍历这个地址列表，找到第一个非回环ipv4地址并返回，找不到则返回127.0.0.1作为本机回环地址：
  
  ![image-20240527232711148](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527232711148.png)
  
  监听到客户端连接请求，需要对请求进行处理，触发槽函数：
  
  ![image-20240527233345788](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527233345788.png)
  
  
  
  对于发送信息，大体逻辑与客户端一致，不过需要注意的是，  在这里，当服务端发送信息的时候，遍历服务端维护的每个客户端的QTcpSocket对象，这个QTcpSocket对象是服务端维护的服务端与客户端的特定链接，由这个QTcpSocket对象调用write函数，将信息写入服务端与该对应客户端的发送缓冲区：
  
  ![image-20240527232915704](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527232915704.png)
  
  在这里，发送信息时服务端与客户端的显示信息函数与回车事件过滤器一致。
  
  当服务端读缓冲区接收到某一客户端发来的信息时，会触发槽函数进行文本显示，在这里sender（）返回触发readyread信号的对象基类QObject指针，使用qobject_cast<QTcpSocket*>(sender());将该指针转化为QTcpSocket类型的指针，如果转化失败则返回空指针。与sendmessage同理在这里clientsocket代表服务端维护的服务端与对应客户端的连接，当客户端给服务端发送信息后，该链接的读缓冲区接收到了信息，然后调用readall读取信息并显示在服务端的聊天框。：
  
  ![image-20240527233650567](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527233650567.png)
  
  当客户端断开连接后，服务端会删除对应链接：
  
  ![image-20240527233856247](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527233856247.png)
  
  停止监听后更改控件属性并关闭QTcpServer：
  
  ![image-20240527233958654](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527233958654.png)
  
  最后的通信效果如下：
  
  ![image-20240527234114654](C:\Users\LSJ\AppData\Roaming\Typora\typora-user-images\image-20240527234114654.png)



**反思与总结**

1.本项目代码行数超过3000行，但是由于最开始项目架构没有思考清楚，比赛模式和练习模式使用同一套UI导致了大量的代码重复，十分冗余，应该在最开始设置一个页面基类，然后再两个模式中继承并扩展，这样子可以减少约六百行代码，大大提高简洁性。

2.其实做到中间比赛模式的时候卡了很久，刚开始因为随机生成算法的rand（）函数使用不当导致大量不合法情况从而阻塞了UI线程（大约200-500ms没有跑出来），后面不想着优化算法，转头去研究起了多线程能否解决算法超时导致的UI线程阻塞的问题，但是在这里卡住了一个星期，线程资源泄露的问题一直没有得到解决，后面也就放弃了这个方案，开始重构起随机生成算法。刚开始针对rand的用法构思了一个每一个位置都在上一个矩阵的位置的小范围区间内随机生成，但是效果也不理想，且随机范围的参数调节过于复杂，也放弃了这个方案。最后想到超时的问题是因为不合法情况过多，想到能否牺牲单次生成的复杂度来换取不合法情况的大量减少，即算法的核心思想从完全随机变成了类搜索问题，枚举区间。最后实现花了一天debug了一天后问题迎刃而解。

3.关于排行榜的样式设置，刚开始由于对CSS不熟悉导致表格的样式设置一直不成功，浪费了很长时间，后来才发现是因为设置对象的某一处语法有多余部分。

4.关于聊天室，这是整个项目最有技术含量也最遗憾的地方，本来最初设想通过联网能够做出玩家间的文件传输，但是由于文件传输方面的封装性不高，需要手动造轮子的地方较多，对计算机网络的知识了解不多，实现起来较为困难，又碍于时间原因只能作罢。此外，虽然聊天室服务端的代码设置是可以访问个客户端，但客户端设置上只能和服务端进行单线通信，没有实现服务端对多个客户端的通信，实属遗憾。

5.虽然本项目的诟病颇多，但是面向项目需求进行学习的过程让我受益匪浅，体会到了开发的漫长和针对某一个模块的难点攻关的艰辛，感受到了在茫茫资料中寻找那一点自己所需要的内容的疲惫，但是解决了问题也让自己的经验增长了，也借此机会学习了部分计算机网络相关的知识，收获颇多。

