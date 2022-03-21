namespace IO{
    const int size = 1 << 16;
    //////*    Input    *//////
    char __in[size], *__p = __in, *__e = __in;
    inline char gechar(){
        return __p == __e && (__e = (__p = __in) + fread(__in, 1, size, stdin)) == __in ? EOF : *__p++;
    }
    inline void read(char &ch){ ch = gechar(); while(ch <= 32)ch = gechar(); }
    inline void read(char *s){
        char ch = gechar(); while(ch <= 32)ch = gechar();
        while(ch > 32){ *s++ = ch, ch = gechar(); } *s = '\0';
    }
    template<class Tp>
    bool read(Tp &x){
        static char ch; static bool sign;
        while(!isdigit(ch = gechar()) and ch != '-')
            if(ch == EOF)
                return false;
        sign = (ch == '-'), x = sign ? 0 : ch - 48;
        while(isdigit(ch = gechar()))
            x = (x << 3) + (x << 1) + ch - 48;
        x = sign ? ~x + 1 : x;
        return true;
    }
    template<class Tp, class ...Args> void read(Tp &x, Args &...args){ read(x), read(args...); }
    //////*    Output    *//////
    char __out[size], *__o = __out;
    inline void flush(){ fwrite(__out, 1, __o - __out, stdout); }
    inline void puchar(char ch){
        *__o++ = ch;
        if(__o - __out >= size){ flush(), __o = __out; }
    }
    inline void print(char ch){ puchar(ch); }
    inline void print(char *s){ while(*s != '\0')puchar(*s++); }
    inline void print(const char *s){ while(*s != '\0')puchar(*s++); }
    template<class Tp>
    void print(Tp x){
        if(x < 0){ puchar('-'), x = ~x + 1; }
        if(x > 9){ print(x / 10); } puchar(x % 10 + 48);
    }
    template<class Tp> inline void println(Tp x){ print(x), puchar(10); }
    template<class Tp, class ...Args> void print(Tp x, Args ...args){ print(x), print(args...); }
    class Flusher{
    public:
        ~Flusher(){ flush(); }
    }__Flusher;
}using namespace IO;
