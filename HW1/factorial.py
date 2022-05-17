def factorial_for(n):
    ret = 1
    for i in range(1, n+1):
        ret *= i
    return ret

n = int(input())
print(factorial_for(n))

