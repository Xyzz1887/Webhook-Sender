#include <iostream>
#include <string>
#include <thread>
#include <curl/curl.h>
#include "config.hpp"

void spammer(int timer, std::string wurl) {
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl){

        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_URL, wurl.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, cfg::jsonmsg.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        std::cout << "[+]Started!\n";
        while(1){
            res = curl_easy_perform(curl);
            std::this_thread::sleep_for(std::chrono::seconds(cfg::sleeptimer));
        }

    }
}


int main(){
    std::string wURL;
    std::cout << "[>]Webhook URL > ";
std::cin >> wURL;
spammer(cfg::sleeptimer, wURL);
}