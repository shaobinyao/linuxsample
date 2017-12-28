/*************************************************************************
	> File Name: log.c
	> Author: yaoshaobin 
	> Mail: 
	> Created Time: 2017-12-28 08:30
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <syslog.h>
#include <string.h>
#include <unistd.h>
#include "log.h"

void print_log(const char* pformat, ...)
{
	char szlog[1024] = {0};
	char buffer[1024] = {0};
	char file_name[100] = {0};
	time_t now;
	struct tm *local;

	va_list args;
	va_start(args, pformat);
	vsprintf(szlog, pformat, args);
	va_end(args);

    time(&now);
    local = localtime(&now);
    printf("%04d-%02d-%02d %02d:%02d:%02d %s\n", 
    		local->tm_year+1900, local->tm_mon + 1,  
            local->tm_mday, local->tm_hour, 
            local->tm_min, local->tm_sec,  
            szlog);

    sprintf(buffer,"%04d-%02d-%02d %02d:%02d:%02d %s\n", 
    				local->tm_year+1900, local->tm_mon + 1,  
                	local->tm_mday, local->tm_hour, 
                	local->tm_min, local->tm_sec,  
                	szlog);

    if (access("log", F_OK ) != 0)
        mkdir("log", 0755);

    sprintf(file_name, "./log/%04d-%02d-%02d %02d:%02d:%02d.log", 
    					local->tm_year+1900, local->tm_mon + 1,  
                		local->tm_mday, local->tm_hour, 
                		local->tm_min, local->tm_sec);

    FILE* file = fopen(file_name, "a+");
    fwrite(buffer,1,strlen(buffer),file);  
    fclose(file);  
}
