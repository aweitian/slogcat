#include <stdio.h>
#include <unistd.h>
#include <android/log.h>
#include <string.h>

#define LOG_TAG    "Garri"
// #define EXIT_SECRET "@RUR'URU'U'R'#13864#RUUR'U'RU'R'@"
#define LOG(...)  __android_log_print(__VA_ARGS__)


void usage() {
//     单个字符a         表示选项a没有参数            格式：-a即可，不加参数
// 单字符加冒号b:     表示选项b有且必须加参数      格式：-b 100或-b100,但-b=100错
// 单字符加2冒号c::   表示选项c可以有，也可以无     格式：-c200，其它格式错误
    fprintf(stderr,
            "usage: \n"
            "   slogcat [-d] [-e] [-i] [-w] [-v] [-t tag] msg\n"
            "   slogcat -tGarri \"test msg\"\n"
            "   slogcat -e -tGarri \"error msg\"\n"
    );
}

int main(int argc, char**argv)
{
    char tag[64];
    char buffer[1024];
    int o;
    int l = ANDROID_LOG_DEBUG;
    strcpy(tag,"Garri");
    const char *optstring = "deiwvt::"; //abc: 有三个选项-abc，其中c选项后有冒号，所以后面必须有参数
    while ((o = getopt(argc, argv, optstring)) != -1) {
        switch (o) {
            case 'd':
                l = ANDROID_LOG_DEBUG;
                break;
            case 'e':
                l=ANDROID_LOG_ERROR;
                break;
            case 'i':
                l=ANDROID_LOG_INFO;
                break;
            case 'w':
                l=ANDROID_LOG_WARN;
                break;
            case 'v':
                l = ANDROID_LOG_VERBOSE;
                break;
            case 't':
                strcpy(tag,optarg);
                break;
        }
    }
    LOG(l,tag,"%s",argv[optind]);
    return 0;
}    




