#pragma comment(lib, "libcurl.lib")
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "MinMax.h"
#include <curl/curl.h>

int main(void) {
    CURL* req = curl_easy_init();
    CURLcode res;
    char poststring[200];// , nam[100], prj[100];
    struct min_max data = maxmin();
    printf("Min and max \n");
   /* printf("Welcome to libcurl app\n");
    printf("your name");
    scanf("%s", nam);
    printf("project:");
    scanf("%s", prj);*/
    sprintf(poststring, "max=%d&min=%d", data.max, data.min);
    //poststring = "Iris is DDDDDumb";
    printf("max = %d min = %d \n", data.max, data.min);
    
    if (req) {
        curl_easy_setopt(req, CURLOPT_URL, "http://www.cc.puv.fi/~e2301484/echo.php");
        //curl_easy_setopt(req, CURLOPT_URL, "http://www.cc.puv.fi/~2301449/echo.php");//2301449
        curl_easy_setopt(req, CURLOPT_POSTFIELDS, poststring);
        res = curl_easy_perform(req);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed : %s\n",
                curl_easy_strerror(res));
        }
    }
    curl_easy_cleanup(req);
    return 0;
}
