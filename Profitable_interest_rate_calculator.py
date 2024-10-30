def deposit(a,b):
    if a>b:
        return a
    else:
        x=b-a
        if a>x:
            a=a-x
            b=b-(2*x)
            if b==a:
                return a
            else:
                return 0
        else:
            return 0

t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    print(deposit(a,b))
