#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
int main(){
	srand(time(0));
	printf("信息查询机\n请输入你的名字(拼音全名)和学号：");
	string s;
	int n;
	cin>>s>>n;
	printf("本程序仅供娱乐，不负任何法律责任"); 
	printf("\n请选择你要查询的信息：\n基础信息请按1\n成绩查询请按2\ncp查询请按3(本查询模式仅限3班)\n未来职业查询请按4\n全方面个人档案请按5\n请输入：");
	int a;
	cin>>a;
	if(a==1){
		printf("你已打开基础信息界面：\n");
		printf("年龄：%d岁\n",(rand()%s.size())*(rand()%10)+1);
		printf("身高：%dcm\n",rand()%100+100);
		if(rand()%2==1){
			printf("性别：男\n");
			printf("体重：%dkg\n",rand()%70+35);
		}
		else{
			printf("性别：女\n");
			printf("体重：%dkg\n",rand()%55+30); 
		}
		printf("智商：%d",rand()%150+50);
	}
	if(a==2){
		printf("你已打开成绩查询界面：\n");
		printf("语文：%d\n",rand()%41+rand()%51);
		printf("数学：%d\n",rand()%41+rand()%61);
		printf("英语：%d\n",rand()%51+rand()%51);
		printf("历史：%d\n",rand()%51+rand()%51);
		printf("地理：%d\n",rand()%51+rand()%51);
		printf("音乐：%d\n",rand()%61+rand()%36);
		printf("体育：%d\n",rand()%51+rand()%46);
	} 
	if(a==3){
		printf("你已打开CP查询界面：\n");
		if(n==15)printf("TA的CP是中一3班5号");
		else if(n==19)printf("TA的CP是中一3班1号");
		else if(n==37|n==14|n==22)printf("TA的CP是中一3班3号");
		else if(n==27)printf("TA的CP是中一6班陈可");
		else if(n==31)printf("TA没有CP，不像别人那样早恋");
		else if(n==34)printf("TA的CP是李玥怡，每个月都要互发情书");
		else if(n==5)printf("TA的CP是中一3班15号");
		else if(n==1)printf("TA的CP是中一3班19号");
		else if(n==3)printf("TA的CP是中一3班37号，14号，22号");
		else{
			if(n<=13){
				int l;
				l=rand()%13;
				if(l>6)printf("TA的CP是中一3班");
				else if(l==0)printf("TA还是只没人要的单身狗");
				else printf("TA的CP是中一%d班",l); 
				if(l!=0)printf("%d号",rand()%31+15);
			}
			if(n>13){
				int ll;
				ll=rand()%13;
				if(ll>6)printf("TA的CP是中一3班");
				else if(ll==0)printf("TA还是只没人要的单身狗");
				else printf("TA的CP是中一%d班",ll); 
				if(ll!=0)printf("%d号",rand()%12+1);
			}
		}
		printf("\n(哈哈！磕到了[吗]？)");
	}
	if(a==4){
		printf("你已打开未来职业查询界面：\n仅前25名隐藏级职业有位次，其余普通职业仅有等级之分,除前25名职业，共有9个等级\n你的职业等级和职业名称：\n");
		int aaa=abs(rand()%1001-rand()%1001);
		if(aaa>998)printf("国家总统(第1位次)");
		else if(aaa>996)printf("国家总理(第2位次)");
		else if(aaa>994)printf("国家高级官员(第3位次)");
		else if(aaa>992)printf("国家各部门总部长(第4位次)");
		else if(aaa>990)printf("国家科学院院士(第5位次)");
		else if(aaa>988)printf("省长(第6位次)");
		else if(aaa>986)printf("副省长(第7位次)");
		else if(aaa>984)printf("省级高级官员(第8位次)");
		else if(aaa>982)printf("省级各部门部长(第9位次)");
		else if(aaa>980)printf("人民代表大会普通成员(第10位次)");
		else if(aaa>978)printf("市长(第11位次)");
		else if(aaa>976)printf("副市长(第12位次)");
		else if(aaa>974)printf("国家高级军官(第13位次)");
		else if(aaa>972)printf("国家队运动员(第14位次)");
		else if(aaa>970)printf("其它国家一级运动员(第15位次)");
		else if(aaa>968)printf("高级科学研究员(第16位次)");
		else if(aaa>966)printf("国家级教育学家，哲学家等思想先驱(第17位次)");
		else if(aaa>964)printf("国家级经济学家(第18位次)");
		else if(aaa>962)printf("外交官(第19位次)");
		else if(aaa>960)printf("国家级社会学家(第20位次)");
		else if(aaa>958)printf("知名钢琴家，艺术家(第21位次)");
		else if(aaa>968)printf("国家级医学家(第22位次)");
		else if(aaa>950)printf("其他国家级领域专家(第23位次)");
		else if(aaa>946)printf("城市版图设计人员(第24位次)");
		else if(aaa>940)printf("100强公司大boss(第25位次)");
		else if(aaa>900){
			printf("至尊级职业(第1等级)\n");
			if(aaa>936)printf("电脑核心芯片设开发者");
			else if(aaa>932)printf("高新科技(经济)发展区负责人"); 
			else if(aaa>928)printf("央视主持人");
			else if(aaa>924)printf("国家机密项目参与人员(无领导地位)");
			else if(aaa>920)printf("市级教育局局长");
			else if(aaa>916)printf("能源管理机关领导");
			else if(aaa>912)printf("市级公安局局长");
			else if(aaa>908)printf("市级自然灾害防护局工作人员");
			else if(aaa>904)printf("国家二级运动员");
			else printf("国际政治及文化活动相关筹备人员"); 
		}
		else if(aaa>840){
			printf("圣级职业(第2等级)\n");
			if(aaa>895)printf("股市大佬");
			else if(aaa>890)printf("区长");
			else if(aaa>885)printf("市级翻译专家");
			else if(aaa>880)printf("药物开发人员");
			else if(aaa>875)printf("市级建筑设计员");
			else if(aaa>870)printf("国家银行行长");
			else if(aaa>865)printf("市级气象学家");
			else if(aaa>860)printf("音乐指挥家");
			else if(aaa>855)printf("天文观测员");
			else if(aaa>850)printf("宇航员");
			else if(aaa>845)printf("三甲级医院院长");
			else printf("城管领导");
		}
		else if(aaa>760){
			printf("神级职业(第3等级)\n");
			if(aaa>835)printf("程序员");
			else if(aaa>830)printf("医生");
			else if(aaa>825)printf("IT工程师");
			else if(aaa>820)printf("知名网红");
			else if(aaa>815)printf("药剂师");
			else if(aaa>810)printf("秘书");
			else if(aaa>805)printf("中级军官");
			else if(aaa>800)printf("飞行员");
			else if(aaa>795)printf("试飞员");
			else if(aaa>790)printf("演员");
			else if(aaa>785)printf("普通大学校长(非985或211)");
			else if(aaa>780)printf("救援队人员"); 
			else if(aaa>775)printf("潜水艇参与成员");
			else if(aaa>770)printf("航空母舰工作人员");
			else if(aaa>765)printf("市级以下法官");
			else printf("刑警"); 
		}
		else if(aaa>660){
			printf("高级职业(第4等级)\n");
			if(aaa>755)printf("冒险家");
			else if(aaa>750)printf("极限运动者");
			else if(aaa>745)printf("幼儿园园长"); 
			else if(aaa>740)printf("大学讲师");
			else if(aaa>735)printf("中小学老师");
			else if(aaa>730)printf("管家");
			else if(aaa>725)printf("私家车司机");
			else if(aaa>720)printf("招生办成员");
			else if(aaa>715)printf("财务人员");
			else if(aaa>710)printf("地形勘测人员");
			else if(aaa>705)printf("大学辅导员");
			else if(aaa>700)printf("护士");
			else if(aaa>695)printf("摄影师");
			else if(aaa>690)printf("城管");
			else if(aaa>685)printf("气象观测员");
			else if(aaa>680)printf("建筑工程师");
			else if(aaa>675)printf("建模工程师");
			else if(aaa>670)printf("游戏开发者");
			else printf("重要机床制作人员");
		}
		else if(aaa>520){
			printf("中级职业(第5等级)\n");
			if(aaa>655)printf("大学助教");
			else if(aaa>650)printf("幼儿园老师");
			else if(aaa>645)printf("会计");
			else if(aaa>640)printf("销售");
			else if(aaa>635)printf("机构老师");
			else if(aaa>630)printf("中介");
			else if(aaa>625)printf("导游");
			else if(aaa>620)printf("厨师");
			else if(aaa>615)printf("救生员");
			else if(aaa>610)printf("客服人员");
			else if(aaa>605)printf("酒店前台");
			else if(aaa>600)printf("档案记录员");
			else if(aaa>590)printf("植物护理员");
			else if(aaa>580)printf("一般博主");
			else if(aaa>570)printf("地铁司机");
			else if(aaa>560)printf("公交司机");
			else if(aaa>550)printf("俱乐部教练");
			else if(aaa>540)printf("煤气抄表员");
			else if(aaa>530)printf("水费抄表员");
			else printf("作业代写员(高尚的职业)"); 
		}
		else if(aaa>340){
			printf("普通职业(第6等级)\n");
			if(aaa>510)printf("售货员");
			else if(aaa>500)printf("餐厅服务员");
			else if(aaa>490)printf("物业");
			else if(aaa>480)printf("大巴车司机");
			else if(aaa>470)printf("KTV服务生");
			else if(aaa>460)printf("黑社会老大");
			else if(aaa>450)printf("景区售票员");
			else if(aaa>440)printf("景区工作人员");
			else if(aaa>430)printf("迎宾人员");
			else if(aaa>420)printf("商场店员");
			else if(aaa>410)printf("吹唢呐的");
			else if(aaa>400)printf("公厕所长");
			else if(aaa>390)printf("保安");
			else if(aaa>380)printf("富豪的小喽啰");
			else if(aaa>370)printf("打鼓的");
			else if(aaa>360)printf("完美犯罪杀人犯");
			else if(aaa>350)printf("完美犯罪抢劫犯");
			else printf("记账员");
		}
		else if(aaa>200){
			printf("低级职业(第7等级)\n");
			if(aaa>330)printf("开拖拉机的");
			else if(aaa>320)printf("快递员");
			else if(aaa>310)printf("油漆工");
			else if(aaa>300)printf("木工");
			else if(aaa>290)printf("铁匠");
			else if(aaa>280)printf("菜市场摊主");
			else if(aaa>270)printf("农夫");
			else if(aaa>260)printf("屠夫");
			else if(aaa>250)printf("水管工");
			else if(aaa>240)printf("海盗");
			else if(aaa>230)printf("黑社会小喽啰");
			else if(aaa>220)printf("保洁");
			else if(aaa>210)printf("垃圾站工作人员");
			else printf("卖艺人");
			} 
		else if(aaa>80){
			printf("底层职业(第8等级)\n");
			if(aaa>185)printf("植树先疯");
			else if(aaa>170)printf("擦鞋工");
			else if(aaa>155)printf("捡垃圾的(而且还是那种捡完以后还要嗅几下的那种)");
			else if(aaa>140)printf("掏粪工");
			else if(aaa>125)printf("抠脚大汉(啥也不干，除了抠脚就摆烂)");
			else if(aaa>110)printf("绿茶(专干这行)");
			else if(aaa>95)printf("碰瓷的死夹子");
			else printf("重达1000近的宅男(如果你现在是女的话可能是成了变性人)"); 
		} 
		else{
			printf("垃圾职业(第9等级)\n");
			if(aaa>60)printf("乞丐");
			else if(aaa>40)printf("小白脸");
			else if(aaa>20)printf("死舔狗");
			else printf("死变态(打扮成异性做直播)");
		}
	}
	if(a==5){
		printf("\n个人档案：\n\n基础信息：\n");
		printf("年龄：%d岁\n",(rand()%s.size())*(rand()%10)+1);
		printf("身高：%dcm\n",rand()%100+100);
		if(rand()%2==1){
			printf("性别：男\n");
			printf("体重：%dkg\n",rand()%70+35);
		}
		else{
			printf("性别：女\n");
			printf("体重：%dkg\n",rand()%55+30); 
		}
		printf("智商：%d\n",rand()%150+50);
		int jcxx=rand()%25+1;
		printf("你的基础信息的评分为%d分(满分25)\n",jcxx);
		printf("成绩查询：\n");
		int yw=rand()%41+rand()%51;
		printf("语文：%d\n",yw);
		int sx=rand()%41+rand()%61;
		printf("数学：%d\n",sx);
		int yy=rand()%51+rand()%51;
		printf("英语：%d\n",yy);
		int ls=rand()%51+rand()%51;
		printf("历史：%d\n",ls);
		int dl=rand()%51+rand()%51;
		printf("地理：%d\n",dl);
		int yye=rand()%61+rand()%36;
		printf("音乐：%d\n",yye);
		int ty=rand()%51+rand()%46;
		printf("体育：%d\n",ty);
		int cjcx=(ty+yye+dl+ls+yw+sx+yy)/28;
		printf("你的成绩查询的评分为：%d分(满分25)",cjcx);
		printf("\nCP查询：\n");
		int cpcx,cp=0; 
		if(n==15)printf("TA的CP是中一3班5号");
		else if(n==19)printf("TA的CP是中一3班1号");
		else if(n==37|n==14|n==22)printf("TA的CP是中一3班3号");
		else if(n==27)printf("TA的CP是中一6班陈可");
		else if(n==31)printf("TA没有CP，不像别人那样早恋");
		else if(n==34)printf("TA的CP是李玥怡，每个月都要互发情书");
		else if(n==5)printf("TA的CP是中一3班15号");
		else if(n==1)printf("TA的CP是中一3班19号");
		else if(n==3)printf("TA的CP是中一3班37号，14号，22号");
		else{
			cp=1;
			if(n<=13){
				int l;
				l=rand()%13;
				if(l>6)printf("TA的CP是中一3班");
				else if(l==0)printf("TA还是只没人要的单身狗");
				else printf("TA的CP是中一%d班",l); 
				if(l!=0)printf("%d号",rand()%31+15);
			}
			if(n>13){
				int ll;
				ll=rand()%13;
				if(ll>6)printf("TA的CP是中一3班");
				else if(ll==0)printf("TA还是只没人要的单身狗");
				else printf("TA的CP是中一%d班",ll); 
				if(ll!=0)printf("%d号",rand()%12+1);
			}
		}
			if(cp)cpcx=rand()%25+1;
			else cpcx=rand()%11+15;
			printf("\n你的cp查询的评分为：%d分(满分25)",cpcx);
			printf("\n未来职业查询：\n");
			int wlzycx=0; 
			int aaa=abs(rand()%1001-rand()%1001);
		if(aaa>998)printf("国家总统(第1位次)");
		else if(aaa>996)printf("国家总理(第2位次)");
		else if(aaa>994)printf("国家高级官员(第3位次)");
		else if(aaa>992)printf("国家各部门总部长(第4位次)");
		else if(aaa>990)printf("国家科学院院士(第5位次)");
		else if(aaa>988)printf("省长(第6位次)");
		else if(aaa>986)printf("副省长(第7位次)");
		else if(aaa>984)printf("省级高级官员(第8位次)");
		else if(aaa>982)printf("省级各部门部长(第9位次)");
		else if(aaa>980)printf("人民代表大会普通成员(第10位次)");
		else if(aaa>978)printf("市长(第11位次)");
		else if(aaa>976)printf("副市长(第12位次)");
		else if(aaa>974)printf("国家高级军官(第13位次)");
		else if(aaa>972)printf("国家队运动员(第14位次)");
		else if(aaa>970)printf("其它国家一级运动员(第15位次)");
		else if(aaa>968)printf("高级科学研究员(第16位次)");
		else if(aaa>966)printf("国家级教育学家，哲学家等思想先驱(第17位次)");
		else if(aaa>964)printf("国家级经济学家(第18位次)");
		else if(aaa>962)printf("外交官(第19位次)");
		else if(aaa>960)printf("国家级社会学家(第20位次)");
		else if(aaa>958)printf("知名钢琴家，艺术家(第21位次)");
		else if(aaa>968)printf("国家级医学家(第22位次)");
		else if(aaa>950)printf("其他国家级领域专家(第23位次)");
		else if(aaa>946)printf("城市版图设计人员(第24位次)");
		else if(aaa>940)printf("100强公司大boss(第25位次)");
		else if(aaa>900){
			printf("至尊级职业(第1等级)\n");
			wlzycx=rand()%3+20;
			if(aaa>936)printf("电脑核心芯片设开发者");
			else if(aaa>932)printf("高新科技(经济)发展区负责人"); 
			else if(aaa>928)printf("央视主持人");
			else if(aaa>924)printf("国家机密项目参与人员(无领导地位)");
			else if(aaa>920)printf("市级教育局局长");
			else if(aaa>916)printf("能源管理机关领导");
			else if(aaa>912)printf("市级公安局局长");
			else if(aaa>908)printf("市级自然灾害防护局工作人员");
			else if(aaa>904)printf("国家二级运动员");
			else printf("国际政治及文化活动相关筹备人员"); 
		}
		else if(aaa>840){
			printf("圣级职业(第2等级)\n");
				wlzycx=rand()%3+18;
				if(aaa>895)printf("股市大佬");
			else if(aaa>890)printf("区长");
			else if(aaa>885)printf("市级翻译专家");
			else if(aaa>880)printf("药物开发人员");
			else if(aaa>875)printf("市级建筑设计员");
			else if(aaa>870)printf("国家银行行长");
			else if(aaa>865)printf("市级气象学家");
			else if(aaa>860)printf("音乐指挥家");
			else if(aaa>855)printf("天文观测员");
			else if(aaa>850)printf("宇航员");
			else if(aaa>845)printf("三甲级医院院长");
			else printf("城管领导");
		}
		else if(aaa>760){
			printf("神级职业(第3等级)\n");
				wlzycx=rand()%3+16;
				if(aaa>835)printf("程序员");
			else if(aaa>830)printf("医生");
			else if(aaa>825)printf("IT工程师");
			else if(aaa>820)printf("知名网红");
			else if(aaa>815)printf("药剂师");
			else if(aaa>810)printf("秘书");
			else if(aaa>805)printf("中级军官");
			else if(aaa>800)printf("飞行员");
			else if(aaa>795)printf("试飞员");
			else if(aaa>790)printf("演员");
			else if(aaa>785)printf("普通大学校长(非985或211)");
			else if(aaa>780)printf("救援队人员"); 
			else if(aaa>775)printf("潜水艇参与成员");
			else if(aaa>770)printf("航空母舰工作人员");
			else if(aaa>765)printf("市级以下法官");
			else printf("刑警"); 
		}
		else if(aaa>660){
			printf("高级职业(第4等级)\n");
				wlzycx=rand()%3+14;
				if(aaa>755)printf("冒险家");
			else if(aaa>750)printf("极限运动者");
			else if(aaa>745)printf("幼儿园园长"); 
			else if(aaa>740)printf("大学讲师");
			else if(aaa>735)printf("中小学老师");
			else if(aaa>730)printf("管家");
			else if(aaa>725)printf("私家车司机");
			else if(aaa>720)printf("招生办成员");
			else if(aaa>715)printf("财务人员");
			else if(aaa>710)printf("地形勘测人员");
			else if(aaa>705)printf("大学辅导员");
			else if(aaa>700)printf("护士");
			else if(aaa>695)printf("摄影师");
			else if(aaa>690)printf("城管");
			else if(aaa>685)printf("气象观测员");
			else if(aaa>680)printf("建筑工程师");
			else if(aaa>675)printf("建模工程师");
			else if(aaa>670)printf("游戏开发者");
			else printf("重要机床制作人员");
		}
		else if(aaa>520){
			printf("中级职业(第5等级)\n");
				wlzycx=rand()%3+12;
				if(aaa>655)printf("大学助教");
			else if(aaa>650)printf("幼儿园老师");
			else if(aaa>645)printf("会计");
			else if(aaa>640)printf("销售");
			else if(aaa>635)printf("机构老师");
			else if(aaa>630)printf("中介");
			else if(aaa>625)printf("导游");
			else if(aaa>620)printf("厨师");
			else if(aaa>615)printf("救生员");
			else if(aaa>610)printf("客服人员");
			else if(aaa>605)printf("酒店前台");
			else if(aaa>600)printf("档案记录员");
			else if(aaa>590)printf("植物护理员");
			else if(aaa>580)printf("一般博主");
			else if(aaa>570)printf("地铁司机");
			else if(aaa>560)printf("公交司机");
			else if(aaa>550)printf("俱乐部教练");
			else if(aaa>540)printf("煤气抄表员");
			else if(aaa>530)printf("水费抄表员");
			else printf("作业代写员(高尚的职业)"); 
		}
		else if(aaa>340){
			printf("普通职业(第6等级)\n");
				wlzycx=rand()%3+10;
				if(aaa>510)printf("售货员");
			else if(aaa>500)printf("餐厅服务员");
			else if(aaa>490)printf("物业");
			else if(aaa>480)printf("大巴车司机");
			else if(aaa>470)printf("KTV服务生");
			else if(aaa>460)printf("黑社会老大");
			else if(aaa>450)printf("景区售票员");
			else if(aaa>440)printf("景区工作人员");
			else if(aaa>430)printf("迎宾人员");
			else if(aaa>420)printf("商场店员");
			else if(aaa>410)printf("吹唢呐的");
			else if(aaa>400)printf("公厕所长");
			else if(aaa>390)printf("保安");
			else if(aaa>380)printf("富豪的小喽啰");
			else if(aaa>370)printf("打鼓的");
			else if(aaa>360)printf("完美犯罪杀人犯");
			else if(aaa>350)printf("完美犯罪抢劫犯");
			else printf("记账员");
		}
		else if(aaa>200){
			printf("低级职业(第7等级)\n");
				wlzycx=rand()%4+7;
				if(aaa>330)printf("开拖拉机的");
			else if(aaa>320)printf("快递员");
			else if(aaa>310)printf("油漆工");
			else if(aaa>300)printf("木工");
			else if(aaa>290)printf("铁匠");
			else if(aaa>280)printf("菜市场摊主");
			else if(aaa>270)printf("农夫");
			else if(aaa>260)printf("屠夫");
			else if(aaa>250)printf("水管工");
			else if(aaa>240)printf("海盗");
			else if(aaa>230)printf("黑社会小喽啰");
			else if(aaa>220)printf("保洁");
			else if(aaa>210)printf("垃圾站工作人员");
			else printf("卖艺人");
			} 
		else if(aaa>80){
			printf("底层职业(第8等级)\n");
				wlzycx=rand()%4+4;
				if(aaa>185)printf("植树先疯");
			else if(aaa>170)printf("擦鞋工");
			else if(aaa>155)printf("捡垃圾的(而且还是那种捡完以后还要嗅几下的那种)");
			else if(aaa>140)printf("掏粪工");
			else if(aaa>125)printf("抠脚大汉(啥也不干，除了抠脚就摆烂)");
			else if(aaa>110)printf("绿茶(专干这行)");
			else if(aaa>95)printf("碰瓷的死夹子");
			else printf("重达1000近的宅男(如果你现在是女的话可能是成了变性人)"); 
		} 
		else{
			printf("垃圾职业(第9等级)\n");
				wlzycx=rand()%4+1;
				if(aaa>60)printf("乞丐");
			else if(aaa>40)printf("小白脸");
			else if(aaa>20)printf("死舔狗");
			else printf("死变态(打扮成异性做直播)");
		}
			if(wlzycx==0)wlzycx=rand()%4+22;
			printf("\n你的未来职业查询的评分为：%d分(满分25)\n\n\n",wlzycx);
			printf("你的个人档案总评分为：%d分(满分100)",cjcx+jcxx+cpcx+wlzycx);
			printf("\n你的评分星级为：%d星(25星满星)\n档案打印完毕",(cjcx+jcxx+cpcx+wlzycx-1)/4+1);
	}
return 0;
}