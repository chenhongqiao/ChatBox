/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2020 Harrychen <harrychen0314@gmail.com>
 * 
 * ChatBox is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * ChatBox is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
void readmessage2(char name[64],char openname[64])
{
	int gettext1;
	char messagename1[1000][64];
	char to1[1000][64];
	char text1[5000][200];
	char end[]="\0";
	FILE *file;
	printf("刷新\n");
	if((file = fopen("messagedata.dat","r")) == NULL){
			printf("505 Notfound ErrorCode:721\n");
	}else{
		for(gettext1=0;gettext1<=10000;gettext1++){
			fscanf(file,"%s",messagename1[gettext1]);
			//printf("messagename1 %s ",messagename1[gettext1]);
			fscanf(file,"%s",to1[gettext1]);
			//printf("to1 %s\n",to1[gettext1]);
			fscanf(file,"%s",text1[gettext1]);
			if (strcmp(to1[gettext1], name) == 0 && strcmp(messagename1[gettext1], openname) == 0 || strcmp(to1[gettext1], openname) == 0 && strcmp(messagename1[gettext1], name) == 0){
				printf("%s",messagename1[gettext1]);
				printf("%s\n",text1[gettext1]);
			}
			if(strcmp(to1[gettext1],end) == 0){
				printf("读取信息完毕\n");
				break;
			}	
		}
		fclose(file);
	}
}
void public2()
{
	int gettext1;
	char messagename1[1000][64];
	char text1[1000][200];
	char end[]="\0";
	FILE *file;
	printf("刷新\n");
	if((file = fopen("public.dat","r")) == NULL){
			printf("505 Notfound ErrorCode:722\n");
	}else{
		for(gettext1=0;gettext1<=10000;gettext1++){
			fscanf(file,"%s",messagename1[gettext1]);
			//printf("messagename1 %s ",messagename1[gettext1]);
			//printf("to1 %s\n",to1[gettext1]);
			fscanf(file,"%s",text1[gettext1]);
			if(strcmp(text1[gettext1],end) == 0){
				printf("读取信息完毕\n");
				break;
			}	
			printf("%s",messagename1[gettext1]);
			printf("%s\n",text1[gettext1]);
			
		}
		fclose(file);
	}
}
void cleandata(char name[64])
{
	char text[1000][200];
	char allname[500][64];
	int signup=0; //判断是否要写入昵称
	char nolook[1000][64]; //这条日记不让谁看
	char dairyname[1000][64];
	int chose=0;
	int go;
	int gettext;
	int ok;
	char code[500][64];
	char code1[64];
	int in;
	int dowhich=0;
	int dowhat=0;
	int deleted[1500];
	char end[]="\0";
	time_t	t; 
	FILE *file;
	FILE *user;

	struct tm  *local;
	
	if((file = fopen("journal.dat","r")) == NULL){
			printf("505 Notfound ErrorCode:601\n");
		}
	else{	
		for(gettext=0;gettext<=1500;gettext++){
			ok=0;
			fscanf(file,"%s",nolook[gettext]);
			fscanf(file,"%s",dairyname[gettext]);
			fscanf(file,"%s",text[gettext]);
			if(strcmp(text[gettext], end) == 0){
				printf("——没有更多日志——\n");
				go=gettext;
				break;
			}
				printf("%s",dairyname[gettext]);
				printf("%s ",text[gettext]);
				printf("编号%d\n",gettext);
		}
			do{
				printf("请选择要管理的日志（输入）编号 1703-保存并退出 1704-不保存并退出");
				scanf("%d",&dowhich);
				if(dowhich==1703){
					go=1;
					break;
				}else if(dowhich==1704){
					go=2;
					break;
				}
				printf("请选择要干什么 1-更改该日志 2-删除该日志 3-放弃更改并退出");
				scanf("%d",&dowhat);
				if(dowhat==1){
					printf("更改成什么？");
					scanf("%s",text[dowhich]);
				}else if(dowhat==2){
					deleted[dowhich] = 1;
				}else if(dowhat==3){
					break;
				}
			}while(1);
			fclose(file);
	}
	if(go==1){
		if((file = fopen("journal.dat","w")) == NULL){
				printf("505 Notfound ErrorCode:602\n");
			}
		else{	
			for(gettext=0;gettext<go;gettext++){
				time(&t);
				local = localtime(&t);
				if(deleted[gettext]!=1){
					fprintf(file,"%s ",nolook[gettext]);
					fprintf(file,"%s ",dairyname[gettext]);
					fprintf(file,"%s ",text[gettext]);
					fprintf(file,"7\n");
					printf("更改成功，更改后界面：\n");
		       			printf("%s",dairyname[gettext]);
					printf("%s ",text[gettext]);
					printf("编号%d\n",gettext);
				}
			}
				fclose(file);
		}
	}
}

