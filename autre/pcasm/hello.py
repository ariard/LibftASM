import os

if __name__ == '__main__':
    a = 0
    b = 100000
    strhello = ("Hello World\n").encode("utf-8")
    end = ("\n").encode("utf-8")
    while a < b:
        os.write(1, strhello)
        a += 1
