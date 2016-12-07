#include "clyp.h"
#include <iostream>

using namespace std;

void *upload(void *arguments) {
    struct upload_args *args = (struct upload_args*) arguments;

    cout << "File Path: " + (args->file_path) << endl;
    cout << "Title: " + (args->title) << endl;
    cout << "Description: " + (args->description) << endl;

    int x;
    for (x = 0; x <= 100; x++) {
        args->progress(x);
    }

    args->success("testID", "", "");
}