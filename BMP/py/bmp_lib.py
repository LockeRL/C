import ctypes

lib = ctypes.CDLL("./lib/bmp.so")

# 1 - grey
# 2 - sobel
# 3 - laplas
# 4 - gauss
# 5 - border
# 6 - user_core
# 7 - median
#
# int process_img(char *file_name_src, char *file_name_dst, int command, double *core_arr, int n, int m)

_process = lib.process_img
_process.argtypes = (ctypes.c_char_p, ctypes.c_char_p, ctypes.c_int,
                     ctypes.POINTER(ctypes.c_float), ctypes.c_int, ctypes.c_int)
_process.restype = ctypes.c_int


def process(file_src, file_dst, command, arr, n, m):
    if arr is None:
        src = None
    else:
        src = (ctypes.c_float * (n * m))(*arr)
    return _process(file_src.encode('ascii'), file_dst.encode('ascii'), command, src, n, m)

# 0 1 0 1 -4 1 0 1 0


