#include <bits/stdc++.h>
#define endl    '\n'
#define _       << ' ' <<
#define LLINF   0x3f3f3f3f3f3f3f3fll
#define INF     0x3f3f3f3f
#define MOD     1000000009
#define Ft      first
#define Sd      second
#define Eb      emplace_back
#define All(v)  v.begin(), v.end()
using namespace std;
using lli = long long int;
using pii = pair<int, int>;

__attribute__((constructor)) void _IO(){
    //ios::sync_with_stdio(false); cin.tie(0); 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

namespace IO{
    const int size = 1 << 16;
    //////*    Input    *//////
    inline char gechar(){
        static char __in[size], *__p = __in, *__e = __in;
        static int counts = INF;
        if(__p == __e ){
            if(counts < size)
                return EOF;
            counts = fread(__in, 1, size, stdin);
            __p = __in;
            __e = __in + counts;
        }
        return *__p++;
    }
    inline void read(char &ch){ ch = gechar(); while(ch <= 32)ch = gechar(); }
    inline void read(char *s){
        char ch = gechar(); while(ch <= 32)ch = gechar();
        while(ch > 32){ *s++ = ch, ch = gechar(); } *s = '\0';
    }
    template<class Tp>
    bool read(Tp &x){
        x = 0; char ch = gechar(); bool sign = false;
        while(ch < 48 || ch > 57){
            if(ch == EOF)
                return false;
            sign |= (ch == '-'), ch = gechar();
        }
        while(ch >= 48 && ch <= 57)
            x = (x << 3) + (x << 1) + ch - 48, ch = gechar();
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

template<class Tp> void debug(Tp x){ cerr _ x; }
template<class Tp, class ...Args> void debug(Tp x, Args ...args){ debug(x), debug(args...); }

//////*    My Code begins here    *//////
