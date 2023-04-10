import ctypes

lib = ctypes.CDLL("./lib/task.so")

# void fib(int *a, int n)
_fib = lib.fib
_fib.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fib.restype = ctypes.c_int


def fib(n):
    nums = []
    if n < 0:
        return []
    src = (ctypes.c_int * n)(*nums)
    _fib(src, n)
    return src


#int make_uniq(int *dst, const int *src, int n);
_make_uniq = lib.make_uniq
_make_uniq.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_make_uniq.restype = ctypes.c_int


def make_uniq_match(src):
    n = len(src)
    dst = []
    src_a = (ctypes.c_int * n)(*src)
    new_n = _make_uniq(None, src_a, n)
    dst_a = (ctypes.c_int * new_n)(*dst)
    _make_uniq(dst_a, src_a, n)
    return dst_a


def make_uniq_reserve(src):
    n = len(src)
    dst = []
    src_a = (ctypes.c_int * n)(*src)
    dst_a = (ctypes.c_int * n)(*dst)
    _make_uniq(dst_a, src_a, n)
    return dst_a