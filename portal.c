#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("%s%c%c\n",
  "Content-Type:text/html;charset=iso-8859-1",13,10);
	printf("<title>Secure storage</title>");
	printf("<style>#form {border: 2p; border-radius:10px; margin-left:10px; width:200px; height:30px;} #button1{width:90px; height:50px; border-radius:10px; margin-left:150px; margin-top:90px;} #button2{width:90px; height:50px; border-radius:10px; margin-left:100px; margin-top:180px;}</style>");
	printf("<body>");
	printf("<div style = \"width:1340px; height:607px; background-color:#222930;border-width:2px; border-style: solid; border-color:#000000;\">");
	printf("<div style=\"width:1340px; height:100px; background-color:#116466;\">");
	printf("</div>");
	printf("<div style=\"width:300px; height:400px; margin-left:20px; background-color:#ffffff ; opacity:0.5; border-width:2px; border-style: solid;\">");
	printf("<h3 align=\"center\"> Demand for storage </h3>");
	printf("<p style=\"margin-left:10px; font-size:20px;\">Size :  </p><form method=\"get\" id=\"usrform\" action=\"http://localhost/cgi-bin/demand.exe\"><input type=\"text\" name=\"size\" id=\"form\">");
	printf("<button id = \"button2\">Submit</button></form>");
	printf("</div>");
	printf("<div style=\"width:300px; height:400px; margin-left:360px; margin-top:-405px; background-color:#ffffff ;opacity:0.5; border-width:2px; border-style: solid; float:left\">");
	printf("<h3 align=\"center\"> Upload a file </h3>");
	printf("<p style=\"margin-left:10px; font-size:20px;\">Filename :  </p><form method=\"get\" action=\"http://localhost/cgi-bin/file_upload.exe\"><input type=\"text\" name=\"filename\" id=\"form\">");
	printf("<p style=\"margin-left:10px; font-size:20px;\">Content :  </p><input type=\"text\" placeholder=\"Enter Content Here.....\" name=\"content\" id=\"form\">");
	printf("<button  style=\" width:90px; height:50px; border-radius:10px; margin-left:100px; margin-top:53px;\">Submit</button></form>");
	printf("</div>");
	//work on this div to display the folder
	printf("<div style=\"width:300px; height:400px; margin-left:690px; margin-top:-405px; background-color:#ffffff ;opacity:0.5; border-width:2px; border-style: solid; float:left\">");
	printf("<h3 align=\"center\"> Register </h3>");
	printf("<p style=\"margin-left:10px; font-size:20px;\">Username  </p><form method=\"get\" action=\"http://localhost/cgi-bin/reg.exe\"><input type=\"text\" name=\"filename\" id=\"form\">");
	printf("<p style=\"margin-left:10px; font-size:20px;\">IP :  </p><input type=\"text\" name=\"content\" id=\"form\">");
	printf("<button  style=\" width:90px; height:50px; border-radius:10px; margin-left:100px; margin-top:53px;\">Submit</button></form>");
	
	printf("</div>");
	//end div
	printf("<div style=\"width:300px; height:400px; margin-left:1020px; margin-top:-405px; background-color:#ffffff ;opacity:0.5; border-width:2px; border-style: solid; float:left\">");
	printf("<h3 align=\"center\"> Extend storage </h3>");
	printf("<p style=\"margin-left:10px; font-size:20px;\">Size :  </p><form method=\"get\" id=\"usrform\" action=\"http://localhost/cgi-bin/extend.exe\"><input type=\"text\" name=\"size_extend\" id=\"form\"></form>");
	printf("<form method=\"get\" id=\"usrform\" action=\"http://localhost/cgi-bin/access.exe\">");
	printf("<button id = \"button2\">Submit</button></form>");
	printf("<button>Access</button></form>");
	printf("</div>");
	
	printf("</div>");
	return 0;
}
	
