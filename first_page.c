#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("%s%c%c\n",
  "Content-Type:text/html;charset=iso-8859-1",13,10);
	printf("<title>Secure storage</title>");
	printf("<style>#form {border: 2p; border-radius:10px; margin-left:10px; width:200px; height:30px;} #button1{width:90px; height:50px; border-radius:10px; margin-left:150px; margin-top:90px;} #button2{width:90px; height:50px; border-radius:10px; margin-left:80px; margin-top:90px;}</style>");
	printf("<body>");
	printf("<div style = \"width:1340px; height:607px; background-color:#222930;border-width:2px; border-style: solid; border-color:#000000;\">");
	printf("<div style=\"width:1340px; height:100px; background-color:#116466;\">");
	printf("<div style=\"width:450px; height:450px; background-color:#116466;\"></div>");
	printf("<div style=\"width:550px; height:355px; background-color:#4EB1BA; float:left; margin-top:-340px; margin-left:400px;border-width:1px; border-style: solid; border-color:#000000;\">");
	printf("<p style=\"margin-left:10px; font-size:20px;\">Username :  </p><form method=\"get\" action=\"http://localhost/minor/register_page.exe\"><input type=\"text\" name=\"username\" id=\"form\">");
	printf("<p style=\"margin-left:10px; font-size:20px;\">Password :  </p><input type=\"password\" name=\"password\" id=\"form\">");
	printf("<br><input type=\"submit\" name=\"submit\" value=\"Login\" id=\"button1\" formaction=\"http://localhost/cgi-bin/login.exe\">");
	printf("<input type=\"submit\" name=\"submit\" value=\"Register\" id=\"button2\" formaction=\"http://localhost/minor/register_page.exe\">");
	printf("</form>");
	printf("</div>");
	printf("</div>");
	printf("</div>");
	printf("</div>");	
	return 0;
}
