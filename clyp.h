#ifndef CLYP_SDK_CPP_CLYP_H
#define CLYP_SDK_CPP_CLYP_H

#endif //CLYP_SDK_CPP_CLYP_H

#include <string>

struct upload_args {
    std::string file_path;
    std::string title;
    std::string description; // optional

    // audioFileId, title, url
    void (*success)(std::string, std::string, std::string);

    // human readable error message
    void (*error)(std::string);

    // int between 0 and 100
    void (*progress)(int);
};

void *upload(void *arguments);
