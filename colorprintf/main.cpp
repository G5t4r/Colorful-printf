//
//  main.cpp
//  colorprintf
//
//  Created by BlueCocoa on 14-4-26.
//  Copyright (c) 2014年 BlueCocoa. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>

#define grayFont 1
#define redFont 2
#define greenFont 3
#define yellowFont 4
#define blueFont 5
#define purperFont 6
#define skyblueFont 7
#define whiteFont 8
#define nonFont 0xFFFF

#define grayBackground 1
#define redBackground 2
#define greenBackground 3
#define yellowBackground 4
#define blueBackground 5
#define purperBackground 6
#define skyblueBackground 7
#define whiteBackground 8
#define nonBackground 0xFFFF

#define highlightTextYES 1
#define highlightTextNO 0

static inline int printf(int fontColor, int backgroundColor,const char * __restrict fmt ,...);
static inline int printf(int fontColor, int backgroundColor,bool hightlight,bool underline,bool blink,const char * __restrict fmt ,...);

static int printf(int fontColor, int backgroundColor,const char * __restrict fmt,...){
    int ret;
    switch (fontColor) {
        case 1:
            printf("\033[30m");
            break;
        case 2:
            printf("\033[31m");
            break;
        case 3:
            printf("\033[32m");
            break;
        case 4:
            printf("\033[33m");
            break;
        case 5:
            printf("\033[34m");
            break;
        case 6:
            printf("\033[35m");
            break;
        case 7:
            printf("\033[36m");
            break;
        case 8:
            printf("\033[37m");
            break;
        default:
            break;
    }
    switch (backgroundColor) {
        case 1:
            printf("\033[40m");
            break;
        case 2:
            printf("\033[41m");
            break;
        case 3:
            printf("\033[42m");
            break;
        case 4:
            printf("\033[43m");
            break;
        case 5:
            printf("\033[44m");
            break;
        case 6:
            printf("\033[45m");
            break;
        case 7:
            printf("\033[46m");
            break;
        case 8:
            printf("\033[47m");
            break;
        default:
            break;
    }
	va_list ap;
	va_start(ap, fmt);
	ret = vfprintf(stdout, fmt, ap);
	va_end(ap);
    printf("\033[0m");
	return (ret);
}

static inline int printf(int fontColor, int backgroundColor,bool hightlight,bool underline,bool blink,const char * __restrict fmt ,...){
    int ret;
    if (hightlight == 1) {
        printf("\033[1m");
    }
    if (blink == 1) {
        printf("\033[5m");
    }
    if (underline == 1) {
        printf("\033[4m");
    }
    switch (fontColor) {
        case 1:
            printf("\033[30m");
            break;
        case 2:
            printf("\033[31m");
            break;
        case 3:
            printf("\033[32m");
            break;
        case 4:
            printf("\033[33m");
            break;
        case 5:
            printf("\033[34m");
            break;
        case 6:
            printf("\033[35m");
            break;
        case 7:
            printf("\033[36m");
            break;
        case 8:
            printf("\033[37m");
            break;
        default:
            break;
    }
    switch (backgroundColor) {
        case 1:
            printf("\033[40m");
            break;
        case 2:
            printf("\033[41m");
            break;
        case 3:
            printf("\033[42m");
            break;
        case 4:
            printf("\033[43m");
            break;
        case 5:
            printf("\033[44m");
            break;
        case 6:
            printf("\033[45m");
            break;
        case 7:
            printf("\033[46m");
            break;
        case 8:
            printf("\033[47m");
            break;
        default:
            break;
    }
	va_list ap;
	va_start(ap, fmt);
	ret = vfprintf(stdout, fmt, ap);
	va_end(ap);
    printf("\033[0m");
	return (ret);
}

int main(int argc, const char * argv[])
{
    printf(blueFont, nonBackground, true, true, true, "I'm Colorful and blinking with underline and highlight.\n");
    return 0;
}

