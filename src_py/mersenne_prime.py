import time

triple = 0
# 1 << 60 까지만 출력함. 61부터는 왜 안될까?
N = (1 << 61) - 1
print("N = " + str(N))

start = time.time()

if N & 1 and (N == 3 or N % 3):
    i = 3
    while i**2 <= N:
        if triple == 0:
            triple = -3
            continue

        if N % i == 0:
            print("N is not a prime number. It can be divided by " + str(i) + ".")
            break

        i += 2
        triple += 1

    if i**2 > N:
        print("N is a prime number.")

else:
    print("N is not a prime number.")

print(" (" + str(time.time() - start) + " seconds)")