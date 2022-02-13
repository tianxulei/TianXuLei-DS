/*
 * crtsurfdata5.cpp 用于生成全国气象站点观测的分钟数据
 * 田旭雷
*/

#include "_public.h"

//全国气象站点数据结构体
struct st_stcode
{
  char provname[31];    //省
  char obtid[11];       //站号
  char obtname[31];     //站名
  double lat;           //纬度
  double lon;           //经度
  double height;        //海拔高度
};


//存放全国气象站点参数的容器
vector<struct st_stcode> vstcode;

//把站点参数文件加载到vstcode容器中
bool LoadSTCode(const char *inifile);

//全国气象站点分钟观测数据结构
struct st_surfdata
{
  char obtid[11];       //站点代码
  char ddatetime[21];   //数据时间：格式yyyymmddhh24miss
  int t;                //气温：单位，0.1摄氏度
  int p;                //气压：0.1百帕。
  int u;                //相对湿度，0-100之间的值
  int wd;               //风向，0-360之间的值
  int wf;               //风速：单位0.1m/s
  int r;                //降雨量：0.1mm
  int vis;              //能见度：0.1米
};

//存放各站点分钟观测数据的容器
vector<struct st_surfdata> vsurfdata;

//模拟生成全国气象站点分钟观测数据，存放在vsurfdata容器中;
void CrtSurData();

//把容器vsurfdata中的全国气象站点分钟观测数据写入文件
bool CrtSurfFile(const char *outpath,const char *datafmt);

CLogFile logfile;//日志类

int main(int argc,char *argv[])
{
  //inifile outpath logfile
  if(argc!=5)
  {
    printf("Using:./crtsurfdata5 inifile outpath logfile datafmt\n");

    printf("inifile 全国气象站点参数文件名。 \n");
    printf("outpath 全国气象站点参数文件名。 \n");
    printf("logfile 全国气象站点参数文件名。 \n");
    printf("datafmt 生成数据文件的格式，支持xml,json和csv三种格式，中间用逗号分隔 \n\n");

    return -1;
  }

  //这是日志文件打开失败
  if(logfile.Open(argv[3],"a+",false)==false)
  {
    printf("logfile.Open(%s) failed.\n",argv[3]);
    return -1;
  }

  logfile.Write("crtsurfdata5 开始运行。 \n");

  //这里插入业务代码

  //把站点参数存入vstcode容器，若文件打开失败，则返回
  if(LoadSTCode(argv[1])==false) return -1;

  //模拟生成全国气象站点分钟观测数据，存放在vsurfdata容器中;
  CrtSurData();

  //把容器vsurfdata里的分钟观测数据写入文件
  if(strstr(argv[4],"xml")!=0) CrtSurfFile(argv[2],"xml");
  if(strstr(argv[4],"json")!=0) CrtSurfFile(argv[2],"json");
  if(strstr(argv[4],"csv")!=0) CrtSurfFile(argv[2],"csv");

  logfile.Write("crtsurfdata5 运行结束。 \n");

  return 0;
}

//把文件中的站点参数写入容器vstcode
bool LoadSTCode(const char *inifile)
{
  CFile File;

  //打开站点参数文件
  if(File.Open(inifile,"r")==false)
  {
    logfile.Write("File.Open(%s) failed.\n",inifile);
    return false;
  }

  char strBuffer[301];

  CCmdStr CmdStr;//字符串拆分框架
  struct st_stcode stcode;//存储拆分后内容

  while(true)
  {
    //从站点文件读取一行
    if(File.Fgets(strBuffer,300,true)==false) break;

    //拆分读取内容
    CmdStr.SplitToCmd(strBuffer,",",true);
    if(CmdStr.CmdCount()!=6) continue;//去掉无效的第一行

    //把拆分结果存入结构体
    CmdStr.GetValue(0, stcode.provname,30);
    CmdStr.GetValue(1, stcode.obtid,10);
    CmdStr.GetValue(2, stcode.obtname,30);
    CmdStr.GetValue(3,&stcode.lat);
    CmdStr.GetValue(4,&stcode.lon);
    CmdStr.GetValue(5,&stcode.height);
    //结构体加入容器
    vstcode.push_back(stcode);
  }
  /*
  for(int ii=0;ii<vstcode.size();ii++)
    logfile.Write("provname=%s,height=%.2f\n",vstcode[ii].provname,vstcode[ii].height);
  */

  return true;
}

//模拟生成全国气象站点分钟观测数据，存放在vsurfdata容器中;
void CrtSurData()
{
  //播随机数种子
  srand(time(0));

  //获取当前时间，当作观测时间
  memset(strddatetime,0,sizeof(strddatetime));
  LocalTime(strddatetime,"yyyymmddhh24miss");

  //定义一个结构体变量
  struct st_surfdata stsurfdata;

  //遍历气象站参数的vscode容器
  for(int ii=0;ii<vstcode.size();ii++)
  {
    memset(&stsurfdata,0,sizeof(struct st_surfdata));

    //用随机数填充观测数据结构体
    strncpy(stsurfdata.obtid,vstcode[ii].obtid,10);     //站点代码
    strncpy(stsurfdata.ddatetime,strddatetime,14);      //数据时间：格式yyyymmddhh24miss
    stsurfdata.t=rand()%351;            //气温：单位，0.1摄氏度
    stsurfdata.p=rand()%265+10000;      //气压：0.1百帕。
    stsurfdata.u=rand()%100+1;          //相对湿度，0-100之间的值
    stsurfdata.wd=rand()%360;           //风向，0-360之间的值
    stsurfdata.wf=rand()%150;           //风速：单位0.1m/s
    stsurfdata.r=rand()%16;             //降雨量：0.1mm
    stsurfdata.vis=rand()%5001+100000;  //能见度：0.1米

    //把观测数据结构体放入vsurfdata容器
    vsurfdata.push_back(stsurfdata);
  }
}

