#include <iostream>
#include "clyp.h"

using namespace std;

int x = 0;

void progress(int total) {
    x = total;
    cout << "Progress: " << x << "%" << endl;
}

void success(string audioFileId, string title, string url) {
    cout << "Finished uploading. AudioFileId: " << audioFileId << endl;
}

void error(string errorMessage) {
    cout << "Failed to upload. Error: " << errorMessage << endl;
}

int main() {
    progress(x);
    cout << "" << endl;

    struct upload_args args;
    args.file_path = "audio.mp4";
    args.title = "Test";
    args.description = "Describing!";

    args.success = success;
    args.error = error;
    args.progress = progress;

    pthread_t thread;

    if (pthread_create(&thread, NULL, &upload, (void *)&args) != 0) {
        printf("Failed to create thread!\n");
        return -1;
    }

    cout << "Parent waiting to exit!" << endl;
    int code = pthread_join(thread, NULL);
    cout << "X = " << x << endl;

    return code;
}
