#include <iostream>
#include <string>
#include <thread>
#include <curl/curl.h>
#include "config.hpp"
CURL* curl;
CURLcode res;
void sendwh() {
    
    if(curl){
            res = curl_easy_perform(curl);
            std::cout << "Sent";

    }
}
void curlinit(std::string wurl){
 
    curl = curl_easy_init();
     struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_URL, wurl.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, cfg::jsonmsg.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        sendwh();
}



int main(){
    std::string wURL;
    std::cout << "[>]Webhook URL > ";
std::cin >> wURL;
curlinit(wURL);
}