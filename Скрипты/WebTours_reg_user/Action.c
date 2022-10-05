Action()
	
{
	lr_start_transaction("UC_06_reg_user");

	
	lr_start_transaction("open_home_page");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Welcome to the Web Tours site",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("open_home_page", LR_AUTO);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_start_transaction("reg_user");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=First time registering",
		LAST);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("reg_user",LR_AUTO);

	lr_think_time(35);

	lr_start_transaction("user_data");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=If you have any questions",
		LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={userRandom}", ENDITEM, 
		"Name=password", "Value={passRandom}", ENDITEM, 
		"Name=passwordConfirm", "Value={passRandom}", ENDITEM, 
		"Name=firstName", "Value={userRandom}", ENDITEM, 
		"Name=lastName", "Value={passRandom}", ENDITEM, 
		"Name=address1", "Value=123", ENDITEM, 
		"Name=address2", "Value=123", ENDITEM, 
		"Name=register.x", "Value=43", ENDITEM, 
		"Name=register.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("user_data",LR_AUTO);

	lr_think_time(31);

	lr_start_transaction("reg_finish");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Web Tours reservation pages",
		LAST);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("reg_finish",LR_AUTO);

	lr_think_time(23);

	lr_start_transaction("sign_off");
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Welcome to the Web",
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("sign_off",LR_AUTO);
	
	lr_end_transaction("UC_06_reg_user", LR_AUTO);


	return 0;
}