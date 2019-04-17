namespace IO{//by laofu
    const int maxn((1 << 21) + 1);
    char ibuf[maxn], *iS, *iT, obuf[maxn], *oS = obuf, *oT = obuf + maxn - 1, c, st[55];
    int f, tp;
    char Getc() {
	return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, maxn, stdin), (iS == iT ? EOF : *iS++)) : *iS++);
    }
    void Flush() {
	fwrite(obuf, 1, oS - obuf, stdout);
	oS = obuf;
    }
    void Putc(char x) {
	*oS++ = x;
	if (oS == oT) Flush();
    }
    template <class Int> void Input(Int &x) {
	for (f = 1, c = Getc(); c < '0' || c > '9'; c = Getc()) f = c == '-' ? -1 : 1;
	for (x = 0; c <= '9' && c >= '0'; c = Getc()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
    }
    template <class Int> void Print(Int x) {
	if (!x) Putc('0');
	if (x < 0) Putc('-'), x = -x;
	while (x) st[++tp] = x % 10 + '0', x /= 10;
	while (tp) Putc(st[tp--]);
    }
    void Getstr(char *s, int &l) {
	for (c = Getc(); c < 'a' || c > 'z'; c = Getc());
	for (l = 0; c <= 'z' && c >= 'a'; c = Getc()) s[l++] = c;
	s[l] = 0;
    }
    void Putstr(const char *s) {
	for (int i = 0, n = strlen(s); i < n; ++i) Putc(s[i]);
    }
}
