ostream &operator<<(ostream &os, const BI &n) {
    if (n > 9) os << (n / 10);
    return os << (int)(n % 10);
}