//把容器vsurfdata中的全国气象站点分钟观测数据写入文件
bool CrtSurfFile(const char *outpath,const char *datafmt)
{
  CFile File;

  //拼接生成数据的文件名，例如:SURF_ZH_20210629092200_2254.csv
  char strFileName[301];
  sprintf(strFileName,"%s/SURF_ZH_%s_%d.%s",outpath,strddatetime,getpid(),datafmt);

  //打开文件
  if(File.OpenForRename(strFileName,"w")==false)
  {
    logfile.Write("File.OpenForRename(%s) failed.\n",strFileName);
    return false;
  }

  //写入第一行标题
  if(strcmp(datafmt,"csv")==0)
    File.Fprintf("站点代码，数据时间，气温，气压，相对湿度，风向，风速，降雨量，能见度\n");
  if(strcmp(datafmt,"xml")==0)
    File.Fprintf("<data>\n");
  if(strcmp(datafmt,"json")==0)
    File.Fprintf("{\"data\":[\n");

  //遍历vsurfdata容器，写入文件
  for(int ii=0;ii<vsurfdata.size();ii++)
  {
    if(strcmp(datafmt,"csv")==0)
    {
      File.Fprintf("%s,%s,%.1f,%.1f,%d,%d,%.1f,%.1f,%.1f\n",\
                    vsurfdata[ii].obtid,vsurfdata[ii].ddatetime,vsurfdata[ii].t/10.0,\
                    vsurfdata[ii].p/10.0,vsurfdata[ii].u,vsurfdata[ii].wd,\
                    vsurfdata[ii].wf/10.0,vsurfdata[ii].r/10.0,vsurfdata[ii].vis/10.0);
    }

    if(strcmp(datafmt,"xml")==0)
    {
      File.Fprintf("<obtid>%s</obtid><ddatetime>%s</ddatetime><t>%.1f</t>"\
                   "<p>%.1f</p><u>%d</u><wd>%d</wd><wf>%.1f</wf><r>%.1f</r><vis>%.1f</vis><endl/>\n",\
                    vsurfdata[ii].obtid,vsurfdata[ii].ddatetime,vsurfdata[ii].t/10.0,\
                    vsurfdata[ii].p/10.0,vsurfdata[ii].u,vsurfdata[ii].wd,\
                    vsurfdata[ii].wf/10.0,vsurfdata[ii].r/10.0,vsurfdata[ii].vis/10.0);
    }

    if(strcmp(datafmt,"json")==0)
    {
      File.Fprintf("{\"obtid\":\"%s\",\"ddatetime\":\"%s\",\"t\":\"%.1f\","\
                   "\"p\":\"%.1f\",\"u\":\"%d\",\"wd\":\"%d\",\"f\":\"%.1f\","\
                   "\"r\":\"%.1f\",\"vis\":\"%.1f\"}",\
                    vsurfdata[ii].obtid,vsurfdata[ii].ddatetime,vsurfdata[ii].t/10.0,\
                    vsurfdata[ii].p/10.0,vsurfdata[ii].u,vsurfdata[ii].wd,\
                    vsurfdata[ii].wf/10.0,vsurfdata[ii].r/10.0,vsurfdata[ii].vis/10.0);
    }
    if(ii<vsurfdata.size()-1) File.Fprintf(",\n");
    else File.Fprintf("\n");
  }

  if(strcmp(datafmt,"xml")==0)
    File.Fprintf("</data>\n");
  if(strcmp(datafmt,"json")==0)
    File.Fprintf("]}\n");

  //关闭文件
  File.CloseAndRename();

  logfile.Write("生成数据文件%s成功，数据时间%s，记录数%d\n",strFileName,strddatetime,vsurfdata.size());

  return true;
}

//makefile文件

#开发框架头文件路径
PUBINCL = -I/project/public

#开发框架cpp文件名，这里直接包含进来，没有采用链接库，是为了方便调试
PUBCPP = /project/public/_public.cpp

#编译参数
CFLAGS = -g

all:crtsurfdata1 crtsurfdata2 crtsurfdata3 crtsurfdata4 crtsurfdata5

crtsurfdata1:crtsurfdata1.cpp
        g++ $(CFLAGS) -o crtsurfdata1 crtsurfdata1.cpp $(PUBINCL) $(PUBCPP) -lm -lc
        cp crtsurfdata1 ../bin/.

crtsurfdata1:crtsurfdata2.cpp
        g++ $(CFLAGS) -o crtsurfdata2 crtsurfdata2.cpp $(PUBINCL) $(PUBCPP) -lm -lc
        cp crtsurfdata2 ../bin/.

crtsurfdata3:crtsurfdata3.cpp
        g++ $(CFLAGS) -o crtsurfdata3 crtsurfdata3.cpp $(PUBINCL) $(PUBCPP) -lm -lc
        cp crtsurfdata3 ../bin/.

crtsurfdata4:crtsurfdata4.cpp
        g++ $(CFLAGS) -o crtsurfdata4 crtsurfdata4.cpp $(PUBINCL) $(PUBCPP) -lm -lc
        cp crtsurfdata4 ../bin/.

crtsurfdata5:crtsurfdata5.cpp
        g++ $(CFLAGS) -o crtsurfdata5 crtsurfdata5.cpp $(PUBINCL) $(PUBCPP) -lm -lc
        cp crtsurfdata5 ../bin/.

clean:
        rm crtsurfdata1 crtsurfdata2 crtsurfdata3 crtsurfdata4 crtsurfdata5
~                                                                               