void writemessage(char name[64])
{
	char text[200];
	char to[64]; 
	int gettext;
	int ok;
	int code[500];
	int code1;
	int in;
	time_t	t; 
	FILE *file;
	FILE *user;

	struct tm  *local;
	
	time(&t);
	local = localtime(&t);
	
	printf("发给：");
	scanf("%s",to);
	printf("内容(200字以内)");
	scanf("%s",text);
	

		if((file = fopen("messagedata.dat","a+")) == NULL){
			printf("505 Notfound ErrorCode:701\n");
		}
		else{	
			
			fprintf(file,"%s ",name );
			fprintf(file,"%s ",to );			
			fprintf(file,"%d年%d月%d日%d时%d分%d秒",local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);		
			fprintf(file,"“%s”\n",text);
			printf("已成功给%s发送邮件\n",to);
			fclose(file);
		}
}

void readmessage(char name[64])
{
	char text[1000][200];
	char text1[1000][200];
	char text2[200];
	char allname[1000][64];
	char to[1000][64]; 
	char to1[1000][64]; 
	char messagename[1000][64];
	char messagename1[1000][64];
	char username[1000][64];
	char openname[64];
	char exit[64]="//fullexit";
	char end[]="\0";
	int chose=0;
	int go=0;
	int gettext=0;
	int gettext1=0;
	int ok=0;
	int go2=0;
	int code[500];
	int code1=0;
	int in=0;
	int sure=0;
	char new[]="//new";
	char ref[]="//refresh";
	time_t	t; 
	FILE *file;
	FILE *user;
	struct tm  *local;
	
	
	if((file = fopen("messagedata.dat","r")) == NULL){
		printf("505 Notfound ErrorCode:702\n");
	}
	else{	
		for(gettext=0;gettext<=1000;gettext++){
			ok=0;
			fscanf(file,"%s",messagename[gettext]);
			fscanf(file,"%s",to[gettext]);
			fscanf(file,"%s",text[gettext]);
			if(strcmp(to[gettext1], end) == 0){
				printf("读取信息完毕\n");
				break;
			}
		}
		
		fclose(file);
	}
	ok=0;
	for(go=0;go<=100;go++){
		if(strcmp(to[go], name) == 0){
		sure=0;
			for(in=0;in<=1000;in++){
				
				if(*username[in]=='\0' && *messagename[go]=='\0'){
					break;
				}
				if(strcmp(username[in], messagename[go]) == 0){
					ok++;
					
					sure=2;
					break;
				}				
				
			}
			if(sure==0){
				ok++;
				stpcpy(username[ok], messagename[go]);
				gettext1=gettext;
			}	
		}
	}	
	for(go=0;go<=gettext;go++){
		go2++;			
		for(gettext1=gettext;gettext1>=0;gettext1--){
			
			if(strcmp(name, to[gettext1-1])==0 && strcmp(messagename[gettext1-1], username[go2])==0){
			printf("===============================================\n");
			printf("%s\n%s\n",username[go2],text[gettext1-1]);
			break;
			}
		}
	}		
	printf("===============================================\n");
	printf("请选择想要打开的聊天框(//new新建聊天)");
	scanf("%s",openname);
	if(strcmp(openname, new) == 0){
		writemessage(name);
	}else{
		for(gettext=0;gettext<=10000;gettext++){
	
			
				if (strcmp(to[gettext], name) == 0 && strcmp(messagename[gettext], openname) == 0 || strcmp(to[gettext], openname) == 0 && strcmp(messagename[gettext], name) == 0){
					printf("%s\n",messagename[gettext]);
					printf("%s\n",text[gettext]);
				}
		}
		for(gettext=0;gettext<=1000;gettext++){	
			if((file = fopen("messagedata.dat","rb+")) == NULL){
				printf("505 Notfound ErrorCode:712\n");
			}
			else{	
					printf("快捷回复给%s",openname);
					scanf("%s" ,text2);
					if(strcmp(text2, exit) == 0){
						break;
					}if(strcmp(text2, ref) == 0){
						readmessage2(name,openname);
					}else if(strcmp(text2, exit) != 0){
						fseek(file, 0L,SEEK_END);
						time(&t);
						local = localtime(&t);
						fprintf(file,"%s ",name );
						fprintf(file,"%s ",openname );			
						fprintf(file,"%d年%d月%d日%d时%d分%d秒",local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);		
						fprintf(file,"“%s”\n",text2);
						fseek(file, 0L, SEEK_SET);
						for(gettext1=0;gettext1<=10000;gettext1++){
							fscanf(file,"%s",messagename1[gettext1]);
							//printf("messagename1 %s ",messagename1[gettext1]);
							fscanf(file,"%s",to1[gettext1]);
							//printf("to1 %s\n",to1[gettext1]);
							if(strcmp(to1[gettext1], end) == 0){
								printf("读取信息完毕\n");
								break;
							}	
							fscanf(file,"%s",text1[gettext1]);
							if (strcmp(to1[gettext1], name) == 0 && strcmp(messagename1[gettext1], openname) == 0 || strcmp(to1[gettext1], openname) == 0 && strcmp(messagename1[gettext1], name) == 0){
								printf("%s",messagename1[gettext1]);
								printf("%s\n",text1[gettext1]);
							}
							
						}
					}
				fclose(file);
			}	
		}
	}
	
}
	
