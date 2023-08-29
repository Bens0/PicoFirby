#include <stdio.h>
#include <stdlib.h>
#include "lib/curl/curl.h"

#define PROJECT_NAME "PicoFurby"


int main() {
  CURL *curl;
  CURLcode res;
  curl_global_init(CURL_GLOBAL_ALL);
  CURL *curl_easy_init();
  if(curl) {
    CURLcode res;
    // Set the API endpoint
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/chat/completions");
    // Set the API key  
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "Authorization: Bearer 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");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    // Set the request data (input prompt and parameters)
    const char *data = "{\"prompt\": \"Once upon a time\", \"max_tokens\": 50}";
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    // Perform the request
    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

    curl_easy_cleanup(curl);
}
curl_global_cleanup();
return 0;
}
