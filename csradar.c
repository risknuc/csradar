#include <stddef.h>

#include "webview/webview.h"

#ifdef _WIN32
#   include <windows.h>
#endif

#define r_webview_title "csradar"

#define r_window_width 720u
#define r_window_height 440u

#ifdef _WIN32
    int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine,
        int nCmdShow) { (void)hInst; (void)hPrevInst; (void)lpCmdLine; (void)nCmdShow;
#else
int main(void) {
#endif
    webview_t webview_instance = webview_create(0, NULL);
    webview_set_title(webview_instance, r_webview_title);
    webview_set_size(webview_instance, r_window_width, r_window_height, WEBVIEW_HINT_NONE);

    webview_navigate(webview_instance, "http://localhost:5173/");

    #ifdef _WIN32
        HWND hwnd = (HWND)webview_get_window(webview_instance);
        if (hwnd) SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
    #endif

    webview_run(webview_instance);
    webview_destroy(webview_instance);

    return 0;
}