void writedairy(char name[64])
{
	char text[100][200];
	char allname[500][64];
	int signup=0; //判断是否要写入昵称
	char nolook[1000][64]; //这条日记不让谁看
	char dairyname[100][64];
	int chose=0;
	int go; 
	int gettext;
	int ok;
	int code[500];
	int code1;
	int in;
	char username[1000][64];
	char end[]="//over";
	time_t	t; 
	FILE *file;
	FILE *user;
	struct tm  *local;
	
	time(&t);
	local = localtime(&t);
	
	printf("您想要写什么？(200字以内)");
	scanf("%s",text);
	

		if((file = fopen("journal.dat","a+")) == NULL){
			printf("505 Notfound ErrorCode:703\n");
		}
		else{	
			printf("是否设置不让谁看？1-是 2-不是");
			scanf("%d",&chose);
		if(chose==1){
			for(go=0;go<=1000;go++){
				printf("不让谁看？(//over输入完成)");
				scanf("%s",nolook[go]);
				if(strcmp(nolook[go], end) == 0){
					break;
				}else{
					fprintf(file,"%s",nolook[go]);
				}
			}
			fprintf(file," ");
		}else if(chose==2){
			fprintf(file,"nobody ");
		}
			
			fprintf(file,"%s 在%d年%d月%d日%d时%d分%d秒时说",name,local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);		
			fprintf(file,"“%s”\n",text);
			printf("写日志成功\n");
			fclose(file);
			}
}

void readdairy(char name[64])
{
	char text[100][200];
	int go2;
	char allname[500][64];
	int signup=0; //判断是否要写入昵称
	char nolook[100][64]; //这条日记不让谁看
	char dairyname[100][64];
	int readname;
	int chose=0;
	int go;
	int gettext;
	int ok;
	int code[500];
	int code1;
	int in;
	char end[]="\0";
	char new[]="//new";
	char *p;
	time_t	t; 
	FILE *file;
	FILE *user;
	struct tm  *local;
	
	/*工程代码
	if((file = fopen("messagedata.dat","r")) == NULL){
			printf("505 Notfound ErrorCode:702\n");
	}
	else{	
		for(gettext=0;gettext<=10000;gettext++){
			ok=0;
			fscanf(file,"%s",nolook[gettext]);
			fscanf(file,"%s",dairyname[gettext]);
			fscanf(file,"%s",text[gettext]);
			if(strcmp(to[gettext1], end) == 0){
				printf("读取信息完毕\n");
				break;
			}
		}
		
		fclose(file);
	}
	
	for(go=0;go<=10000;go++){
		if(strcmp(nolook[go], name) != 0){
		sure=0;
			for(in=0;in<=10000;in++){
				
				if(*username[in]=='\0' && dairyname[go]=='\0'){
					break;
				}
				if(strcmp(username[in], dairy[go]) == 0){
					
					sure=2;
					break;
				}				
				
			}
			if(sure==0){
				ok++;
				stpcpy(username[ok], dairy[go]);
			}	
		}
	}	
	for(go=0;go<=gettext;go++){
		go2++;			
		for(gettext1=gettext;gettext1>=0;gettext1--){
			
			if(strcmp(name, nolook[gettext1-1])!=0 && strcmp(diaryname[gettext1-1], username[go2])==0){
			printf("===============================================\n");
			printf("%s\n%s\n",username[go2],text[gettext1-1]);
			break;
			}
		}
	}		
	printf("===============================================\n");
	*/
	printf("1-时间线 2-写日志");
	scanf("%d",&readname);
	
	if(readname==2){
		writedairy(name);
	}else{
		if((file = fopen("journal.dat","r")) == NULL){
				printf("505 Notfound ErrorCode:704\n");
		}
		else{	
			for(gettext=0;gettext<=1500;gettext++){
				ok=0;
				fscanf(file,"%s",nolook[gettext]);
				fscanf(file,"%s",dairyname[gettext]);
				fscanf(file,"%s",text[gettext]);
				if(strcmp(text[gettext], end) == 0){
					printf("——没有更多日志——\n");
					break;
				}
				p=strstr(nolook[gettext],name);
				if (p){

				}else{
					printf("%s",dairyname[gettext]);
					printf("%s\n",text[gettext]);
				}
			
			}
	
			fclose(file);
		}

	}
}
void public(char name[64])
{
	char text[10000][200];
	char text1[10000][200];
	char text2[200];
	char allname[10000][64];
	char to[10000][64]; 
	char to1[10000][64]; 
	char messagename[10000][64];
	char messagename1[10000][64];
	char username[10000][64];
	char openname[64];
	char exit[64]="//fullexit";
	char end[]="\0";
	int chose=0;
	int go=0;
	int gettext=0;
	int gettext1=0;
	int ok=0;
	int go2=0;
	int code[500];
	int code1=0;
	int in=0;
	int sure=0;
	char new[]="//new";
	char ref[]="//refresh";
	time_t	t; 
	FILE *file;
	FILE *user;
	struct tm  *local;
	
	time(&t);
	local = localtime(&t);
	for(gettext=0;gettext<=100000000;gettext++){	
		if((file = fopen("public.dat","rb+")) == NULL){
			printf("505 Notfound ErrorCode:712\n");
		}
		else{	
			printf("发送消息");
			scanf("%s" ,text2);
			if(strcmp(text2, exit) == 0){
				break;
			}if(strcmp(text2, ref) == 0){
				public2();
			}else if(strcmp(text2, exit) != 0){
				fseek(file, 0L,SEEK_END);
				time(&t);
				local = localtime(&t);
				fprintf(file,"%s ",name );		
				fprintf(file,"%d年%d月%d日%d时%d分%d秒",local->tm_year + 1900, local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);		
				fprintf(file,"“%s”\n",text2);
				fseek(file, 0L, SEEK_SET);
				for(gettext1=0;gettext1<=100000;gettext1++){
					fscanf(file,"%s",messagename1[gettext1]);
					fscanf(file,"%s",text1[gettext1]);
					if(strcmp(text1[gettext1], end) == 0){
						printf("读取信息完毕\n");
						break;
					}	
					printf("%s\n",messagename1[gettext1]);
					printf("%s\n",text1[gettext1]);
					
				}
			}
			fclose(file);
		}	
		
	}
}
void userdata()
{
	char name[1000][64];
	int gettext;
	char end[]="\0";
	FILE *file;
	
	if((file = fopen("userdata.dat","r")) == NULL){
				printf("505 Notfound ErrorCode:731\n");
		}
		else{	
			for(gettext=0;gettext<=1500;gettext++){
				fscanf(file,"%s",name[gettext]);
				if(strcmp(name[gettext], end) == 0){
					printf("——没有更多用户——\n");
					break;
				}

				printf("%s\n",name[gettext]);
			
			}
	
			fclose(file);
		}
}
int main(void){

	char allname[500][64];
	char name[64];
	char name1[64];
	int signup=0; 
	int chose=0;
	int go;
	int ok;
	char code[500][64];
	char code1[64];
	int in;
	char admin[] = "admin";
	int connect=0;
	int connect2=0;;
	time_t	t; 
	FILE *file;
	FILE *user;
	struct tm  *local;
	
	time(&t);
	local = localtime(&t);
	if((user = fopen("userdata.dat","r")) == NULL){
		printf("服务器连接异常，请确认连接后重试");
	}
	else{
		for(go=0;go<=1500;go++){
			ok=0;
			fscanf(user,"%d",&ok);
			fscanf(user,"%s",allname[go]);
			fscanf(user,"%s",&code[go]);

			if(ok!=6){
				break;
			}
			
		}
		fclose(user);
	}
	if((user = fopen("connect.dat","r")) == NULL){
		printf("服务器连接异常，请确认连接后重试");
		connect=1;
	}
	else{
		
	}
	if(connect!=1){
		printf("欢迎\n");
		do{
		in=2;
		printf("1-登陆 2-注册");
		scanf("%d",&signup);
		if(signup==1){
			printf("账号：");
			scanf("%s",name1);
			printf("密码：");
			scanf("%s",code1);
			for(go=0;go<=500;go++){
				if (strcmp(allname[go], name1) == 0 && strcmp(code[go], code1) == 0){
						stpcpy(name, name1);
						printf("登陆成功，欢迎你%s\n",name);
						in=0;
						break;
					}
				if(go==500){
					printf("登录失败请重试\n");
					break;
				}
			
			}
		}
	
		else if(signup==2){
			printf("首次使用，请注册\n");
			printf("昵称：");
			scanf("%s",name);
			printf("密码:");
			scanf("%s",code1);
			for(go=0;go<=500;go++){
				if (strcmp(allname[go], name) == 0){
						printf("昵称已被其他用户占用，请重试\n");
						break;
					}
				if(go==500){
					in=0;
					break;
				}
			
			}
			if(in==0){
			if((user = fopen("userdata.dat","a+")) == NULL){
			printf("无法读取\n");
			}
			else{
				fprintf(user,"6 ");			
				fprintf(user,"%s ",name);
				fprintf(user,"%s\n",code1);
				fclose(user);
				printf("注册成功\n");
				in=0;
			}
			}
		}	
		}while(in==2);
		if(strcmp(name, admin) == 0){
			printf("admin，您已成功登陆管理员账号。\n");
			do{
			printf("日志-1 信息-2 大厅-3 数据管理-4 用户管理-5");
			scanf("%d",&chose);
			if(chose==1){
				readdairy(name);
			}else if(chose==2){
				readmessage(name);
			}else if(chose==3){
				public(name);
			}else if(chose==4){
				cleandata(name);
			}else if(chose==5){
				printf("开发中");
			}
			}while(1);
		}else{
			do{
			printf("日志-1 信息-2 大厅-3 用户列表-4");
			scanf("%d",&chose);
			if(chose==1){
				readdairy(name);
			}else if(chose==2){
				readmessage(name);
			}else if(chose==3){
				public(name);
			}else if(chose==4){
				userdata();
			}
			}while(1);
		}
	}
	return(0);
}
